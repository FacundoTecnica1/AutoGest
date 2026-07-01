#include "gestor_incidente.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

GestorIncidente::GestorIncidente(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorIncidente::poblarTabla(const std::vector<Incidente>& lista) {
    ui->tblIncidentes->clearContents();
    ui->tblIncidentes->setRowCount(0);
    ui->tblIncidentes->setColumnCount(6);
    ui->tblIncidentes->setHorizontalHeaderLabels({"ID", "ID Alq", "Tipo", "Fecha", "Descripción", "Costo"});
    ui->tblIncidentes->setColumnHidden(0, true);
    ui->tblIncidentes->setColumnHidden(1, true);

    int row = 0;
    for(const auto& i : lista) {
        ui->tblIncidentes->insertRow(row);
        ui->tblIncidentes->setItem(row, 0, new QTableWidgetItem(QString::number(i.getid_incidente())));
        ui->tblIncidentes->setItem(row, 1, new QTableWidgetItem(QString::number(i.getid_alquiler())));
        ui->tblIncidentes->setItem(row, 2, new QTableWidgetItem(i.getTipoIncidente()));
        ui->tblIncidentes->setItem(row, 3, new QTableWidgetItem(i.getFechaIncidente()));
        ui->tblIncidentes->setItem(row, 4, new QTableWidgetItem(i.getDescripcion()));
        ui->tblIncidentes->setItem(row, 5, new QTableWidgetItem("$" + QString::number(i.getCosto())));
        row++;
    }
}

void GestorIncidente::listar() {
    poblarTabla(daoIncidente.listar());
}

void GestorIncidente::buscar(const QString &texto) {
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoIncidente.buscarCampo(texto));
    }
}

void GestorIncidente::cargarDatos() {
    int fila = ui->tblIncidentes->currentRow();
    if (fila == -1) return;

    ui->txtTipoIncidente->setText(ui->tblIncidentes->item(fila, 2)->text());
    ui->dteFechaIncidente->setDate(QDate::fromString(ui->tblIncidentes->item(fila, 3)->text(), "yyyy-MM-dd"));
    ui->txtDescripcionIncidente->setText(ui->tblIncidentes->item(fila, 4)->text());

    QString costo = ui->tblIncidentes->item(fila, 5)->text().replace("$", "").trimmed();
    ui->txtCostoIncidente->setText(costo);
}

void GestorIncidente::limpiarFormulario() {
    ui->txtTipoIncidente->clear();
    ui->dteFechaIncidente->setDate(QDate::currentDate());
    ui->txtDescripcionIncidente->clear();
    ui->txtCostoIncidente->clear();
}

int GestorIncidente::getIdSeleccionadoTabla() {
    int fila = ui->tblIncidentes->currentRow();
    if (fila == -1) return -1;
    return ui->tblIncidentes->item(fila, 0)->text().toInt();
}

void GestorIncidente::guardar() {
    Incidente obj;
    obj.setid_alquiler(1);
    obj.setTipoIncidente(ui->txtTipoIncidente->text());
    obj.setFechaIncidente(ui->dteFechaIncidente->date().toString("yyyy-MM-dd"));
    obj.setDescripcion(ui->txtDescripcionIncidente->text());
    obj.setCosto(ui->txtCostoIncidente->text().toDouble());

    daoIncidente.insertar(obj);
    listar();
    limpiarFormulario();
    QMessageBox::information(ui->centralwidget, "Éxito", "Incidente reportado.");
}

void GestorIncidente::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    Incidente obj;
    obj.setid_incidente(id);
    obj.setid_alquiler(1);
    obj.setTipoIncidente(ui->txtTipoIncidente->text());
    obj.setFechaIncidente(ui->dteFechaIncidente->date().toString("yyyy-MM-dd"));
    obj.setDescripcion(ui->txtDescripcionIncidente->text());
    obj.setCosto(ui->txtCostoIncidente->text().toDouble());

    daoIncidente.actualizar(obj);
    listar();
    limpiarFormulario();
}

void GestorIncidente::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Incidente obj;
    obj.setid_incidente(id);
    daoIncidente.eliminar(obj);
    listar();
    limpiarFormulario();
}