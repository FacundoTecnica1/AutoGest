#include "gestor_mantenimiento.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>

GestorMantenimiento::GestorMantenimiento(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorMantenimiento::cargarListasCombo() {
    //Llenamos el combo box de autos
    ui->cmbAutoMantenimiento->clear();
    for (const auto& a : daoAuto.listar()) {
        ui->cmbAutoMantenimiento->addItem(a.getMarca() + " " + a.getModelo() + " - " + a.getPatente(), a.getid_auto());
    }

    //Asumo que tenes un combo para tipos de mantenimiento, si no, es un ID estandar
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

    QSqlQuery q;
    q.prepare("SELECT m.id_Mantenimiento, a.marca, a.modelo, a.patente, t.nombre, "
              "m.fecha_ingreso, m.fecha_salida, m.costo, m.estado "
              "FROM mantenimiento m "
              "INNER JOIN auto a ON m.id_auto = a.id_auto "
              "INNER JOIN tipo_mantenimiento t ON m.id_tipo_Mantenimiento = t.id_tipo_Mantenimiento");
    q.exec();

    int row = 0;
    while(q.next()) {
        ui->tblMantenimientos->insertRow(row);
        QString idMant = q.value(0).toString();
        QString infoAuto = q.value(1).toString() + " " + q.value(2).toString() + " (" + q.value(3).toString() + ")";

        ui->tblMantenimientos->setItem(row, 0, new QTableWidgetItem(idMant));
        ui->tblMantenimientos->setItem(row, 1, new QTableWidgetItem(infoAuto));
        ui->tblMantenimientos->setItem(row, 2, new QTableWidgetItem(q.value(4).toString()));
        ui->tblMantenimientos->setItem(row, 3, new QTableWidgetItem(q.value(5).toString()));
        ui->tblMantenimientos->setItem(row, 4, new QTableWidgetItem(q.value(6).toString()));
        ui->tblMantenimientos->setItem(row, 5, new QTableWidgetItem("$" + q.value(7).toString()));
        ui->tblMantenimientos->setItem(row, 6, new QTableWidgetItem(q.value(8).toString()));
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