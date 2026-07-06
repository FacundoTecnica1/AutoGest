#include "gestor_autoparte.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>

GestorAutoparte::GestorAutoparte(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {
    //ponemos un maximo logico al stock
    //para no mandar numeros re locos a la base
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
    //busco el primer id de proveedor
    //y si no hay corto todo aca
    int idProv = -1;
    QSqlQuery qProv("SELECT id_proveedor FROM proveedor ORDER BY id_proveedor");
    if(qProv.next()) {
        idProv = qProv.value(0).toInt();
    } else {
        QMessageBox::warning(ui->centralwidget, "Faltan datos", "Tenés que crear un proveedor antes de guardar una autoparte.");
        return;
    }

    //la autoparte puede quedar sin mantenimiento
    //si existe alguno lo asociamos, y si no queda libre
    int idMant = 0;
    QSqlQuery qMant("SELECT id_mantenimiento FROM mantenimiento ORDER BY id_mantenimiento");
    if(qMant.next()) {
        idMant = qMant.value(0).toInt();
    }

    Autoparte obj;
    obj.setid_proveedor(idProv);
    obj.setid_Mantenimiento(idMant);
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

    //repito el filtro de seguridad para el proveedor
    //asi evitamos que se rompa al editar
    int idProv = -1;
    QSqlQuery qProv("SELECT id_proveedor FROM proveedor ORDER BY id_proveedor");
    if(qProv.next()) {
        idProv = qProv.value(0).toInt();
    } else {
        QMessageBox::warning(ui->centralwidget, "Faltan datos", "No hay proveedores en la base de datos.");
        return;
    }

    //si no hay mantenimiento, la autoparte queda sin esa asociacion
    //esto permite cargar repuestos antes de usarlos en un trabajo
    int idMant = 0;
    QSqlQuery qMant("SELECT id_mantenimiento FROM mantenimiento ORDER BY id_mantenimiento");
    if(qMant.next()) {
        idMant = qMant.value(0).toInt();
    }

    Autoparte obj;
    obj.setid_autoparte(id);
    obj.setid_proveedor(idProv);
    obj.setid_Mantenimiento(idMant);
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
