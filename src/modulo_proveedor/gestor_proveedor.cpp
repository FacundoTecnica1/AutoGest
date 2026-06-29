#include "gestor_proveedor.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

//constructor donde conectamos la interfaz con este gestor
GestorProveedor::GestorProveedor(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorProveedor::listar() {
    //vaciamos todo lo que tenga la tabla para que no se dupliquen los datos al recargar
    ui->tblProveedores->clearContents();
    ui->tblProveedores->setRowCount(0);

    //le decimos cuantas columnas va a tener y le ponemos los nombres arriba
    ui->tblProveedores->setColumnCount(5);
    ui->tblProveedores->setHorizontalHeaderLabels({"ID", "Nombre", "Teléfono", "Email", "Dirección"});

    //escondemos la columna del id
    ui->tblProveedores->setColumnHidden(0, true);

    //traemos todos los proveedores de la base de datos
    auto lista = daoProveedor.listar();
    int row = 0;

    //vamos recorriendo uno por uno y lo metemos en las filas de la tabla
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

int GestorProveedor::getIdSeleccionadoTabla() {
    //nos fijamos que fila toco el usuario
    int fila = ui->tblProveedores->currentRow();

    //si no toco ninguna devuelve -1 para que sepamos que hay error
    if (fila == -1) return -1;

    //sacamos el texto de la columna 0 (el id oculto) y lo pasamos a numero
    return ui->tblProveedores->item(fila, 0)->text().toInt();
}

void GestorProveedor::guardar() {
    //creamos el objeto vacio
    Proveedor obj;

    //le vamos pasando lo que el usuario escribio en los cuadritos de texto
    obj.setNombre(ui->txtNombreProveedor->text());
    obj.setTelefono(ui->txtTelefonoProveedor->text());
    obj.setEmail(ui->txtEmailProveedor->text());
    obj.setDireccion(ui->txtDireccionProveedor->text());

    //lo mandamos a guardar a la base de datos
    daoProveedor.insertar(obj);

    //actualizamos la tabla para que se vea el nuevo y avisamos que salio bien
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Proveedor guardado correctamente.");
}

void GestorProveedor::actualizar() {
    //buscamos cual eligieron
    int id = getIdSeleccionadoTabla();
    if(id == -1) {
        QMessageBox::warning(ui->centralwidget, "Aviso", "Seleccioná un proveedor de la lista primero.");
        return;
    }

    Proveedor obj;
    //le pasamos el id viejo y todos los datos nuevos
    obj.setid_proveedor(id);
    obj.setNombre(ui->txtNombreProveedor->text());
    obj.setTelefono(ui->txtTelefonoProveedor->text());
    obj.setEmail(ui->txtEmailProveedor->text());
    obj.setDireccion(ui->txtDireccionProveedor->text());

    daoProveedor.actualizar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Datos actualizados.");
}

void GestorProveedor::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) {
        QMessageBox::warning(ui->centralwidget, "Aviso", "Seleccioná un proveedor para eliminar.");
        return;
    }

    Proveedor obj;
    obj.setid_proveedor(id);
    daoProveedor.eliminar(obj);
    listar();
    QMessageBox::information(ui->centralwidget, "Éxito", "Proveedor eliminado de la base.");
}