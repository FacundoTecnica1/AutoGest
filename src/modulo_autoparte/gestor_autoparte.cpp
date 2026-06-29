#include "gestor_autoparte.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

GestorAutoparte::GestorAutoparte(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorAutoparte::listar() {

    //limpiamos todo antes de cargar
    ui->tblAutopartes->clearContents();
    ui->tblAutopartes->setRowCount(0);

    //definimos las columnas
    ui->tblAutopartes->setColumnCount(7);
    ui->tblAutopartes->setHorizontalHeaderLabels({"ID", "ID Prov", "ID Mant", "Nombre", "Marca", "Precio", "Stock"});

    //ocultamos los ids para que quede mas limpia la tabla
    ui->tblAutopartes->setColumnHidden(0, true);
    ui->tblAutopartes->setColumnHidden(1, true);
    ui->tblAutopartes->setColumnHidden(2, true);

    auto lista = daoAutoparte.listar();
    int row = 0;

    for(const auto& a : lista) {
        ui->tblAutopartes->insertRow(row);
        ui->tblAutopartes->setItem(row, 0, new QTableWidgetItem(QString::number(a.getid_autoparte())));
        ui->tblAutopartes->setItem(row, 1, new QTableWidgetItem(QString::number(a.getid_proveedor())));
        ui->tblAutopartes->setItem(row, 2, new QTableWidgetItem(QString::number(a.getid_Mantenimiento())));
        ui->tblAutopartes->setItem(row, 3, new QTableWidgetItem(a.getNombre()));
        ui->tblAutopartes->setItem(row, 4, new QTableWidgetItem(a.getMarca()));

        //le metemos el signito de pesos para que quede mejor
        ui->tblAutopartes->setItem(row, 5, new QTableWidgetItem("$" + QString::number(a.getPrecio())));
        ui->tblAutopartes->setItem(row, 6, new QTableWidgetItem(QString::number(a.getStock())));
        row++;
    }
}

int GestorAutoparte::getIdSeleccionadoTabla() {
    int fila = ui->tblAutopartes->currentRow();
    if (fila == -1) return -1;
    return ui->tblAutopartes->item(fila, 0)->text().toInt();
}

void GestorAutoparte::guardar() {
    Autoparte obj;


    obj.setid_proveedor(1);
    obj.setid_Mantenimiento(1);

    obj.setNombre(ui->txtNombreAutoparte->text());
    obj.setMarca(ui->txtMarcaAutoparte->text());
    obj.setPrecio(ui->txtPrecioAutoparte->text().toDouble());
    obj.setStock(ui->txtStockAutoparte->text().toInt());

    daoAutoparte.insertar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Autoparte guardada.");
}

void GestorAutoparte::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) {
        QMessageBox::warning(ui->centralwidget, "Aviso", "Seleccioná una autoparte de la tabla.");
        return;
    }

    Autoparte obj;
    obj.setid_autoparte(id);

    //volvemos a poner los ids fijos por las dudas
    obj.setid_proveedor(1);
    obj.setid_Mantenimiento(1);

    obj.setNombre(ui->txtNombreAutoparte->text());
    obj.setMarca(ui->txtMarcaAutoparte->text());
    obj.setPrecio(ui->txtPrecioAutoparte->text().toDouble());
    obj.setStock(ui->txtStockAutoparte->text().toInt());

    daoAutoparte.actualizar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Autoparte actualizada.");
}

void GestorAutoparte::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) {
        QMessageBox::warning(ui->centralwidget, "Aviso", "Seleccioná algo para borrar.");
        return;
    }
    Autoparte obj;
    obj.setid_autoparte(id);
    daoAutoparte.eliminar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Autoparte borrada con éxito.");
}