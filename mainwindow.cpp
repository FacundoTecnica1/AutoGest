#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "admindaoimpl.h"
#include <QMessageBox>
#include <QVector>

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

    //creamos gestores modulares que controlan cada pantalla
    //cada gestor recibe la ui para poder actualizar la vista
    gestorAuto = new GestorAuto(ui, this);
    gestorCliente = new GestorCliente(ui, this);
    gestorAlquiler = new GestorAlquiler(ui, this);
    gestorMantenimiento = new GestorMantenimiento(ui, this);
    gestorProveedor = new GestorProveedor(ui, this);
    gestorAutoparte = new GestorAutoparte(ui, this);
    gestorIncidente = new GestorIncidente(ui, this);

    //cargamos los datos iniciales en las tablas y comboboxes
    gestorAuto->listar();
    gestorCliente->listar();
    gestorAlquiler->cargarListasCombo();
    gestorAlquiler->listar();
    gestorMantenimiento->cargarListasCombo();
    gestorMantenimiento->listar();
    gestorProveedor->listar();
    gestorAutoparte->listar();
    gestorIncidente->cargarListasCombo();
    gestorIncidente->listar();

    //conexiones automaticas para recalcular el total de alquiler cuando cambian fechas o auto
    connect(ui->dteFechaInicioAlquiler, &QDateEdit::dateChanged, gestorAlquiler, &GestorAlquiler::calcularTotal);
    connect(ui->dteFechaFinAlquiler, &QDateEdit::dateChanged, gestorAlquiler, &GestorAlquiler::calcularTotal);
    connect(ui->cmbAutoAlquiler, &QComboBox::currentIndexChanged, gestorAlquiler, &GestorAlquiler::calcularTotal);


    //los buscadores filtran cada tabla en vivo mientras se escribe
    connect(ui->txtBuscadorAuto, &QLineEdit::textChanged, gestorAuto, &GestorAuto::buscar);
    connect(ui->txtBuscadorCliente, &QLineEdit::textChanged, gestorCliente, &GestorCliente::buscar);
    connect(ui->txtBuscadorAlquiler, &QLineEdit::textChanged, gestorAlquiler, &GestorAlquiler::buscar);
    connect(ui->txtBuscadorMantenimiento, &QLineEdit::textChanged, gestorMantenimiento, &GestorMantenimiento::buscar);
    connect(ui->txtBuscadorProveedor, &QLineEdit::textChanged, gestorProveedor, &GestorProveedor::buscar);
    connect(ui->txtBuscadorAutoparte, &QLineEdit::textChanged, gestorAutoparte, &GestorAutoparte::buscar);
    connect(ui->txtBuscadorIncidente, &QLineEdit::textChanged, gestorIncidente, &GestorIncidente::buscar);

    //cuando el usuario selecciona una fila en una tabla
    //los datos se vuelcan en el formulario correspondiente
    connect(ui->tblAutos, &QTableWidget::itemSelectionChanged, gestorAuto, &GestorAuto::cargarDatos);
    connect(ui->tblClientes, &QTableWidget::itemSelectionChanged, gestorCliente, &GestorCliente::cargarDatos);
    connect(ui->tblAlquileres, &QTableWidget::itemSelectionChanged, gestorAlquiler, &GestorAlquiler::cargarDatos);
    connect(ui->tblMantenimientos, &QTableWidget::itemSelectionChanged, gestorMantenimiento, &GestorMantenimiento::cargarDatos);
    connect(ui->tblProveedores, &QTableWidget::itemSelectionChanged, gestorProveedor, &GestorProveedor::cargarDatos);
    connect(ui->tblAutopartes, &QTableWidget::itemSelectionChanged, gestorAutoparte, &GestorAutoparte::cargarDatos);
    connect(ui->tblIncidentes, &QTableWidget::itemSelectionChanged, gestorIncidente, &GestorIncidente::cargarDatos);

    aplicarPermisosPorRol();

}

MainWindow::~MainWindow()
{
    //liberamos todos los gestores y la ui cuando se cierra la ventana
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
    //cierra la aplicacion desde el boton cerrar
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
    QString rol;
    //validamos credenciales y recibimos el rol para uso posterior
    if (dao.validarLogin(usuario, password, rol)) {
        currentUserRole = rol.trimmed(); //guardamos el rol para aplicar restricciones luego
        QMessageBox::information(this, "Éxito", "¡Bienvenido a AutoGest!");
        //al iniciar sesion mostramos la pantalla principal
        ui->stackedWidget->setCurrentIndex(1);
        aplicarPermisosPorRol();
        ui->txtUsuario->clear();
        ui->txtPassword->clear();
    } else {
        QMessageBox::critical(this, "Error de Login", "Usuario o contraseña incorrectos.");
        ui->txtPassword->clear();
    }
}

void MainWindow::aplicarPermisosPorRol() {
    const QString rol = currentUserRole.trimmed();
    const bool esAdmin = rol.compare("Admin", Qt::CaseInsensitive) == 0;
    const bool esMostrador = rol.compare("Mostrador", Qt::CaseInsensitive) == 0;
    const bool esMecanico = rol.compare("Mecánico", Qt::CaseInsensitive) == 0 || rol.compare("Mecanico", Qt::CaseInsensitive) == 0;
    const bool esCompras = rol.compare("Compras", Qt::CaseInsensitive) == 0;

    //por defecto se muestran todos los módulos; si hay un rol concreto, se ocultan los no permitidos
    const QVector<int> indicesPermitidos = esAdmin ? QVector<int>({0, 1, 2, 3, 4, 5, 6})
                                          : esMostrador ? QVector<int>({0, 1, 2})
                                          : esMecanico ? QVector<int>({0, 4})
                                          : esCompras ? QVector<int>({5, 6})
                                          : QVector<int>({0, 1, 2, 3, 4, 5, 6});

    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        const bool visible = indicesPermitidos.contains(i);
        ui->tabWidget->setTabVisible(i, visible);
    }

    if (ui->tabWidget->currentIndex() < 0 || !ui->tabWidget->isTabVisible(ui->tabWidget->currentIndex())) {
        for (int i = 0; i < ui->tabWidget->count(); ++i) {
            if (ui->tabWidget->isTabVisible(i)) {
                ui->tabWidget->setCurrentIndex(i);
                break;
            }
        }
    }
}

void MainWindow::cerrarSesion() {
    currentUserRole.clear();
    ui->stackedWidget->setCurrentIndex(0);
    ui->txtUsuario->clear();
    ui->txtPassword->clear();
    aplicarPermisosPorRol();
    ui->txtUsuario->setFocus();
}

void MainWindow::on_btnVolverLoginAutos_clicked() { cerrarSesion(); }
void MainWindow::on_btnVolverLoginClientes_clicked() { cerrarSesion(); }
void MainWindow::on_btnVolverLoginAlquileres_clicked() { cerrarSesion(); }
void MainWindow::on_btnVolverLoginIncidentes_clicked() { cerrarSesion(); }
void MainWindow::on_btnVolverLoginMantenimientos_clicked() { cerrarSesion(); }
void MainWindow::on_btnVolverLoginAutopartes_clicked() { cerrarSesion(); }
void MainWindow::on_btnVolverLoginProveedores_clicked() { cerrarSesion(); }

//Eventos de Autos
//los botones de autos llaman al gestor y actualizan los combos afectados
void MainWindow::on_btnGuardarAuto_clicked() {
    gestorAuto->guardar();
    gestorAuto->listar();
    gestorAlquiler->cargarListasCombo();
    gestorMantenimiento->cargarListasCombo();
    gestorIncidente->cargarListasCombo();
}
void MainWindow::on_btnActualizarAuto_clicked() {
    gestorAuto->actualizar();
    gestorAuto->listar();
    gestorAlquiler->cargarListasCombo();
    gestorMantenimiento->cargarListasCombo();
    gestorIncidente->cargarListasCombo();
}
void MainWindow::on_btnEliminarAuto_clicked() {
    gestorAuto->eliminar();
    gestorAuto->listar();
    gestorAlquiler->cargarListasCombo();
    gestorMantenimiento->cargarListasCombo();
    gestorIncidente->cargarListasCombo();
}

//Eventos de Clientes
void MainWindow::on_btnGuardarCliente_clicked() {
    gestorCliente->guardar();
    gestorCliente->listar();
    gestorAlquiler->cargarListasCombo();
    gestorIncidente->cargarListasCombo();
}

void MainWindow::on_btnActualizarCliente_clicked() {
    gestorCliente->actualizar();
    gestorCliente->listar();
    gestorAlquiler->cargarListasCombo();
    gestorIncidente->cargarListasCombo();
}

void MainWindow::on_btnEliminarCliente_clicked() {
    gestorCliente->eliminar();
    gestorCliente->listar();
    gestorAlquiler->cargarListasCombo();
    gestorIncidente->cargarListasCombo();
}

//Eventos de Alquiler
void MainWindow::on_btnGuardarAlquiler_clicked() {
    gestorAlquiler->guardar();
    gestorAlquiler->listar();
    gestorAlquiler->cargarListasCombo();
    gestorAuto->listar();
    gestorMantenimiento->cargarListasCombo();
}

void MainWindow::on_btnActualizarAlquiler_clicked() {
    gestorAlquiler->actualizar();
    gestorAlquiler->listar();
    gestorAlquiler->cargarListasCombo();
    gestorAuto->listar();
    gestorMantenimiento->cargarListasCombo();
}

void MainWindow::on_btnEliminarAlquiler_clicked() {
    gestorAlquiler->eliminar();
    gestorAlquiler->listar();
    gestorAlquiler->cargarListasCombo();
    gestorAuto->listar();
    gestorMantenimiento->cargarListasCombo();
}

//Eventos de Mantenimiento
void MainWindow::on_btnGuardarMantenimiento_clicked() {
    gestorMantenimiento->guardar();
    gestorMantenimiento->listar();
    gestorMantenimiento->cargarListasCombo();
    gestorAlquiler->cargarListasCombo();
    gestorAuto->listar();
}

void MainWindow::on_btnActualizarMantenimiento_clicked() {
    gestorMantenimiento->actualizar();
    gestorMantenimiento->listar();
    gestorMantenimiento->cargarListasCombo();
    gestorAlquiler->cargarListasCombo();
    gestorAuto->listar();
}

void MainWindow::on_btnEliminarMantenimiento_clicked() {
    gestorMantenimiento->eliminar();
    gestorMantenimiento->listar();
    gestorMantenimiento->cargarListasCombo();
    gestorAlquiler->cargarListasCombo();
    gestorAuto->listar();
}

//Eventos de Proveedores
void MainWindow::on_btnGuardarProveedor_clicked() {
    gestorProveedor->guardar();
}

void MainWindow::on_btnActualizarProveedor_clicked() {
    gestorProveedor->actualizar();
}

void MainWindow::on_btnEliminarProveedor_clicked() {
    gestorProveedor->eliminar();
}

//Eventos de Autopartes
void MainWindow::on_btnGuardarAutoparte_clicked() {
    gestorAutoparte->guardar();
}

void MainWindow::on_btnActualizarAutoparte_clicked() {
    gestorAutoparte->actualizar();
}

void MainWindow::on_btnEliminarAutoparte_clicked() {
    gestorAutoparte->eliminar();
}

//Eventos de Incidentes
void MainWindow::on_btnGuardarIncidente_clicked() {
    gestorIncidente->guardar();
    gestorAlquiler->listar();
}

void MainWindow::on_btnActualizarIncidente_clicked() {
    gestorIncidente->actualizar();
    gestorAlquiler->listar();
}

void MainWindow::on_btnEliminarIncidente_clicked() {
    gestorIncidente->eliminar();
}
