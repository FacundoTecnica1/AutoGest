#include "gestor_auto.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

GestorAuto::GestorAuto(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorAuto::listar() {
    ui->tblAutos->clearContents();
    ui->tblAutos->setRowCount(0);
    ui->tblAutos->setColumnCount(9);
    ui->tblAutos->setHorizontalHeaderLabels({"ID", "Marca", "Modelo", "Patente", "Año", "Color", "Km", "Precio/Dia", "Estado"});
    ui->tblAutos->setColumnHidden(0, true);

    auto lista = daoAuto.listar();
    int row = 0;
    for(const auto& a : lista) {
        ui->tblAutos->insertRow(row);
        ui->tblAutos->setItem(row, 0, new QTableWidgetItem(QString::number(a.getid_auto())));
        ui->tblAutos->setItem(row, 1, new QTableWidgetItem(a.getMarca()));
        ui->tblAutos->setItem(row, 2, new QTableWidgetItem(a.getModelo()));
        ui->tblAutos->setItem(row, 3, new QTableWidgetItem(a.getPatente()));
        ui->tblAutos->setItem(row, 4, new QTableWidgetItem(QString::number(a.getAnio())));
        ui->tblAutos->setItem(row, 5, new QTableWidgetItem(a.getColor()));
        ui->tblAutos->setItem(row, 6, new QTableWidgetItem(QString::number(a.getKilometraje())));
        ui->tblAutos->setItem(row, 7, new QTableWidgetItem(QString::number(a.getPrecio_por_dia())));
        ui->tblAutos->setItem(row, 8, new QTableWidgetItem(a.getEstado()));
        row++;
    }
}

int GestorAuto::getIdSeleccionadoTabla() {
    int fila = ui->tblAutos->currentRow();
    if (fila == -1) return -1;
    return ui->tblAutos->item(fila, 0)->text().toInt();
}

void GestorAuto::guardar() {
    Auto obj;
    obj.setMarca(ui->txtMarcaAuto->text());
    obj.setModelo(ui->txtModeloAuto->text());
    obj.setPatente(ui->txtPatenteAuto->text());
    obj.setAnio(ui->txtAnioAuto->text().toInt());
    obj.setColor(ui->cmbColorAuto->currentText());
    obj.setKilometraje(ui->txtKilometrajeAuto->text().toInt());
    obj.setPrecio_por_dia(ui->txtPrecioDiaAuto->text().toDouble());
    obj.setEstado(ui->cmbEstadoAuto->currentText());


    obj.setFechaIngreso(QDate::currentDate().toString("yyyy-MM-dd"));

    daoAuto.insertar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Auto guardado.");
}

void GestorAuto::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    Auto obj;
    obj.setid_auto(id);
    obj.setMarca(ui->txtMarcaAuto->text());
    obj.setModelo(ui->txtModeloAuto->text());
    obj.setPatente(ui->txtPatenteAuto->text());
    obj.setAnio(ui->txtAnioAuto->text().toInt());
    obj.setColor(ui->cmbColorAuto->currentText());
    obj.setKilometraje(ui->txtKilometrajeAuto->text().toInt());
    obj.setPrecio_por_dia(ui->txtPrecioDiaAuto->text().toDouble());
    obj.setEstado(ui->cmbEstadoAuto->currentText());
    obj.setFechaIngreso(QDate::currentDate().toString("yyyy-MM-dd"));

    daoAuto.actualizar(obj);
    listar();
}

void GestorAuto::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Auto obj;
    obj.setid_auto(id);
    daoAuto.eliminar(obj);
    listar();
}