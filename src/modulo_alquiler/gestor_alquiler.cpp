#include "gestor_alquiler.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>

GestorAlquiler::GestorAlquiler(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorAlquiler::cargarListasCombo() {
    ui->cmbClienteAlquiler->clear();
    for (const auto& c : daoCliente.listar()) {
        //Guardamos el ID en el userData del combo para poder usarlo despues
        ui->cmbClienteAlquiler->addItem(c.getNombre() + " " + c.getApellido(), c.getid_cliente());
    }

    ui->cmbAutoAlquiler->clear();
    for (const auto& a : daoAuto.listar()) {
        ui->cmbAutoAlquiler->addItem(a.getMarca() + " " + a.getModelo() + " - " + a.getPatente(), a.getid_auto());
    }
}

void GestorAlquiler::calcularTotal() {
    QDate inicio = ui->dteFechaInicioAlquiler->date();
    QDate fin = ui->dteFechaFinAlquiler->date();

    //Calculamos dias
    int dias = inicio.daysTo(fin);
    if(dias <= 0) dias = 1; //Minimo cobramos 1 dia si es el mismo dia

    //Buscamos el precio del auto seleccionado
    int idAuto = ui->cmbAutoAlquiler->currentData().toInt();
    double precioDia = 0.0;

    for (const auto& a : daoAuto.listar()) {
        if (a.getid_auto() == idAuto) {
            precioDia = a.getPrecio_por_dia();
            break;
        }
    }

    double total = dias * precioDia;
    ui->lblTotalAlquiler->setText("$ " + QString::number(total, 'f', 2));
}

void GestorAlquiler::listar() {
    ui->tblAlquileres->clearContents();
    ui->tblAlquileres->setRowCount(0);
    //Columnas: ID, Auto, Cliente, Pago, Inicio, Fin, Total, Estado
    ui->tblAlquileres->setColumnCount(8);
    ui->tblAlquileres->setHorizontalHeaderLabels({"ID", "Auto", "Cliente", "Metodo Pago", "Inicio", "Fin", "Total", "Estado"});
    ui->tblAlquileres->setColumnHidden(0, true); //Ocultamos el ID

    QSqlQuery q;
    //Hacemos inner join para traer los datos reales de la bd
    q.prepare("SELECT alq.id_alquiler, a.marca, a.modelo, a.patente, c.nombre, c.apellido, "
              "alq.metodo_pago, alq.fecha_inicio, alq.fecha_fin, alq.precio_total, alq.estado "
              "FROM alquiler alq "
              "INNER JOIN auto a ON alq.id_auto = a.id_auto "
              "INNER JOIN cliente c ON alq.id_cliente = c.id_cliente");
    q.exec();

    int row = 0;
    while(q.next()) {
        ui->tblAlquileres->insertRow(row);

        QString idAlq = q.value(0).toString();
        QString infoAuto = q.value(1).toString() + " " + q.value(2).toString() + " (" + q.value(3).toString() + ")";
        QString infoCliente = q.value(4).toString() + " " + q.value(5).toString();

        ui->tblAlquileres->setItem(row, 0, new QTableWidgetItem(idAlq));
        ui->tblAlquileres->setItem(row, 1, new QTableWidgetItem(infoAuto));
        ui->tblAlquileres->setItem(row, 2, new QTableWidgetItem(infoCliente));
        ui->tblAlquileres->setItem(row, 3, new QTableWidgetItem(q.value(6).toString()));
        ui->tblAlquileres->setItem(row, 4, new QTableWidgetItem(q.value(7).toString()));
        ui->tblAlquileres->setItem(row, 5, new QTableWidgetItem(q.value(8).toString()));
        ui->tblAlquileres->setItem(row, 6, new QTableWidgetItem("$" + q.value(9).toString()));
        ui->tblAlquileres->setItem(row, 7, new QTableWidgetItem(q.value(10).toString()));
        row++;
    }
}

int GestorAlquiler::getIdSeleccionadoTabla() {
    int fila = ui->tblAlquileres->currentRow();
    if (fila == -1) return -1;
    return ui->tblAlquileres->item(fila, 0)->text().toInt();
}

void GestorAlquiler::guardar() {
    Alquiler obj;
    obj.setid_auto(ui->cmbAutoAlquiler->currentData().toInt());
    obj.setid_cliente(ui->cmbClienteAlquiler->currentData().toInt());
    obj.setMetodoPago(ui->cmbMetodoPagoAlquiler->currentText().toLower());
    obj.setFechaInicio(ui->dteFechaInicioAlquiler->date().toString("yyyy-MM-dd"));
    obj.setFechaFin(ui->dteFechaFinAlquiler->date().toString("yyyy-MM-dd"));

    //Sacamos el simbolo de pesos del total para guardar un double limpio
    QString totalStr = ui->lblTotalAlquiler->text().replace("$ ", "");
    obj.setPrecioTotal(totalStr.toDouble());

    obj.setEstado(ui->cmbEstadoAlquiler->currentText().toLower());

    daoAlquiler.insertar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Alquiler guardado.");
}

void GestorAlquiler::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) {
        QMessageBox::warning(ui->centralwidget, "Aviso", "Seleccioná un alquiler de la tabla.");
        return;
    }

    Alquiler obj;
    obj.setid_alquiler(id);
    obj.setid_auto(ui->cmbAutoAlquiler->currentData().toInt());
    obj.setid_cliente(ui->cmbClienteAlquiler->currentData().toInt());
    obj.setid_usuario(1);
    obj.setMetodoPago(ui->cmbMetodoPagoAlquiler->currentText().toLower());
    obj.setFechaInicio(ui->dteFechaInicioAlquiler->date().toString("yyyy-MM-dd"));
    obj.setFechaFin(ui->dteFechaFinAlquiler->date().toString("yyyy-MM-dd"));

    QString totalStr = ui->lblTotalAlquiler->text().replace("$ ", "");
    obj.setPrecioTotal(totalStr.toDouble());
    obj.setEstado(ui->cmbEstadoAlquiler->currentText().toLower());

    daoAlquiler.actualizar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Alquiler actualizado.");
}

void GestorAlquiler::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) {
        QMessageBox::warning(ui->centralwidget, "Aviso", "Seleccioná un alquiler de la tabla.");
        return;
    }
    Alquiler obj;
    obj.setid_alquiler(id);
    daoAlquiler.eliminar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Alquiler eliminado.");
}