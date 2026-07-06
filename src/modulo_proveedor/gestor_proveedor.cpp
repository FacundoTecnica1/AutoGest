#include "gestor_proveedor.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

GestorProveedor::GestorProveedor(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {
    //le damos limite de 8 caracteres al numero de telefono
    //para mantener un estandar
    ui->txtTelefonoProveedor->setMaxLength(8);
}

void GestorProveedor::poblarTabla(const std::vector<Proveedor>& lista) {
    //vaciamos la tabla por completo antes de meter la data nueva
    //si no hacemos esto se empiezan a duplicar las filas visualmente
    ui->tblProveedores->clearContents();
    ui->tblProveedores->setRowCount(0);
    ui->tblProveedores->setColumnCount(5);
    ui->tblProveedores->setHorizontalHeaderLabels({"ID", "Nombre", "Telefono", "Email", "Direccion"});
    ui->tblProveedores->setColumnHidden(0, true);

    int row = 0;
    for(const auto& p : lista) {
        ui->tblProveedores->insertRow(row);

        //oculto el id en la primer columna
        //para usarlo en las funciones
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
    //si el buscador esta vacio traemos la lista normal
    //si tiene texto llamamos a buscarCampo para que filtre
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoProveedor.buscarCampo(texto));
    }
}

void GestorProveedor::cargarDatos() {
    int fila = ui->tblProveedores->currentRow();
    if (fila == -1) return;

    //agarramos el texto de cada celda y lo clavamos en los inputs del formulario
    ui->txtNombreProveedor->setText(ui->tblProveedores->item(fila, 1)->text());
    ui->txtTelefonoProveedor->setText(ui->tblProveedores->item(fila, 2)->text());
    ui->txtEmailProveedor->setText(ui->tblProveedores->item(fila, 3)->text());
    ui->txtDireccionProveedor->setText(ui->tblProveedores->item(fila, 4)->text());
}

void GestorProveedor::limpiarFormulario() {
    //blanqueamos todos los campos para que quede listo para un ingreso nuevo
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
    QString email = ui->txtEmailProveedor->text().trimmed();

    //si faltan los datos principales, no se guarda el proveedor
    //esto evita registros vacios
    if(ui->txtNombreProveedor->text().trimmed().isEmpty() ||
        ui->txtTelefonoProveedor->text().trimmed().isEmpty()) {
        QMessageBox::warning(ui->centralwidget, "Campos vacíos", "Completa los datos del proveedor antes de guardarlo.");
        return;
    }

    if(!email.isEmpty() && !email.contains("@")) {
        QMessageBox::warning(ui->centralwidget, "Email inválido", "El email tiene que contener @.");
        return;
    }

    Proveedor obj;
    obj.setNombre(ui->txtNombreProveedor->text());
    obj.setTelefono(ui->txtTelefonoProveedor->text());
    obj.setEmail(email);
    obj.setDireccion(ui->txtDireccionProveedor->text());

    daoProveedor.insertar(obj);
    listar();
    limpiarFormulario(); //limpiamos aca despues de insertar
    QMessageBox::information(ui->centralwidget, "Éxito", "Proveedor guardado.");
}

void GestorProveedor::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    QString email = ui->txtEmailProveedor->text().trimmed();

    if(!email.isEmpty() && !email.contains("@")) {
        QMessageBox::warning(ui->centralwidget, "Email inválido", "El email tiene que contener @.");
        return;
    }

    Proveedor obj;
    obj.setid_proveedor(id);
    obj.setNombre(ui->txtNombreProveedor->text());
    obj.setTelefono(ui->txtTelefonoProveedor->text());
    obj.setEmail(email);
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