#include "gestor_mantenimiento.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

GestorMantenimiento::GestorMantenimiento(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorMantenimiento::cargarListasCombo() {
    ui->cmbAutoMantenimiento->clear();
    for (const auto& a : daoAuto.listar()) {
        ui->cmbAutoMantenimiento->addItem(a.getMarca() + " " + a.getModelo() + " - " + a.getPatente(), a.getid_auto());
    }

    ui->cmbTipoMantenimiento->clear();
    for (const auto& t : daoTipo.listar()) {
        ui->cmbTipoMantenimiento->addItem(t.getNombre(), t.getid_tipo_Mantenimiento());
    }
}

void GestorMantenimiento::listar() {
    ui->tblMantenimientos->clearContents();
    ui->tblMantenimientos->setRowCount(0);
    ui->tblMantenimientos->setColumnCount(7);
    ui->tblMantenimientos->setHorizontalHeaderLabels({"ID", "Auto", "Tipo", "Ingreso", "Salida", "Costo", "Estado"});
    ui->tblMantenimientos->setColumnHidden(0, true);

    // Le pedimos al DAO la lista usando listar()
    auto lista = daoMantenimiento.listar();
    int row = 0;
    for(const auto& fila : lista) {
        ui->tblMantenimientos->insertRow(row);
        ui->tblMantenimientos->setItem(row, 0, new QTableWidgetItem(fila[0]));
        ui->tblMantenimientos->setItem(row, 1, new QTableWidgetItem(fila[1]));
        ui->tblMantenimientos->setItem(row, 2, new QTableWidgetItem(fila[2]));
        ui->tblMantenimientos->setItem(row, 3, new QTableWidgetItem(fila[3]));
        ui->tblMantenimientos->setItem(row, 4, new QTableWidgetItem(fila[4]));
        ui->tblMantenimientos->setItem(row, 5, new QTableWidgetItem("$" + fila[5]));
        ui->tblMantenimientos->setItem(row, 6, new QTableWidgetItem(fila[6]));
        row++;
    }
}

int GestorMantenimiento::getIdSeleccionadoTabla() {
    int fila = ui->tblMantenimientos->currentRow();
    if (fila == -1) return -1;
    return ui->tblMantenimientos->item(fila, 0)->text().toInt();
}

void GestorMantenimiento::guardar() {
    Mantenimiento obj;
    obj.setid_auto(ui->cmbAutoMantenimiento->currentData().toInt());
    obj.setid_tipo_Mantenimiento(ui->cmbTipoMantenimiento->currentData().toInt());
    obj.setFechaIngreso(ui->dteFechaIngresoMantenimiento->date().toString("yyyy-MM-dd"));
    obj.setFechaSalida(ui->dteFechaSalidaMantenimiento->date().toString("yyyy-MM-dd"));
    obj.setObservaciones(ui->txtObservacionesMantenimiento->text());
    obj.setCosto(ui->txtCostoMantenimiento->text().toDouble());
    obj.setEstado(ui->cmbEstadoMantenimiento->currentText().toLower());

    daoMantenimiento.insertar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Mantenimiento guardado.");
}

void GestorMantenimiento::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    Mantenimiento obj;
    obj.setid_Mantenimiento(id);
    obj.setid_auto(ui->cmbAutoMantenimiento->currentData().toInt());
    obj.setid_tipo_Mantenimiento(ui->cmbTipoMantenimiento->currentData().toInt());
    obj.setFechaIngreso(ui->dteFechaIngresoMantenimiento->date().toString("yyyy-MM-dd"));
    obj.setFechaSalida(ui->dteFechaSalidaMantenimiento->date().toString("yyyy-MM-dd"));
    obj.setObservaciones(ui->txtObservacionesMantenimiento->text());
    obj.setCosto(ui->txtCostoMantenimiento->text().toDouble());
    obj.setEstado(ui->cmbEstadoMantenimiento->currentText().toLower());

    daoMantenimiento.actualizar(obj);
    listar();
}

void GestorMantenimiento::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Mantenimiento obj;
    obj.setid_Mantenimiento(id);
    daoMantenimiento.eliminar(obj);
    listar();
}