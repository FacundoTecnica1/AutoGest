#include "gestor_incidente.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

GestorIncidente::GestorIncidente(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {}

void GestorIncidente::cargarListasCombo() {
    ui->cmbAutoIncidente->clear();
    for (const auto& a : daoAuto.listar()) {
        ui->cmbAutoIncidente->addItem(a.getMarca() + " " + a.getModelo() + " - " + a.getPatente(), a.getid_auto());
    }

    ui->cmbClienteIncidente->clear();
    for (const auto& c : daoCliente.listar()) {
        ui->cmbClienteIncidente->addItem(c.getNombre() + " " + c.getApellido(), c.getid_cliente());
    }
}

void GestorIncidente::poblarTabla(const std::vector<std::vector<QString>>& lista) {
    ui->tblIncidentes->clearContents();
    ui->tblIncidentes->setRowCount(0);
    ui->tblIncidentes->setColumnCount(8);
    ui->tblIncidentes->setHorizontalHeaderLabels({"ID", "ID Alq", "Tipo", "Cliente", "Auto", "Fecha", "Descripcion", "Costo"});
    ui->tblIncidentes->setColumnHidden(0, true);
    ui->tblIncidentes->setColumnHidden(1, true);

    int row = 0;
    for(const auto& fila : lista) {
        ui->tblIncidentes->insertRow(row);
        ui->tblIncidentes->setItem(row, 0, new QTableWidgetItem(fila[0]));
        ui->tblIncidentes->setItem(row, 1, new QTableWidgetItem(fila[1]));
        ui->tblIncidentes->setItem(row, 2, new QTableWidgetItem(fila[2]));
        ui->tblIncidentes->setItem(row, 3, new QTableWidgetItem(fila[3]));
        ui->tblIncidentes->setItem(row, 4, new QTableWidgetItem(fila[4]));
        ui->tblIncidentes->setItem(row, 5, new QTableWidgetItem(fila[5]));
        ui->tblIncidentes->setItem(row, 6, new QTableWidgetItem(fila[6]));
        ui->tblIncidentes->setItem(row, 7, new QTableWidgetItem("$" + fila[7]));
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

    //cargamos lo visible de la tabla al formulario
    //los ids quedan ocultos solo para poder actualizar o borrar
    ui->txtTipoIncidente->setText(ui->tblIncidentes->item(fila, 2)->text());
    ui->cmbClienteIncidente->setCurrentText(ui->tblIncidentes->item(fila, 3)->text());
    ui->cmbAutoIncidente->setCurrentText(ui->tblIncidentes->item(fila, 4)->text().replace(" (", " - ").replace(")", ""));
    ui->dteFechaIncidente->setDate(QDate::fromString(ui->tblIncidentes->item(fila, 5)->text(), "yyyy-MM-dd"));
    ui->txtDescripcionIncidente->setText(ui->tblIncidentes->item(fila, 6)->text());

    QString costo = ui->tblIncidentes->item(fila, 7)->text().replace("$", "").trimmed();
    ui->txtCostoIncidente->setText(costo);
}

void GestorIncidente::limpiarFormulario() {
    ui->txtTipoIncidente->clear();
    ui->cmbAutoIncidente->setCurrentIndex(0);
    ui->cmbClienteIncidente->setCurrentIndex(0);
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
    QString fecha = ui->dteFechaIncidente->date().toString("yyyy-MM-dd");

    //buscamos el alquiler real con ese auto, cliente y fecha
    //si no existe, no hay forma correcta de asociar el incidente
    int idAlquiler = daoIncidente.buscarAlquilerActivo(ui->cmbAutoIncidente->currentData().toInt(),
                                                       ui->cmbClienteIncidente->currentData().toInt(),
                                                       fecha);

    if(idAlquiler == -1) {
        QMessageBox::warning(ui->centralwidget, "Sin alquiler activo", "No hay un alquiler activo para ese auto, cliente y fecha.");
        return;
    }

    Incidente obj;
    obj.setid_alquiler(idAlquiler);
    obj.setTipoIncidente(ui->txtTipoIncidente->text());
    obj.setFechaIncidente(fecha);
    obj.setDescripcion(ui->txtDescripcionIncidente->text());
    obj.setCosto(ui->txtCostoIncidente->text().toDouble());

    daoIncidente.insertar(obj);
    daoIncidente.finalizarAlquilerSiCorresponde(idAlquiler, fecha);
    daoAuto.actualizarEstado(ui->cmbAutoIncidente->currentData().toInt(), "En mantenimiento");
    listar();
    limpiarFormulario();
    QMessageBox::information(ui->centralwidget, "Exito", "Incidente reportado.");
}

void GestorIncidente::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    QString fecha = ui->dteFechaIncidente->date().toString("yyyy-MM-dd");
    int idAlquiler = daoIncidente.buscarAlquilerActivo(ui->cmbAutoIncidente->currentData().toInt(),
                                                       ui->cmbClienteIncidente->currentData().toInt(),
                                                       fecha);

    if(idAlquiler == -1) {
        QMessageBox::warning(ui->centralwidget, "Sin alquiler activo", "No hay un alquiler activo para ese auto, cliente y fecha.");
        return;
    }

    Incidente obj;
    obj.setid_incidente(id);
    obj.setid_alquiler(idAlquiler);
    obj.setTipoIncidente(ui->txtTipoIncidente->text());
    obj.setFechaIncidente(fecha);
    obj.setDescripcion(ui->txtDescripcionIncidente->text());
    obj.setCosto(ui->txtCostoIncidente->text().toDouble());

    daoIncidente.actualizar(obj);
    daoIncidente.finalizarAlquilerSiCorresponde(idAlquiler, fecha);
    daoAuto.actualizarEstado(ui->cmbAutoIncidente->currentData().toInt(), "En mantenimiento");
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
