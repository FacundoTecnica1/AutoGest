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
    QString inicio = ui->dteFechaInicioAlquiler->date().toString("yyyy-MM-dd");
    QString fin = ui->dteFechaFinAlquiler->date().toString("yyyy-MM-dd");
    int idAuto = ui->cmbAutoAlquiler->currentData().toInt();

    double total = daoAlquiler.calcularTotal(idAuto, inicio, fin);
    ui->lblTotalAlquiler->setText("$ " + QString::number(total, 'f', 2));
}

//usamos un vector de vectores de string porque asi lo armaste en tu dao para el join
void GestorAlquiler::poblarTabla(const std::vector<std::vector<QString>>& lista) {
    ui->tblAlquileres->clearContents();
    ui->tblAlquileres->setRowCount(0);
    ui->tblAlquileres->setColumnCount(8);
    ui->tblAlquileres->setHorizontalHeaderLabels({"ID", "Auto", "Cliente", "Metodo Pago", "Inicio", "Fin", "Total", "Estado"});
    ui->tblAlquileres->setColumnHidden(0, true);

    int row = 0;
    for(const auto& fila : lista) {
        ui->tblAlquileres->insertRow(row);
        ui->tblAlquileres->setItem(row, 0, new QTableWidgetItem(fila[0])); //ID
        ui->tblAlquileres->setItem(row, 1, new QTableWidgetItem(fila[1])); //Auto
        ui->tblAlquileres->setItem(row, 2, new QTableWidgetItem(fila[2])); //Cliente
        ui->tblAlquileres->setItem(row, 3, new QTableWidgetItem(fila[3])); //Metodo Pago
        ui->tblAlquileres->setItem(row, 4, new QTableWidgetItem(fila[4])); //Inicio
        ui->tblAlquileres->setItem(row, 5, new QTableWidgetItem(fila[5])); //Fin
        ui->tblAlquileres->setItem(row, 6, new QTableWidgetItem("$" + fila[6])); //Total
        ui->tblAlquileres->setItem(row, 7, new QTableWidgetItem(fila[7])); //Estado
        row++;
    }
}

void GestorAlquiler::listar() {
    poblarTabla(daoAlquiler.listar());
}

void GestorAlquiler::buscar(const QString &texto) {
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoAlquiler.buscarCampo(texto));
    }
}

void GestorAlquiler::cargarDatos() {
    int fila = ui->tblAlquileres->currentRow();
    if (fila == -1) return;

    //seteamos el combobox buscando el texto exacto que aparece en la tabla
    ui->cmbAutoAlquiler->setCurrentText(ui->tblAlquileres->item(fila, 1)->text());
    ui->cmbClienteAlquiler->setCurrentText(ui->tblAlquileres->item(fila, 2)->text());

    //capitalizamos la primera letra para que coincida con el combobox si viene en minuscula
    QString metodo = ui->tblAlquileres->item(fila, 3)->text();
    if(!metodo.isEmpty()) {
        metodo[0] = metodo[0].toUpper();
        ui->cmbMetodoPagoAlquiler->setCurrentText(metodo);
    }

    ui->dteFechaInicioAlquiler->setDate(QDate::fromString(ui->tblAlquileres->item(fila, 4)->text(), "yyyy-MM-dd"));
    ui->dteFechaFinAlquiler->setDate(QDate::fromString(ui->tblAlquileres->item(fila, 5)->text(), "yyyy-MM-dd"));

    //le sacamos el signo peso para guardar el numero limpio
    QString total = ui->tblAlquileres->item(fila, 6)->text().replace("$", "").trimmed();
    ui->lblTotalAlquiler->setText("$ " + total);

    QString estado = ui->tblAlquileres->item(fila, 7)->text();
    if(!estado.isEmpty()) {
        estado[0] = estado[0].toUpper();
        ui->cmbEstadoAlquiler->setCurrentText(estado);
    }
}

void GestorAlquiler::limpiarFormulario() {
    ui->cmbAutoAlquiler->setCurrentIndex(0);
    ui->cmbClienteAlquiler->setCurrentIndex(0);
    ui->cmbMetodoPagoAlquiler->setCurrentIndex(0);
    ui->cmbEstadoAlquiler->setCurrentIndex(0);
    ui->dteFechaInicioAlquiler->setDate(QDate::currentDate());
    ui->dteFechaFinAlquiler->setDate(QDate::currentDate());
    ui->lblTotalAlquiler->setText("$ 0.00");
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
    obj.setid_usuario(1);
    obj.setMetodoPago(ui->cmbMetodoPagoAlquiler->currentText().toLower());
    obj.setFechaInicio(ui->dteFechaInicioAlquiler->date().toString("yyyy-MM-dd"));
    obj.setFechaFin(ui->dteFechaFinAlquiler->date().toString("yyyy-MM-dd"));

    QString totalStr = ui->lblTotalAlquiler->text().replace("$ ", "");
    obj.setPrecioTotal(totalStr.toDouble());

    obj.setEstado(ui->cmbEstadoAlquiler->currentText().toLower());

    daoAlquiler.insertar(obj);
    listar();
    limpiarFormulario();
    QMessageBox::information(ui->centralwidget, "Éxito", "Alquiler guardado.");
}

void GestorAlquiler::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

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
    limpiarFormulario();
}

void GestorAlquiler::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Alquiler obj;
    obj.setid_alquiler(id);
    daoAlquiler.eliminar(obj);
    listar();
    limpiarFormulario();
}