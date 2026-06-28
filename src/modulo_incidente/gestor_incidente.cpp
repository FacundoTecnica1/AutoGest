#include "gestor_incidente.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

GestorIncidente::GestorIncidente(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorIncidente::listar() {
    //limpiamos la tabla
    ui->tblIncidentes->clearContents();
    ui->tblIncidentes->setRowCount(0);

    ui->tblIncidentes->setColumnCount(6);
    ui->tblIncidentes->setHorizontalHeaderLabels({"ID", "ID Alq", "Tipo", "Fecha", "Descripción", "Costo"});

    //ocultamos los dos primeros ids
    ui->tblIncidentes->setColumnHidden(0, true);
    ui->tblIncidentes->setColumnHidden(1, true);

    auto lista = daoIncidente.listar();
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

int GestorIncidente::getIdSeleccionadoTabla() {
    int fila = ui->tblIncidentes->currentRow();
    if (fila == -1) return -1;
    return ui->tblIncidentes->item(fila, 0)->text().toInt();
}

void GestorIncidente::guardar() {
    Incidente obj;

    //pasa lo mismo que antes, no tenes como seleccionar a que alquiler pertenece
    //le pongo un 1 fijo para que te deje guardar sin que explote la base
    obj.setid_alquiler(1);

    obj.setTipoIncidente(ui->txtTipoIncidente->text());

    //sacamos la fecha que eligieron en el cuadradito del calendario
    obj.setFechaIncidente(ui->dteFechaIncidente->date().toString("yyyy-MM-dd"));

    obj.setDescripcion(ui->txtDescripcionIncidente->text());
    obj.setCosto(ui->txtCostoIncidente->text().toDouble());

    daoIncidente.insertar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Incidente reportado.");
}

void GestorIncidente::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) {
        QMessageBox::warning(ui->centralwidget, "Aviso", "Seleccioná un incidente de la tabla che.");
        return;
    }

    Incidente obj;
    obj.setid_incidente(id);
    obj.setid_alquiler(1); //mismo detalle del id fijo
    obj.setTipoIncidente(ui->txtTipoIncidente->text());
    obj.setFechaIncidente(ui->dteFechaIncidente->date().toString("yyyy-MM-dd"));
    obj.setDescripcion(ui->txtDescripcionIncidente->text());
    obj.setCosto(ui->txtCostoIncidente->text().toDouble());

    daoIncidente.actualizar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Incidente actualizado.");
}

void GestorIncidente::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) {
        QMessageBox::warning(ui->centralwidget, "Aviso", "Tenes que tocar un incidente en la tabla para borrarlo.");
        return;
    }
    Incidente obj;
    obj.setid_incidente(id);
    daoIncidente.eliminar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "El incidente fue eliminado.");
}