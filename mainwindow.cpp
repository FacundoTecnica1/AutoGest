#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "admindaoimpl.h"
#include <QMessageBox>

//Incluimos todos nuestros gestores
#include "gestor_auto.h"
#include "gestor_cliente.h"
#include "gestor_alquiler.h"
#include "gestor_mantenimiento.h"
#include "gestor_proveedor.h"
#include "gestor_autoparte.h"
#include "gestor_incidente.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Instanciamos los gestores y les pasamos la UI
    gestorAuto = new GestorAuto(ui, this);
    gestorCliente = new GestorCliente(ui, this);
    gestorAlquiler = new GestorAlquiler(ui, this);
    gestorMantenimiento = new GestorMantenimiento(ui, this);
    gestorProveedor = new GestorProveedor(ui, this);
    gestorAutoparte = new GestorAutoparte(ui, this);
    gestorIncidente = new GestorIncidente(ui, this);

    //Cargamos las tablas y combobox iniciales
    gestorAuto->listar();
    gestorCliente->listar();
    gestorAlquiler->cargarListasCombo();
    gestorAlquiler->listar();
    gestorMantenimiento->cargarListasCombo();
    gestorMantenimiento->listar();
    gestorProveedor->listar();
    gestorAutoparte->listar();
    gestorIncidente->listar();

    //Conectamos las fechas y el combobox de auto para que cambien el total del alquiler automaticamente
    connect(ui->dteFechaInicioAlquiler, &QDateEdit::dateChanged, gestorAlquiler, &GestorAlquiler::calcularTotal);
    connect(ui->dteFechaFinAlquiler, &QDateEdit::dateChanged, gestorAlquiler, &GestorAlquiler::calcularTotal);
    connect(ui->cmbAutoAlquiler, &QComboBox::currentIndexChanged, gestorAlquiler, &GestorAlquiler::calcularTotal);
}

MainWindow::~MainWindow()
{
    delete gestorAuto;
    delete gestorCliente;
    delete gestorAlquiler;
    delete gestorMantenimiento;
    delete gestorProveedor;
    delete gestorAutoparte;
    delete gestorIncidente;
    delete ui;
}

void MainWindow::on_btnCerrar_clicked(){
    this->close();
}

void MainWindow::on_btnIngresar_clicked(){
    QString usuario = ui->txtUsuario->text().trimmed();
    QString password = ui->txtPassword->text();

    if (usuario.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, ingresá tu usuario y contraseña.");
        return;
    }
    AdminDAOImpl dao;
    if (dao.validarLogin(usuario, password)) {
        QMessageBox::information(this, "Éxito", "¡Bienvenido a AutoGest!");
        ui->stackedWidget->setCurrentIndex(1);
        ui->txtUsuario->clear();
        ui->txtPassword->clear();
    }else{
        QMessageBox::critical(this, "Error de Login", "Usuario o contraseña incorrectos.");
        ui->txtPassword->clear();
    }
}

//Eventos de Autos
void MainWindow::on_btnGuardarAuto_clicked() { gestorAuto->guardar(); }
void MainWindow::on_btnActualizarAuto_clicked() { gestorAuto->actualizar(); }
void MainWindow::on_btnEliminarAuto_clicked() { gestorAuto->eliminar(); }

//Eventos de Clientes
void MainWindow::on_btnGuardarCliente_clicked() { gestorCliente->guardar(); }
void MainWindow::on_btnActualizarCliente_clicked() { gestorCliente->actualizar(); }
void MainWindow::on_btnEliminarCliente_clicked() { gestorCliente->eliminar(); }

//Eventos de Alquiler
void MainWindow::on_btnGuardarAlquiler_clicked() { gestorAlquiler->guardar(); }
void MainWindow::on_btnActualizarAlquiler_clicked() { gestorAlquiler->actualizar(); }
void MainWindow::on_btnEliminarAlquiler_clicked() { gestorAlquiler->eliminar(); }

//Eventos de Mantenimiento
void MainWindow::on_btnGuardarMantenimiento_clicked() { gestorMantenimiento->guardar(); }
void MainWindow::on_btnActualizarMantenimiento_clicked() { gestorMantenimiento->actualizar(); }
void MainWindow::on_btnEliminarMantenimiento_clicked() { gestorMantenimiento->eliminar(); }

//Eventos de Proveedores
void MainWindow::on_btnGuardarProveedor_clicked() { gestorProveedor->guardar(); }
void MainWindow::on_btnActualizarProveedor_clicked() { gestorProveedor->actualizar(); }
void MainWindow::on_btnEliminarProveedor_clicked() { gestorProveedor->eliminar(); }

//Eventos de Autopartes
void MainWindow::on_btnGuardarAutoparte_clicked() { gestorAutoparte->guardar(); }
void MainWindow::on_btnActualizarAutoparte_clicked() { gestorAutoparte->actualizar(); }
void MainWindow::on_btnEliminarAutoparte_clicked() { gestorAutoparte->eliminar(); }

//Eventos de Incidentes
void MainWindow::on_btnGuardarIncidente_clicked() { gestorIncidente->guardar(); }
void MainWindow::on_btnActualizarIncidente_clicked() { gestorIncidente->actualizar(); }
void MainWindow::on_btnEliminarIncidente_clicked() { gestorIncidente->eliminar(); }