#include "gestor_cliente.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

GestorCliente::GestorCliente(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {
    //le damos limite de 8 caracteres al numero de telefono
    //tambien le metemos limite al dni para mantener un estandar
    ui->txtTelefonoCliente->setMaxLength(8);
    ui->txtDniCliente->setMaxLength(8);
}

void GestorCliente::poblarTabla(const std::vector<Cliente>& lista) {
    ui->tblClientes->clearContents();
    ui->tblClientes->setRowCount(0);
    ui->tblClientes->setColumnCount(9);
    ui->tblClientes->setHorizontalHeaderLabels({"ID", "Nombre", "Apellido", "Edad", "DNI", "Telefono", "Email", "Direccion", "Licencia"});
    ui->tblClientes->setColumnHidden(0, true);

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

void GestorCliente::listar() {
    poblarTabla(daoCliente.listar());
}

void GestorCliente::buscar(const QString &texto) {
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoCliente.buscarCampo(texto));
    }
}

void GestorCliente::cargarDatos() {
    int fila = ui->tblClientes->currentRow();
    if (fila == -1) return;

    //rescatamos los datos de la fila tocada y actualizamos los controles
    ui->txtNombreCliente->setText(ui->tblClientes->item(fila, 1)->text());
    ui->txtApellidoCliente->setText(ui->tblClientes->item(fila, 2)->text());
    ui->txtEdadCliente->setText(ui->tblClientes->item(fila, 3)->text());
    ui->txtDniCliente->setText(ui->tblClientes->item(fila, 4)->text());
    ui->txtTelefonoCliente->setText(ui->tblClientes->item(fila, 5)->text());
    ui->txtEmailCliente->setText(ui->tblClientes->item(fila, 6)->text());
    ui->txtDireccionCliente->setText(ui->tblClientes->item(fila, 7)->text());
    ui->cmbClaseLicenciaCliente->setCurrentText(ui->tblClientes->item(fila, 8)->text());
}

void GestorCliente::limpiarFormulario() {
    ui->txtNombreCliente->clear();
    ui->txtApellidoCliente->clear();
    ui->txtEdadCliente->clear();
    ui->txtDniCliente->clear();
    ui->txtTelefonoCliente->clear();
    ui->txtEmailCliente->clear();
    ui->txtDireccionCliente->clear();
    ui->cmbClaseLicenciaCliente->setCurrentIndex(0);
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
    limpiarFormulario();
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
    limpiarFormulario();
}

void GestorCliente::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Cliente obj;
    obj.setid_cliente(id);
    daoCliente.eliminar(obj);
    listar();
    limpiarFormulario();
}