#include "gestor_cliente.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

GestorCliente::GestorCliente(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorCliente::listar() {
    ui->tblClientes->clearContents();
    ui->tblClientes->setRowCount(0);
    ui->tblClientes->setColumnCount(9);
    ui->tblClientes->setHorizontalHeaderLabels({"ID", "Nombre", "Apellido", "Edad", "DNI", "Telefono", "Email", "Direccion", "Licencia"});
    ui->tblClientes->setColumnHidden(0, true);

    auto lista = daoCliente.listar();
    int row = 0;
    for(const auto& c : lista) {
        ui->tblClientes->insertRow(row);
        ui->tblClientes->setItem(row, 0, new QTableWidgetItem(QString::number(c.getid_cliente())));
        ui->tblClientes->setItem(row, 1, new QTableWidgetItem(c.getNombre()));
        ui->tblClientes->setItem(row, 2, new QTableWidgetItem(c.getApellido()));
        ui->tblClientes->setItem(row, 3, new QTableWidgetItem(QString::number(c.getEdad())));
        ui->tblClientes->setItem(row, 4, new QTableWidgetItem(c.getDni()));
        ui->tblClientes->setItem(row, 5, new QTableWidgetItem(c.getTelefono()));
        ui->tblClientes->setItem(row, 6, new QTableWidgetItem(c.getEmail()));
        ui->tblClientes->setItem(row, 7, new QTableWidgetItem(c.getDireccion()));
        ui->tblClientes->setItem(row, 8, new QTableWidgetItem(c.getClaseLicencia()));
        row++;
    }
}

int GestorCliente::getIdSeleccionadoTabla() {
    int fila = ui->tblClientes->currentRow();
    if (fila == -1) return -1;
    return ui->tblClientes->item(fila, 0)->text().toInt();
}

void GestorCliente::guardar() {
    Cliente obj;
    obj.setNombre(ui->txtNombreCliente->text());
    obj.setApellido(ui->txtApellidoCliente->text());
    obj.setEdad(ui->txtEdadCliente->text().toInt());
    obj.setDni(ui->txtDniCliente->text());
    obj.setTelefono(ui->txtTelefonoCliente->text());
    obj.setEmail(ui->txtEmailCliente->text());
    obj.setDireccion(ui->txtDireccionCliente->text());
    obj.setClaseLicencia(ui->cmbClaseLicenciaCliente->currentText());
    obj.setFechaRegistro(QDate::currentDate().toString("yyyy-MM-dd"));

    daoCliente.insertar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Cliente guardado.");
}

void GestorCliente::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    Cliente obj;
    obj.setid_cliente(id);
    obj.setNombre(ui->txtNombreCliente->text());
    obj.setApellido(ui->txtApellidoCliente->text());
    obj.setEdad(ui->txtEdadCliente->text().toInt());
    obj.setDni(ui->txtDniCliente->text());
    obj.setTelefono(ui->txtTelefonoCliente->text());
    obj.setEmail(ui->txtEmailCliente->text());
    obj.setDireccion(ui->txtDireccionCliente->text());
    obj.setClaseLicencia(ui->cmbClaseLicenciaCliente->currentText());
    obj.setFechaRegistro(QDate::currentDate().toString("yyyy-MM-dd"));

    daoCliente.actualizar(obj);
    listar();
}

void GestorCliente::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Cliente obj;
    obj.setid_cliente(id);
    daoCliente.eliminar(obj);
    listar();
}