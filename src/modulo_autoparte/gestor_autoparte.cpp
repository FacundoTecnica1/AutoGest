#include "gestor_autoparte.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

GestorAutoparte::GestorAutoparte(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {
    //ponemos un maximo logico al stock para no mandar numeros re locos a la base
    ui->txtStockAutoparte->setMaxLength(5);
}

void GestorAutoparte::poblarTabla(const std::vector<Autoparte>& lista) {
    ui->tblAutopartes->clearContents();
    ui->tblAutopartes->setRowCount(0);
    ui->tblAutopartes->setColumnCount(7);
    ui->tblAutopartes->setHorizontalHeaderLabels({"ID", "ID Prov", "ID Mant", "Nombre", "Marca", "Precio", "Stock"});
    ui->tblAutopartes->setColumnHidden(0, true);
    ui->tblAutopartes->setColumnHidden(1, true);
    ui->tblAutopartes->setColumnHidden(2, true);

    int row = 0;
    for(const auto& a : lista) {
        ui->tblAutopartes->insertRow(row);
        ui->tblAutopartes->setItem(row, 0, new QTableWidgetItem(QString::number(a.getid_autoparte())));
        ui->tblAutopartes->setItem(row, 1, new QTableWidgetItem(QString::number(a.getid_proveedor())));
        ui->tblAutopartes->setItem(row, 2, new QTableWidgetItem(QString::number(a.getid_Mantenimiento())));
        ui->tblAutopartes->setItem(row, 3, new QTableWidgetItem(a.getNombre()));
        ui->tblAutopartes->setItem(row, 4, new QTableWidgetItem(a.getMarca()));
        ui->tblAutopartes->setItem(row, 5, new QTableWidgetItem("$" + QString::number(a.getPrecio())));
        ui->tblAutopartes->setItem(row, 6, new QTableWidgetItem(QString::number(a.getStock())));
        row++;
    }
}

void GestorAutoparte::listar() {
    poblarTabla(daoAutoparte.listar());
}

void GestorAutoparte::buscar(const QString &texto) {
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoAutoparte.buscarCampo(texto));
    }
}

void GestorAutoparte::cargarDatos() {
    int fila = ui->tblAutopartes->currentRow();
    if (fila == -1) return;

    ui->txtNombreAutoparte->setText(ui->tblAutopartes->item(fila, 3)->text());
    ui->txtMarcaAutoparte->setText(ui->tblAutopartes->item(fila, 4)->text());

    QString precio = ui->tblAutopartes->item(fila, 5)->text().replace("$", "").trimmed();
    ui->txtPrecioAutoparte->setText(precio);

    ui->txtStockAutoparte->setText(ui->tblAutopartes->item(fila, 6)->text());
}

void GestorAutoparte::limpiarFormulario() {
    ui->txtNombreAutoparte->clear();
    ui->txtMarcaAutoparte->clear();
    ui->txtPrecioAutoparte->clear();
    ui->txtStockAutoparte->clear();
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
    limpiarFormulario();
    QMessageBox::information(ui->centralwidget, "Éxito", "Autoparte guardada.");
}

void GestorAutoparte::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    Autoparte obj;
    obj.setid_autoparte(id);
    obj.setid_proveedor(1);
    obj.setid_Mantenimiento(1);
    obj.setNombre(ui->txtNombreAutoparte->text());
    obj.setMarca(ui->txtMarcaAutoparte->text());
    obj.setPrecio(ui->txtPrecioAutoparte->text().toDouble());
    obj.setStock(ui->txtStockAutoparte->text().toInt());

    daoAutoparte.actualizar(obj);
    listar();
    limpiarFormulario();
}

void GestorAutoparte::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Autoparte obj;
    obj.setid_autoparte(id);
    daoAutoparte.eliminar(obj);
    listar();
    limpiarFormulario();
}