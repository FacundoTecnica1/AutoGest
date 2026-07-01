#include "gestor_mantenimiento.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

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

void GestorMantenimiento::poblarTabla(const std::vector<std::vector<QString>>& lista) {
    ui->tblMantenimientos->clearContents();
    ui->tblMantenimientos->setRowCount(0);
    ui->tblMantenimientos->setColumnCount(7);
    ui->tblMantenimientos->setHorizontalHeaderLabels({"ID", "Auto", "Tipo", "Ingreso", "Salida", "Costo", "Estado"});
    ui->tblMantenimientos->setColumnHidden(0, true);

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

void GestorMantenimiento::listar() {
    poblarTabla(daoMantenimiento.listar());
}

void GestorMantenimiento::buscar(const QString &texto) {
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoMantenimiento.buscarCampo(texto));
    }
}

void GestorMantenimiento::cargarDatos() {
    int fila = ui->tblMantenimientos->currentRow();
    if (fila == -1) return;

    ui->cmbAutoMantenimiento->setCurrentText(ui->tblMantenimientos->item(fila, 1)->text());
    ui->cmbTipoMantenimiento->setCurrentText(ui->tblMantenimientos->item(fila, 2)->text());
    ui->dteFechaIngresoMantenimiento->setDate(QDate::fromString(ui->tblMantenimientos->item(fila, 3)->text(), "yyyy-MM-dd"));
    ui->dteFechaSalidaMantenimiento->setDate(QDate::fromString(ui->tblMantenimientos->item(fila, 4)->text(), "yyyy-MM-dd"));

    QString costo = ui->tblMantenimientos->item(fila, 5)->text().replace("$", "").trimmed();
    ui->txtCostoMantenimiento->setText(costo);

    QString estado = ui->tblMantenimientos->item(fila, 6)->text();
    if(!estado.isEmpty()) {
        estado[0] = estado[0].toUpper();
        ui->cmbEstadoMantenimiento->setCurrentText(estado);
    }
}

void GestorMantenimiento::limpiarFormulario() {
    ui->cmbAutoMantenimiento->setCurrentIndex(0);
    ui->cmbTipoMantenimiento->setCurrentIndex(0);
    ui->dteFechaIngresoMantenimiento->setDate(QDate::currentDate());
    ui->dteFechaSalidaMantenimiento->setDate(QDate::currentDate());
    ui->txtObservacionesMantenimiento->clear();
    ui->txtCostoMantenimiento->clear();
    ui->cmbEstadoMantenimiento->setCurrentIndex(0);
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
    limpiarFormulario();
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
    limpiarFormulario();
}

void GestorMantenimiento::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Mantenimiento obj;
    obj.setid_Mantenimiento(id);
    daoMantenimiento.eliminar(obj);
    listar();
    limpiarFormulario();
}