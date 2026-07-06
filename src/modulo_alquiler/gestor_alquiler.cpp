#include "gestor_alquiler.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

GestorAlquiler::GestorAlquiler(Ui::MainWindow *ui, QObject *parent) : QObject(parent), ui(ui) {
    //el calendario arranca desde manana
    //asi queda bloqueado elegir hoy o fechas anteriores
    ui->dteFechaInicioAlquiler->setMinimumDate(QDate::currentDate().addDays(1));
    ui->dteFechaFinAlquiler->setMinimumDate(QDate::currentDate().addDays(1));
    ui->dteFechaInicioAlquiler->setDate(QDate::currentDate().addDays(1));
    ui->dteFechaFinAlquiler->setDate(QDate::currentDate().addDays(1));
}

void GestorAlquiler::cargarListasCombo() {
    ui->cmbClienteAlquiler->clear();
    for (const auto& c : daoCliente.listar()) {
        ui->cmbClienteAlquiler->addItem(c.getNombre() + " " + c.getApellido(), c.getid_cliente());
    }

    ui->cmbAutoAlquiler->clear();
    for (const auto& a : daoAuto.listar()) {
        ui->cmbAutoAlquiler->addItem(a.getMarca() + " " + a.getModelo() + " - " + a.getPatente(), a.getid_auto());
    }
}

void GestorAlquiler::calcularTotal() {
    QString inicio = ui->dteFechaInicioAlquiler->date().toString("yyyy-MM-dd");
    QString fin = ui->dteFechaFinAlquiler->date().toString("yyyy-MM-dd");
    int idAuto = ui->cmbAutoAlquiler->currentData().toInt();

    double total = daoAlquiler.calcularTotal(idAuto, inicio, fin);
    ui->lblTotalAlquiler->setText("$ " + QString::number(total, 'f', 2));
}

void GestorAlquiler::poblarTabla(const std::vector<std::vector<QString>>& lista) {
    ui->tblAlquileres->clearContents();
    ui->tblAlquileres->setRowCount(0);
    ui->tblAlquileres->setColumnCount(10);
    ui->tblAlquileres->setHorizontalHeaderLabels({"ID", "ID Auto", "ID Cliente", "Auto", "Cliente", "Metodo Pago", "Inicio", "Fin", "Total", "Estado"});
    ui->tblAlquileres->setColumnHidden(0, true);
    ui->tblAlquileres->setColumnHidden(1, true);
    ui->tblAlquileres->setColumnHidden(2, true);

    int row = 0;
    for(const auto& fila : lista) {
        ui->tblAlquileres->insertRow(row);

        //oculto el id en la primer columna
        //para usarlo en las funciones
        ui->tblAlquileres->setItem(row, 0, new QTableWidgetItem(fila[0]));
        ui->tblAlquileres->setItem(row, 1, new QTableWidgetItem(fila[1]));
        ui->tblAlquileres->setItem(row, 2, new QTableWidgetItem(fila[2]));

        //asigno los indices que traen los textos
        //para que no se vean los numeros de id
        ui->tblAlquileres->setItem(row, 3, new QTableWidgetItem(fila[3]));
        ui->tblAlquileres->setItem(row, 4, new QTableWidgetItem(fila[4]));

        //desplazo los indices de los demas datos
        //para que coincidan con la fila del dao
        ui->tblAlquileres->setItem(row, 5, new QTableWidgetItem(fila[5]));
        ui->tblAlquileres->setItem(row, 6, new QTableWidgetItem(fila[6]));
        ui->tblAlquileres->setItem(row, 7, new QTableWidgetItem(fila[7]));
        ui->tblAlquileres->setItem(row, 8, new QTableWidgetItem("$" + fila[8]));
        ui->tblAlquileres->setItem(row, 9, new QTableWidgetItem(fila[9]));
        row++;
    }
}

void GestorAlquiler::listar() {
    poblarTabla(daoAlquiler.listar());
}

void GestorAlquiler::buscar(const QString &texto) {
    if (texto.isEmpty()) {
        listar();
    } else {
        poblarTabla(daoAlquiler.buscarCampo(texto));
    }
}

void GestorAlquiler::cargarDatos() {
    int fila = ui->tblAlquileres->currentRow();
    if (fila == -1) return;

    ui->cmbAutoAlquiler->setCurrentText(ui->tblAlquileres->item(fila, 3)->text().replace(" (", " - ").replace(")", ""));
    ui->cmbClienteAlquiler->setCurrentText(ui->tblAlquileres->item(fila, 4)->text());

    QString metodo = ui->tblAlquileres->item(fila, 5)->text();
    if(!metodo.isEmpty()) {
        metodo[0] = metodo[0].toUpper();
        ui->cmbMetodoPagoAlquiler->setCurrentText(metodo);
    }

    ui->dteFechaInicioAlquiler->setDate(QDate::fromString(ui->tblAlquileres->item(fila, 6)->text(), "yyyy-MM-dd"));
    ui->dteFechaFinAlquiler->setDate(QDate::fromString(ui->tblAlquileres->item(fila, 7)->text(), "yyyy-MM-dd"));

    QString total = ui->tblAlquileres->item(fila, 8)->text().replace("$", "").trimmed();
    ui->lblTotalAlquiler->setText("$ " + total);

    QString estado = ui->tblAlquileres->item(fila, 9)->text();
    if(!estado.isEmpty()) {
        estado[0] = estado[0].toUpper();
        ui->cmbEstadoAlquiler->setCurrentText(estado);
    }
}

void GestorAlquiler::limpiarFormulario() {
    ui->cmbAutoAlquiler->setCurrentIndex(0);
    ui->cmbClienteAlquiler->setCurrentIndex(0);
    ui->cmbMetodoPagoAlquiler->setCurrentIndex(0);
    ui->cmbEstadoAlquiler->setCurrentIndex(0);
    ui->dteFechaInicioAlquiler->setDate(QDate::currentDate().addDays(1));
    ui->dteFechaFinAlquiler->setDate(QDate::currentDate().addDays(1));
    ui->lblTotalAlquiler->setText("$ 0.00");
}

int GestorAlquiler::getIdSeleccionadoTabla() {
    int fila = ui->tblAlquileres->currentRow();
    if (fila == -1) return -1;
    return ui->tblAlquileres->item(fila, 0)->text().toInt();
}

void GestorAlquiler::guardar() {
    QDate inicio = ui->dteFechaInicioAlquiler->date();
    QDate fin = ui->dteFechaFinAlquiler->date();
    int idAuto = ui->cmbAutoAlquiler->currentData().toInt();

    //las fechas se cargan desde manana en adelante
    //asi no se registran alquileres arrancando hoy o antes
    if(inicio <= QDate::currentDate() || fin <= QDate::currentDate() || fin < inicio) {
        QMessageBox::warning(ui->centralwidget, "Fechas invalidas", "Las fechas del alquiler tienen que ser posteriores a hoy y la fecha final no puede ser menor a la inicial.");
        return;
    }

    if(!daoAlquiler.mantenimientoFinalizado(idAuto)) {
        QMessageBox::warning(ui->centralwidget, "Mantenimiento pendiente", "El auto solo se puede alquilar si su ultimo mantenimiento esta finalizado.");
        return;
    }

    if(!daoAlquiler.autoDisponibleParaAlquiler(idAuto, inicio.toString("yyyy-MM-dd"), fin.toString("yyyy-MM-dd"))) {
        QMessageBox::warning(ui->centralwidget, "Auto no disponible", "Ese auto ya tiene un alquiler activo en esas fechas.");
        return;
    }

    Alquiler obj;
    obj.setid_auto(idAuto);
    obj.setid_cliente(ui->cmbClienteAlquiler->currentData().toInt());
    obj.setid_usuario(1);
    obj.setMetodoPago(ui->cmbMetodoPagoAlquiler->currentText().toLower());
    obj.setFechaInicio(ui->dteFechaInicioAlquiler->date().toString("yyyy-MM-dd"));
    obj.setFechaFin(ui->dteFechaFinAlquiler->date().toString("yyyy-MM-dd"));

    QString totalStr = ui->lblTotalAlquiler->text().replace("$ ", "");
    obj.setPrecioTotal(totalStr.toDouble());

    obj.setEstado(ui->cmbEstadoAlquiler->currentText().toLower());

    daoAlquiler.insertar(obj);
    if(obj.getEstado() == "activo") {
        daoAuto.actualizarEstado(idAuto, "Alquilado");
    }
    listar();
    limpiarFormulario();
    QMessageBox::information(ui->centralwidget, "Éxito", "Alquiler guardado.");
}

void GestorAlquiler::actualizar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    int fila = ui->tblAlquileres->currentRow();
    int idAutoAnterior = ui->tblAlquileres->item(fila, 1)->text().toInt();

    QDate inicio = ui->dteFechaInicioAlquiler->date();
    QDate fin = ui->dteFechaFinAlquiler->date();
    int idAuto = ui->cmbAutoAlquiler->currentData().toInt();

    if(inicio <= QDate::currentDate() || fin <= QDate::currentDate() || fin < inicio) {
        QMessageBox::warning(ui->centralwidget, "Fechas invalidas", "Las fechas del alquiler tienen que ser posteriores a hoy y la fecha final no puede ser menor a la inicial.");
        return;
    }

    if(!daoAlquiler.mantenimientoFinalizado(idAuto)) {
        QMessageBox::warning(ui->centralwidget, "Mantenimiento pendiente", "El auto solo se puede alquilar si su ultimo mantenimiento esta finalizado.");
        return;
    }

    if(!daoAlquiler.autoDisponibleParaAlquiler(idAuto, inicio.toString("yyyy-MM-dd"), fin.toString("yyyy-MM-dd"), id)) {
        QMessageBox::warning(ui->centralwidget, "Auto no disponible", "Ese auto ya tiene un alquiler activo en esas fechas.");
        return;
    }

    Alquiler obj;
    obj.setid_alquiler(id);
    obj.setid_auto(idAuto);
    obj.setid_cliente(ui->cmbClienteAlquiler->currentData().toInt());
    obj.setid_usuario(1);
    obj.setMetodoPago(ui->cmbMetodoPagoAlquiler->currentText().toLower());
    obj.setFechaInicio(ui->dteFechaInicioAlquiler->date().toString("yyyy-MM-dd"));
    obj.setFechaFin(ui->dteFechaFinAlquiler->date().toString("yyyy-MM-dd"));

    QString totalStr = ui->lblTotalAlquiler->text().replace("$ ", "");
    obj.setPrecioTotal(totalStr.toDouble());
    obj.setEstado(ui->cmbEstadoAlquiler->currentText().toLower());

    daoAlquiler.actualizar(obj);
    if(idAutoAnterior != idAuto) {
        daoAuto.actualizarEstado(idAutoAnterior, "Disponible");
    }
    if(obj.getEstado() == "activo") {
        daoAuto.actualizarEstado(idAuto, "Alquilado");
    } else {
        daoAuto.actualizarEstado(idAuto, "Disponible");
    }
    listar();
    limpiarFormulario();
}

void GestorAlquiler::eliminar() {
    int id = getIdSeleccionadoTabla();
    if(id == -1) return;
    int fila = ui->tblAlquileres->currentRow();
    int idAuto = ui->tblAlquileres->item(fila, 1)->text().toInt();
    Alquiler obj;
    obj.setid_alquiler(id);
    daoAlquiler.eliminar(obj);
    daoAuto.actualizarEstado(idAuto, "Disponible");
    listar();
    limpiarFormulario();
}
