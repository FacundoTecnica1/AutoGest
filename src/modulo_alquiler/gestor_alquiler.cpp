#include "gestor_alquiler.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

GestorAlquiler::GestorAlquiler(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorAlquiler::cargarListasCombo() {
    ui->cmbClienteAlquiler->clear();
    for (const auto& c : daoCliente.listar()) {
        ui->cmbClienteAlquiler->addItem(c.getNombre() + " " + c.getApellido(), c.getid_cliente());
    }

    ui->cmbAutoAlquiler->clear();
    for (const auto& a : daoAuto.listar()) {
        ui->cmbAutoAlquiler->addItem(a.getMarca() + " " + a.getModelo() + " - " + a.getPatente(), a.getid_auto());
    }
}

void GestorAlquiler::calcularTotal() {
    // Tomamos las fechas como string y el id desde la UI, el cálculo pesado lo hace el DAO
    QString inicio = ui->dteFechaInicioAlquiler->date().toString("yyyy-MM-dd");
    QString fin = ui->dteFechaFinAlquiler->date().toString("yyyy-MM-dd");
    int idAuto = ui->cmbAutoAlquiler->currentData().toInt();

    double total = daoAlquiler.calcularTotal(idAuto, inicio, fin);
    ui->lblTotalAlquiler->setText("$ " + QString::number(total, 'f', 2));
}

void GestorAlquiler::listar() {
    ui->tblAlquileres->clearContents();
    ui->tblAlquileres->setRowCount(0);
    ui->tblAlquileres->setColumnCount(8);
    ui->tblAlquileres->setHorizontalHeaderLabels({"ID", "Auto", "Cliente", "Metodo Pago", "Inicio", "Fin", "Total", "Estado"});
    ui->tblAlquileres->setColumnHidden(0, true);

    // Le pedimos al DAO la lista ya armada y formateada usando listar()
    auto lista = daoAlquiler.listar();
    int row = 0;

    for(const auto& fila : lista) {
        ui->tblAlquileres->insertRow(row);
        ui->tblAlquileres->setItem(row, 0, new QTableWidgetItem(fila[0]));
        ui->tblAlquileres->setItem(row, 1, new QTableWidgetItem(fila[1]));
        ui->tblAlquileres->setItem(row, 2, new QTableWidgetItem(fila[2]));
        ui->tblAlquileres->setItem(row, 3, new QTableWidgetItem(fila[3]));
        ui->tblAlquileres->setItem(row, 4, new QTableWidgetItem(fila[4]));
        ui->tblAlquileres->setItem(row, 5, new QTableWidgetItem(fila[5]));
        ui->tblAlquileres->setItem(row, 6, new QTableWidgetItem("$" + fila[6]));
        ui->tblAlquileres->setItem(row, 7, new QTableWidgetItem(fila[7]));
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