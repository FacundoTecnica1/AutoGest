#include "gestor_auto.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

GestorAuto::GestorAuto(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {
    //limite de 7 caracteres para la patente
    ui->txtPatenteAuto->setMaxLength(7);
}

void GestorAuto::poblarTabla(const std::vector<Auto>& lista) {
    //vaciamos la tabla por completo antes de meter la data nueva
    //si no hacemos esto se empiezan a duplicar las filas visualmente
    ui->tblAutos->clearContents();
    ui->tblAutos->setRowCount(0);
    ui->tblAutos->setColumnCount(9);
    ui->tblAutos->setHorizontalHeaderLabels({"ID", "Marca", "Modelo", "Patente", "Año", "Color", "Km", "Precio/Dia", "Estado"});
    ui->tblAutos->setColumnHidden(0, true);

    int row = 0;
    for(const auto& a : lista) {
        ui->tblAutos->insertRow(row);
        ui->tblAutos->setItem(row, 0, new QTableWidgetItem(QString::number(a.getid_auto())));
        ui->tblAutos->setItem(row, 1, new QTableWidgetItem(a.getMarca()));
        ui->tblAutos->setItem(row, 2, new QTableWidgetItem(a.getModelo()));
        ui->tblAutos->setItem(row, 3, new QTableWidgetItem(a.getPatente()));
        ui->tblAutos->setItem(row, 4, new QTableWidgetItem(QString::number(a.getAnio())));
        ui->tblAutos->setItem(row, 5, new QTableWidgetItem(a.getColor()));
        ui->tblAutos->setItem(row, 6, new QTableWidgetItem(QString::number(a.getKilometraje())));
        ui->tblAutos->setItem(row, 7, new QTableWidgetItem(QString::number(a.getPrecio_por_dia())));
        ui->tblAutos->setItem(row, 8, new QTableWidgetItem(a.getEstado()));
        row++;
    }
}

void GestorAuto::listar() {
    poblarTabla(daoAuto.listar());
}

void GestorAuto::buscar(const QString &texto) {
    //si el buscador esta vacio traemos la lista normal
    //si tiene texto llamamos a buscarCampo para que filtre
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoAuto.buscarCampo(texto));
    }
}

void GestorAuto::cargarDatos() {
    int fila = ui->tblAutos->currentRow();
    if (fila == -1) return;

    //agarramos el texto de cada celda y lo clavamos en los inputs del formulario
    ui->txtMarcaAuto->setText(ui->tblAutos->item(fila, 1)->text());
    ui->txtModeloAuto->setText(ui->tblAutos->item(fila, 2)->text());
    ui->txtPatenteAuto->setText(ui->tblAutos->item(fila, 3)->text());
    ui->txtAnioAuto->setText(ui->tblAutos->item(fila, 4)->text());
    ui->cmbColorAuto->setCurrentText(ui->tblAutos->item(fila, 5)->text());
    ui->txtKilometrajeAuto->setText(ui->tblAutos->item(fila, 6)->text());
    ui->txtPrecioDiaAuto->setText(ui->tblAutos->item(fila, 7)->text());
    ui->cmbEstadoAuto->setCurrentText(ui->tblAutos->item(fila, 8)->text());
}

void GestorAuto::limpiarFormulario() {
    //blanqueamos todos los campos para que quede listo para un ingreso nuevo
    ui->txtMarcaAuto->clear();
    ui->txtModeloAuto->clear();
    ui->txtPatenteAuto->clear();
    ui->txtAnioAuto->clear();
    ui->txtKilometrajeAuto->clear();
    ui->txtPrecioDiaAuto->clear();
    ui->cmbColorAuto->setCurrentIndex(0);
    ui->cmbEstadoAuto->setCurrentIndex(0);
}

int GestorAuto::getIdSeleccionadoTabla() {
    int fila = ui->tblAutos->currentRow();
    if (fila == -1) return -1;
    return ui->tblAutos->item(fila, 0)->text().toInt();
}

void GestorAuto::guardar() {
    //si faltan los datos principales, no se guarda el auto
    //esto evita registros vacios que despues rompen los combos
    if(ui->txtMarcaAuto->text().trimmed().isEmpty() ||
       ui->txtModeloAuto->text().trimmed().isEmpty() ||
       ui->txtPatenteAuto->text().trimmed().isEmpty() ||
       ui->txtAnioAuto->text().trimmed().isEmpty() ||
       ui->txtKilometrajeAuto->text().trimmed().isEmpty() ||
       ui->txtPrecioDiaAuto->text().trimmed().isEmpty()) {
        QMessageBox::warning(ui->centralwidget, "Campos vacios", "Completa los datos del auto antes de guardarlo.");
        return;
    }

    Auto obj;
    obj.setMarca(ui->txtMarcaAuto->text());
    obj.setModelo(ui->txtModeloAuto->text());
    obj.setPatente(ui->txtPatenteAuto->text());
    obj.setAnio(ui->txtAnioAuto->text().toInt());
    obj.setColor(ui->cmbColorAuto->currentText());
    obj.setKilometraje(ui->txtKilometrajeAuto->text().toInt());
    obj.setPrecio_por_dia(ui->txtPrecioDiaAuto->text().toDouble());
    obj.setEstado(ui->cmbEstadoAuto->currentText());
    obj.setFechaIngreso(QDate::currentDate().toString("yyyy-MM-dd"));

    daoAuto.insertar(obj);
    listar();
    limpiarFormulario(); //limpiamos aca despues de insertar
    QMessageBox::information(ui->centralwidget, "Éxito", "Auto guardado.");
}

void GestorAuto::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;

    Auto obj;
    obj.setid_auto(id);
    obj.setMarca(ui->txtMarcaAuto->text());
    obj.setModelo(ui->txtModeloAuto->text());
    obj.setPatente(ui->txtPatenteAuto->text());
    obj.setAnio(ui->txtAnioAuto->text().toInt());
    obj.setColor(ui->cmbColorAuto->currentText());
    obj.setKilometraje(ui->txtKilometrajeAuto->text().toInt());
    obj.setPrecio_por_dia(ui->txtPrecioDiaAuto->text().toDouble());
    obj.setEstado(ui->cmbEstadoAuto->currentText());
    obj.setFechaIngreso(QDate::currentDate().toString("yyyy-MM-dd"));

    daoAuto.actualizar(obj);
    listar();
    limpiarFormulario();
}

void GestorAuto::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    Auto obj;
    obj.setid_auto(id);
    daoAuto.eliminar(obj);
    listar();
    limpiarFormulario();
}
