#include "gestor_proveedor.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

GestorProveedor::GestorProveedor(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {
    //le damos 12 caracteres de limite al telefono por si ponen codigos de area
    ui->txtTelefonoProveedor->setMaxLength(12);
}

void GestorProveedor::poblarTabla(const std::vector<Proveedor>& lista) {
    ui->tblProveedores->clearContents();
    ui->tblProveedores->setRowCount(0);
    ui->tblProveedores->setColumnCount(5);
    ui->tblProveedores->setHorizontalHeaderLabels({"ID", "Nombre", "Teléfono", "Email", "Dirección"});
    ui->tblProveedores->setColumnHidden(0, true);

    int row = 0;
    for(const auto& p : lista) {
        ui->tblProveedores->insertRow(row);
        ui->tblProveedores->setItem(row, 0, new QTableWidgetItem(QString::number(p.getid_proveedor())));
        ui->tblProveedores->setItem(row, 1, new QTableWidgetItem(p.getNombre()));
        ui->tblProveedores->setItem(row, 2, new QTableWidgetItem(p.getTelefono()));
        ui->tblProveedores->setItem(row, 3, new QTableWidgetItem(p.getEmail()));
        ui->tblProveedores->setItem(row, 4, new QTableWidgetItem(p.getDireccion()));
        row++;
    }
}

void GestorProveedor::listar() {
    poblarTabla(daoProveedor.listar());
}

void GestorProveedor::buscar(const QString &texto) {
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoProveedor.buscarCampo(texto));
    }
}

void GestorProveedor::cargarDatos() {
    int fila = ui->tblProveedores->currentRow();
    if (fila == -1) return;

    ui->txtNombreProveedor->setText(ui->tblProveedores->item(fila, 1)->text());
    ui->txtTelefonoProveedor->setText(ui->tblProveedores->item(fila, 2)->text());
    ui->txtEmailProveedor->setText(ui->tblProveedores->item(fila, 3)->text());
    ui->txtDireccionProveedor->setText(ui->tblProveedores->item(fila, 4)->text());
}

void GestorProveedor::limpiarFormulario() {
    ui->txtNombreProveedor->clear();
    ui->txtTelefonoProveedor->clear();
    ui->txtEmailProveedor->clear();
    ui->txtDireccionProveedor->clear();
}

int GestorProveedor::getIdSeleccionadoTabla() {
    int fila = ui->tblProveedores->currentRow();
    if (fila == -1) return -1;
    return ui->tblProveedores->item(fila, 0)->text().toInt();
}

void GestorProveedor::guardar() {
    Proveedor obj;
    obj.setNombre(ui->txtNombreProveedor->text());
    obj.setTelefono(ui->txtTelefonoProveedor->text());
    obj.setEmail(ui->txtEmailProveedor->text());
    obj.setDireccion(ui->txtDireccionProveedor->text());

    daoProveedor.insertar(obj);
    listar();
    limpiarFormulario();
    QMessageBox::information(ui->centralwidget, "Éxito", "Proveedor guardado correctamente.");
}

void GestorProveedor::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    Proveedor obj;
    obj.setid_proveedor(id);
    obj.setNombre(ui->txtNombreProveedor->text());
    obj.setTelefono(ui->txtTelefonoProveedor->text());
    obj.setEmail(ui->txtEmailProveedor->text());
    obj.setDireccion(ui->txtDireccionProveedor->text());

    daoProveedor.actualizar(obj);
    listar();
    limpiarFormulario();
}

void GestorProveedor::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    Proveedor obj;
    obj.setid_proveedor(id);
    daoProveedor.eliminar(obj);
    listar();
    limpiarFormulario();
}