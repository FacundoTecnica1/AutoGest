/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frameLogin;
    QGridLayout *gridLayout;
    QLabel *label_iniciarSesion;
    QLabel *label_Usuario;
    QLineEdit *txtUsuario;
    QLabel *label_Contrasena;
    QLineEdit *txtPassword;
    QPushButton *btnIngresar;
    QPushButton *btnCerrar;
    QWidget *page_2;
    QTabWidget *QTabWidget;
    QWidget *Autos;
    QLabel *label_marca;
    QLineEdit *txtMarca;
    QLabel *label_modelo;
    QLineEdit *txtModelo;
    QLineEdit *txtAnio;
    QLineEdit *txtPatente;
    QLabel *label_anio;
    QLabel *label_patente;
    QLabel *label_kilometraje;
    QLineEdit *txtKilometraje;
    QLineEdit *txtPrecioDia;
    QLabel *label_preciodia;
    QLabel *label_estado;
    QComboBox *comboBox_estado;
    QComboBox *comboBox_color;
    QLabel *label_color;
    QPushButton *btnGuardar_Autos;
    QPushButton *btnEliminar_Autos;
    QTableWidget *tableWidget_Autos;
    QLabel *label_ListaAutos;
    QLineEdit *txtBuscadorAutos;
    QLabel *label_buscadorAutos;
    QPushButton *btnActualizar_Autos;
    QWidget *Clientes;
    QLineEdit *txtTelefono;
    QLineEdit *txtDni;
    QLabel *label_ListaClientes;
    QTableWidget *tableWidget_Clientes;
    QComboBox *comboBox_ClaseLicencia;
    QLineEdit *txtDireccion;
    QLabel *label_direccion;
    QLabel *label_nombre;
    QPushButton *btnGuardar_Clientes;
    QLabel *label_email;
    QLabel *label_dni;
    QLabel *label_telefono;
    QLineEdit *txtApellido;
    QPushButton *btnEliminar_Clientes;
    QLineEdit *txtBuscadorClientes;
    QLabel *label_claseLicencia;
    QLineEdit *txtEmail;
    QLabel *label_buscadorClientes;
    QLabel *label_apellido;
    QPushButton *btnActualizar_Clientes;
    QLineEdit *txtNombre;
    QLineEdit *txtEdad;
    QLabel *label_edad;
    QWidget *Alquiler;
    QPushButton *btnEliminar_Alquiler;
    QLabel *label_metodoPago;
    QLabel *label_EstadoAlquiler;
    QLabel *label_fechaInicio;
    QLabel *label_FechaFin;
    QComboBox *comboBox_MetodoPago;
    QPushButton *btnGuardar_Alquiler;
    QLabel *label_ListaAlquileres;
    QTableWidget *tableWidget_Alquileres;
    QLabel *label_buscadorAlquileres;
    QLineEdit *txtBuscadorAlquileres;
    QPushButton *btnActualizar_Alquiler;
    QComboBox *comboBox_EstadoAlquiler;
    QLabel *label_precioTotal;
    QLabel *label_total;
    QDateEdit *dateEdit_FechaInicio;
    QDateEdit *dateEdit_FechaFin;
    QWidget *tab;
    QTableWidget *tableWidget_Incidentes;
    QLabel *label_buscadorIncidentes;
    QLabel *label_ListaIncidentes;
    QPushButton *btnEliminar_Incidente;
    QLabel *label_TipoIncidente;
    QPushButton *btnActualizar_Incidente;
    QLineEdit *txtBuscadorIncidentes;
    QLabel *label_FechaIncidente;
    QPushButton *btnGuardar_Incidente;
    QDateEdit *dateEdit_FechaIncidente;
    QLabel *label_Descripcion;
    QLineEdit *txtTipoIncidente;
    QLineEdit *txtDescripcion;
    QLineEdit *txtCosto;
    QLabel *label_Costo;
    QWidget *Mantenimientos;
    QTableWidget *tableWidget_Mantenimientos;
    QLabel *label_buscadorMantenimiento;
    QLabel *label_ListaMantenimientos;
    QDateEdit *dateEdit_FechaIngreso;
    QLabel *label_fechaIngreso;
    QPushButton *btnEliminarMantenimiento;
    QPushButton *btnActualizarMantenimiento;
    QLabel *label_ObservacionesMantenimiento;
    QLineEdit *txtBuscadorMantenimientos;
    QLabel *label_FechaSalida;
    QPushButton *btnGuardarMantenimiento;
    QDateEdit *dateEdit_FechaSalida;
    QLabel *label_TipoMantenimiento;
    QComboBox *comboBox_TipoMantenimiento;
    QLineEdit *txtObservaciones;
    QLabel *label_EstadoMantenimiento;
    QComboBox *comboBox_EstadoMantenimiento;
    QLabel *label_CostoMantenimiento;
    QLineEdit *txtCostoMantenimiento;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        frameLogin = new QFrame(page);
        frameLogin->setObjectName("frameLogin");
        frameLogin->setGeometry(QRect(300, 90, 176, 241));
        frameLogin->setFrameShape(QFrame::Shape::StyledPanel);
        frameLogin->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frameLogin);
        gridLayout->setObjectName("gridLayout");
        label_iniciarSesion = new QLabel(frameLogin);
        label_iniciarSesion->setObjectName("label_iniciarSesion");

        gridLayout->addWidget(label_iniciarSesion, 0, 0, 1, 2);

        label_Usuario = new QLabel(frameLogin);
        label_Usuario->setObjectName("label_Usuario");

        gridLayout->addWidget(label_Usuario, 1, 0, 1, 1);

        txtUsuario = new QLineEdit(frameLogin);
        txtUsuario->setObjectName("txtUsuario");
        txtUsuario->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout->addWidget(txtUsuario, 2, 0, 1, 2);

        label_Contrasena = new QLabel(frameLogin);
        label_Contrasena->setObjectName("label_Contrasena");

        gridLayout->addWidget(label_Contrasena, 3, 0, 1, 1);

        txtPassword = new QLineEdit(frameLogin);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout->addWidget(txtPassword, 4, 0, 1, 2);

        btnIngresar = new QPushButton(frameLogin);
        btnIngresar->setObjectName("btnIngresar");

        gridLayout->addWidget(btnIngresar, 5, 0, 1, 1);

        btnCerrar = new QPushButton(frameLogin);
        btnCerrar->setObjectName("btnCerrar");

        gridLayout->addWidget(btnCerrar, 5, 1, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        QTabWidget = new QTabWidget(page_2);
        QTabWidget->setObjectName("QTabWidget");
        QTabWidget->setGeometry(QRect(0, 0, 781, 581));
        Autos = new QWidget();
        Autos->setObjectName("Autos");
        label_marca = new QLabel(Autos);
        label_marca->setObjectName("label_marca");
        label_marca->setGeometry(QRect(20, 20, 75, 40));
        txtMarca = new QLineEdit(Autos);
        txtMarca->setObjectName("txtMarca");
        txtMarca->setGeometry(QRect(20, 60, 113, 24));
        label_modelo = new QLabel(Autos);
        label_modelo->setObjectName("label_modelo");
        label_modelo->setGeometry(QRect(150, 20, 75, 40));
        txtModelo = new QLineEdit(Autos);
        txtModelo->setObjectName("txtModelo");
        txtModelo->setGeometry(QRect(150, 60, 113, 24));
        txtAnio = new QLineEdit(Autos);
        txtAnio->setObjectName("txtAnio");
        txtAnio->setGeometry(QRect(150, 140, 113, 24));
        txtPatente = new QLineEdit(Autos);
        txtPatente->setObjectName("txtPatente");
        txtPatente->setGeometry(QRect(20, 140, 113, 24));
        label_anio = new QLabel(Autos);
        label_anio->setObjectName("label_anio");
        label_anio->setGeometry(QRect(150, 100, 75, 40));
        label_patente = new QLabel(Autos);
        label_patente->setObjectName("label_patente");
        label_patente->setGeometry(QRect(20, 100, 75, 40));
        label_kilometraje = new QLabel(Autos);
        label_kilometraje->setObjectName("label_kilometraje");
        label_kilometraje->setGeometry(QRect(20, 180, 75, 40));
        txtKilometraje = new QLineEdit(Autos);
        txtKilometraje->setObjectName("txtKilometraje");
        txtKilometraje->setGeometry(QRect(20, 220, 113, 24));
        txtPrecioDia = new QLineEdit(Autos);
        txtPrecioDia->setObjectName("txtPrecioDia");
        txtPrecioDia->setGeometry(QRect(150, 220, 113, 24));
        label_preciodia = new QLabel(Autos);
        label_preciodia->setObjectName("label_preciodia");
        label_preciodia->setGeometry(QRect(150, 180, 75, 40));
        label_estado = new QLabel(Autos);
        label_estado->setObjectName("label_estado");
        label_estado->setGeometry(QRect(20, 250, 75, 40));
        comboBox_estado = new QComboBox(Autos);
        comboBox_estado->addItem(QString());
        comboBox_estado->addItem(QString());
        comboBox_estado->addItem(QString());
        comboBox_estado->setObjectName("comboBox_estado");
        comboBox_estado->setGeometry(QRect(20, 280, 111, 24));
        comboBox_color = new QComboBox(Autos);
        comboBox_color->addItem(QString());
        comboBox_color->addItem(QString());
        comboBox_color->addItem(QString());
        comboBox_color->addItem(QString());
        comboBox_color->addItem(QString());
        comboBox_color->addItem(QString());
        comboBox_color->setObjectName("comboBox_color");
        comboBox_color->setGeometry(QRect(150, 280, 111, 24));
        label_color = new QLabel(Autos);
        label_color->setObjectName("label_color");
        label_color->setGeometry(QRect(150, 250, 75, 40));
        btnGuardar_Autos = new QPushButton(Autos);
        btnGuardar_Autos->setObjectName("btnGuardar_Autos");
        btnGuardar_Autos->setGeometry(QRect(20, 320, 80, 24));
        btnEliminar_Autos = new QPushButton(Autos);
        btnEliminar_Autos->setObjectName("btnEliminar_Autos");
        btnEliminar_Autos->setGeometry(QRect(160, 320, 80, 24));
        tableWidget_Autos = new QTableWidget(Autos);
        tableWidget_Autos->setObjectName("tableWidget_Autos");
        tableWidget_Autos->setGeometry(QRect(290, 100, 421, 401));
        label_ListaAutos = new QLabel(Autos);
        label_ListaAutos->setObjectName("label_ListaAutos");
        label_ListaAutos->setGeometry(QRect(440, 0, 121, 41));
        QFont font;
        font.setPointSize(14);
        label_ListaAutos->setFont(font);
        txtBuscadorAutos = new QLineEdit(Autos);
        txtBuscadorAutos->setObjectName("txtBuscadorAutos");
        txtBuscadorAutos->setGeometry(QRect(290, 60, 421, 24));
        label_buscadorAutos = new QLabel(Autos);
        label_buscadorAutos->setObjectName("label_buscadorAutos");
        label_buscadorAutos->setGeometry(QRect(290, 20, 75, 40));
        btnActualizar_Autos = new QPushButton(Autos);
        btnActualizar_Autos->setObjectName("btnActualizar_Autos");
        btnActualizar_Autos->setGeometry(QRect(90, 360, 80, 24));
        QTabWidget->addTab(Autos, QString());
        Clientes = new QWidget();
        Clientes->setObjectName("Clientes");
        txtTelefono = new QLineEdit(Clientes);
        txtTelefono->setObjectName("txtTelefono");
        txtTelefono->setGeometry(QRect(150, 280, 113, 24));
        txtDni = new QLineEdit(Clientes);
        txtDni->setObjectName("txtDni");
        txtDni->setGeometry(QRect(20, 140, 113, 24));
        label_ListaClientes = new QLabel(Clientes);
        label_ListaClientes->setObjectName("label_ListaClientes");
        label_ListaClientes->setGeometry(QRect(440, 0, 141, 41));
        label_ListaClientes->setFont(font);
        tableWidget_Clientes = new QTableWidget(Clientes);
        tableWidget_Clientes->setObjectName("tableWidget_Clientes");
        tableWidget_Clientes->setGeometry(QRect(290, 100, 421, 401));
        comboBox_ClaseLicencia = new QComboBox(Clientes);
        comboBox_ClaseLicencia->addItem(QString());
        comboBox_ClaseLicencia->addItem(QString());
        comboBox_ClaseLicencia->setObjectName("comboBox_ClaseLicencia");
        comboBox_ClaseLicencia->setGeometry(QRect(20, 280, 111, 24));
        txtDireccion = new QLineEdit(Clientes);
        txtDireccion->setObjectName("txtDireccion");
        txtDireccion->setGeometry(QRect(150, 220, 113, 24));
        label_direccion = new QLabel(Clientes);
        label_direccion->setObjectName("label_direccion");
        label_direccion->setGeometry(QRect(150, 180, 75, 40));
        label_nombre = new QLabel(Clientes);
        label_nombre->setObjectName("label_nombre");
        label_nombre->setGeometry(QRect(20, 20, 75, 40));
        btnGuardar_Clientes = new QPushButton(Clientes);
        btnGuardar_Clientes->setObjectName("btnGuardar_Clientes");
        btnGuardar_Clientes->setGeometry(QRect(20, 320, 80, 24));
        label_email = new QLabel(Clientes);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(20, 180, 75, 40));
        label_dni = new QLabel(Clientes);
        label_dni->setObjectName("label_dni");
        label_dni->setGeometry(QRect(20, 100, 75, 40));
        label_telefono = new QLabel(Clientes);
        label_telefono->setObjectName("label_telefono");
        label_telefono->setGeometry(QRect(150, 240, 75, 40));
        txtApellido = new QLineEdit(Clientes);
        txtApellido->setObjectName("txtApellido");
        txtApellido->setGeometry(QRect(150, 60, 113, 24));
        btnEliminar_Clientes = new QPushButton(Clientes);
        btnEliminar_Clientes->setObjectName("btnEliminar_Clientes");
        btnEliminar_Clientes->setGeometry(QRect(160, 320, 80, 24));
        txtBuscadorClientes = new QLineEdit(Clientes);
        txtBuscadorClientes->setObjectName("txtBuscadorClientes");
        txtBuscadorClientes->setGeometry(QRect(290, 60, 421, 24));
        label_claseLicencia = new QLabel(Clientes);
        label_claseLicencia->setObjectName("label_claseLicencia");
        label_claseLicencia->setGeometry(QRect(20, 250, 101, 40));
        txtEmail = new QLineEdit(Clientes);
        txtEmail->setObjectName("txtEmail");
        txtEmail->setGeometry(QRect(20, 220, 113, 24));
        label_buscadorClientes = new QLabel(Clientes);
        label_buscadorClientes->setObjectName("label_buscadorClientes");
        label_buscadorClientes->setGeometry(QRect(290, 20, 75, 40));
        label_apellido = new QLabel(Clientes);
        label_apellido->setObjectName("label_apellido");
        label_apellido->setGeometry(QRect(150, 20, 75, 40));
        btnActualizar_Clientes = new QPushButton(Clientes);
        btnActualizar_Clientes->setObjectName("btnActualizar_Clientes");
        btnActualizar_Clientes->setGeometry(QRect(90, 360, 80, 24));
        txtNombre = new QLineEdit(Clientes);
        txtNombre->setObjectName("txtNombre");
        txtNombre->setGeometry(QRect(20, 60, 113, 24));
        txtEdad = new QLineEdit(Clientes);
        txtEdad->setObjectName("txtEdad");
        txtEdad->setGeometry(QRect(150, 140, 113, 24));
        label_edad = new QLabel(Clientes);
        label_edad->setObjectName("label_edad");
        label_edad->setGeometry(QRect(150, 100, 75, 40));
        QTabWidget->addTab(Clientes, QString());
        Alquiler = new QWidget();
        Alquiler->setObjectName("Alquiler");
        btnEliminar_Alquiler = new QPushButton(Alquiler);
        btnEliminar_Alquiler->setObjectName("btnEliminar_Alquiler");
        btnEliminar_Alquiler->setGeometry(QRect(170, 270, 80, 24));
        label_metodoPago = new QLabel(Alquiler);
        label_metodoPago->setObjectName("label_metodoPago");
        label_metodoPago->setGeometry(QRect(20, 100, 101, 40));
        label_EstadoAlquiler = new QLabel(Alquiler);
        label_EstadoAlquiler->setObjectName("label_EstadoAlquiler");
        label_EstadoAlquiler->setGeometry(QRect(140, 100, 111, 40));
        label_fechaInicio = new QLabel(Alquiler);
        label_fechaInicio->setObjectName("label_fechaInicio");
        label_fechaInicio->setGeometry(QRect(20, 20, 75, 40));
        label_FechaFin = new QLabel(Alquiler);
        label_FechaFin->setObjectName("label_FechaFin");
        label_FechaFin->setGeometry(QRect(140, 20, 75, 40));
        comboBox_MetodoPago = new QComboBox(Alquiler);
        comboBox_MetodoPago->addItem(QString());
        comboBox_MetodoPago->addItem(QString());
        comboBox_MetodoPago->addItem(QString());
        comboBox_MetodoPago->addItem(QString());
        comboBox_MetodoPago->setObjectName("comboBox_MetodoPago");
        comboBox_MetodoPago->setGeometry(QRect(20, 140, 111, 24));
        btnGuardar_Alquiler = new QPushButton(Alquiler);
        btnGuardar_Alquiler->setObjectName("btnGuardar_Alquiler");
        btnGuardar_Alquiler->setGeometry(QRect(30, 270, 80, 24));
        label_ListaAlquileres = new QLabel(Alquiler);
        label_ListaAlquileres->setObjectName("label_ListaAlquileres");
        label_ListaAlquileres->setGeometry(QRect(440, 0, 161, 41));
        label_ListaAlquileres->setFont(font);
        tableWidget_Alquileres = new QTableWidget(Alquiler);
        tableWidget_Alquileres->setObjectName("tableWidget_Alquileres");
        tableWidget_Alquileres->setGeometry(QRect(290, 100, 421, 401));
        label_buscadorAlquileres = new QLabel(Alquiler);
        label_buscadorAlquileres->setObjectName("label_buscadorAlquileres");
        label_buscadorAlquileres->setGeometry(QRect(290, 20, 75, 40));
        txtBuscadorAlquileres = new QLineEdit(Alquiler);
        txtBuscadorAlquileres->setObjectName("txtBuscadorAlquileres");
        txtBuscadorAlquileres->setGeometry(QRect(290, 60, 421, 24));
        btnActualizar_Alquiler = new QPushButton(Alquiler);
        btnActualizar_Alquiler->setObjectName("btnActualizar_Alquiler");
        btnActualizar_Alquiler->setGeometry(QRect(100, 310, 80, 24));
        comboBox_EstadoAlquiler = new QComboBox(Alquiler);
        comboBox_EstadoAlquiler->addItem(QString());
        comboBox_EstadoAlquiler->addItem(QString());
        comboBox_EstadoAlquiler->addItem(QString());
        comboBox_EstadoAlquiler->setObjectName("comboBox_EstadoAlquiler");
        comboBox_EstadoAlquiler->setGeometry(QRect(140, 140, 111, 24));
        label_precioTotal = new QLabel(Alquiler);
        label_precioTotal->setObjectName("label_precioTotal");
        label_precioTotal->setGeometry(QRect(100, 180, 111, 40));
        label_total = new QLabel(Alquiler);
        label_total->setObjectName("label_total");
        label_total->setGeometry(QRect(110, 210, 41, 40));
        QFont font1;
        font1.setPointSize(10);
        font1.setUnderline(true);
        label_total->setFont(font1);
        dateEdit_FechaInicio = new QDateEdit(Alquiler);
        dateEdit_FechaInicio->setObjectName("dateEdit_FechaInicio");
        dateEdit_FechaInicio->setGeometry(QRect(20, 60, 110, 25));
        dateEdit_FechaFin = new QDateEdit(Alquiler);
        dateEdit_FechaFin->setObjectName("dateEdit_FechaFin");
        dateEdit_FechaFin->setGeometry(QRect(140, 60, 110, 25));
        QTabWidget->addTab(Alquiler, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tableWidget_Incidentes = new QTableWidget(tab);
        tableWidget_Incidentes->setObjectName("tableWidget_Incidentes");
        tableWidget_Incidentes->setGeometry(QRect(290, 100, 421, 401));
        label_buscadorIncidentes = new QLabel(tab);
        label_buscadorIncidentes->setObjectName("label_buscadorIncidentes");
        label_buscadorIncidentes->setGeometry(QRect(290, 20, 75, 40));
        label_ListaIncidentes = new QLabel(tab);
        label_ListaIncidentes->setObjectName("label_ListaIncidentes");
        label_ListaIncidentes->setGeometry(QRect(440, 0, 161, 41));
        label_ListaIncidentes->setFont(font);
        btnEliminar_Incidente = new QPushButton(tab);
        btnEliminar_Incidente->setObjectName("btnEliminar_Incidente");
        btnEliminar_Incidente->setGeometry(QRect(170, 190, 80, 24));
        label_TipoIncidente = new QLabel(tab);
        label_TipoIncidente->setObjectName("label_TipoIncidente");
        label_TipoIncidente->setGeometry(QRect(20, 20, 101, 40));
        btnActualizar_Incidente = new QPushButton(tab);
        btnActualizar_Incidente->setObjectName("btnActualizar_Incidente");
        btnActualizar_Incidente->setGeometry(QRect(100, 230, 80, 24));
        txtBuscadorIncidentes = new QLineEdit(tab);
        txtBuscadorIncidentes->setObjectName("txtBuscadorIncidentes");
        txtBuscadorIncidentes->setGeometry(QRect(290, 60, 421, 24));
        label_FechaIncidente = new QLabel(tab);
        label_FechaIncidente->setObjectName("label_FechaIncidente");
        label_FechaIncidente->setGeometry(QRect(140, 20, 91, 40));
        btnGuardar_Incidente = new QPushButton(tab);
        btnGuardar_Incidente->setObjectName("btnGuardar_Incidente");
        btnGuardar_Incidente->setGeometry(QRect(30, 190, 80, 24));
        dateEdit_FechaIncidente = new QDateEdit(tab);
        dateEdit_FechaIncidente->setObjectName("dateEdit_FechaIncidente");
        dateEdit_FechaIncidente->setGeometry(QRect(140, 60, 110, 25));
        label_Descripcion = new QLabel(tab);
        label_Descripcion->setObjectName("label_Descripcion");
        label_Descripcion->setGeometry(QRect(20, 100, 101, 40));
        txtTipoIncidente = new QLineEdit(tab);
        txtTipoIncidente->setObjectName("txtTipoIncidente");
        txtTipoIncidente->setGeometry(QRect(20, 60, 113, 24));
        txtDescripcion = new QLineEdit(tab);
        txtDescripcion->setObjectName("txtDescripcion");
        txtDescripcion->setGeometry(QRect(20, 140, 113, 24));
        txtCosto = new QLineEdit(tab);
        txtCosto->setObjectName("txtCosto");
        txtCosto->setGeometry(QRect(150, 140, 113, 24));
        label_Costo = new QLabel(tab);
        label_Costo->setObjectName("label_Costo");
        label_Costo->setGeometry(QRect(150, 100, 101, 40));
        QTabWidget->addTab(tab, QString());
        Mantenimientos = new QWidget();
        Mantenimientos->setObjectName("Mantenimientos");
        tableWidget_Mantenimientos = new QTableWidget(Mantenimientos);
        tableWidget_Mantenimientos->setObjectName("tableWidget_Mantenimientos");
        tableWidget_Mantenimientos->setGeometry(QRect(290, 100, 421, 321));
        label_buscadorMantenimiento = new QLabel(Mantenimientos);
        label_buscadorMantenimiento->setObjectName("label_buscadorMantenimiento");
        label_buscadorMantenimiento->setGeometry(QRect(290, 20, 75, 40));
        label_ListaMantenimientos = new QLabel(Mantenimientos);
        label_ListaMantenimientos->setObjectName("label_ListaMantenimientos");
        label_ListaMantenimientos->setGeometry(QRect(410, 0, 211, 41));
        label_ListaMantenimientos->setFont(font);
        dateEdit_FechaIngreso = new QDateEdit(Mantenimientos);
        dateEdit_FechaIngreso->setObjectName("dateEdit_FechaIngreso");
        dateEdit_FechaIngreso->setGeometry(QRect(20, 60, 110, 25));
        label_fechaIngreso = new QLabel(Mantenimientos);
        label_fechaIngreso->setObjectName("label_fechaIngreso");
        label_fechaIngreso->setGeometry(QRect(20, 20, 81, 40));
        btnEliminarMantenimiento = new QPushButton(Mantenimientos);
        btnEliminarMantenimiento->setObjectName("btnEliminarMantenimiento");
        btnEliminarMantenimiento->setGeometry(QRect(160, 270, 80, 24));
        btnActualizarMantenimiento = new QPushButton(Mantenimientos);
        btnActualizarMantenimiento->setObjectName("btnActualizarMantenimiento");
        btnActualizarMantenimiento->setGeometry(QRect(90, 310, 80, 24));
        label_ObservacionesMantenimiento = new QLabel(Mantenimientos);
        label_ObservacionesMantenimiento->setObjectName("label_ObservacionesMantenimiento");
        label_ObservacionesMantenimiento->setGeometry(QRect(150, 100, 111, 40));
        txtBuscadorMantenimientos = new QLineEdit(Mantenimientos);
        txtBuscadorMantenimientos->setObjectName("txtBuscadorMantenimientos");
        txtBuscadorMantenimientos->setGeometry(QRect(290, 60, 421, 24));
        label_FechaSalida = new QLabel(Mantenimientos);
        label_FechaSalida->setObjectName("label_FechaSalida");
        label_FechaSalida->setGeometry(QRect(150, 20, 75, 40));
        btnGuardarMantenimiento = new QPushButton(Mantenimientos);
        btnGuardarMantenimiento->setObjectName("btnGuardarMantenimiento");
        btnGuardarMantenimiento->setGeometry(QRect(20, 270, 80, 24));
        dateEdit_FechaSalida = new QDateEdit(Mantenimientos);
        dateEdit_FechaSalida->setObjectName("dateEdit_FechaSalida");
        dateEdit_FechaSalida->setGeometry(QRect(150, 60, 110, 25));
        label_TipoMantenimiento = new QLabel(Mantenimientos);
        label_TipoMantenimiento->setObjectName("label_TipoMantenimiento");
        label_TipoMantenimiento->setGeometry(QRect(20, 100, 121, 40));
        comboBox_TipoMantenimiento = new QComboBox(Mantenimientos);
        comboBox_TipoMantenimiento->setObjectName("comboBox_TipoMantenimiento");
        comboBox_TipoMantenimiento->setGeometry(QRect(20, 140, 111, 24));
        txtObservaciones = new QLineEdit(Mantenimientos);
        txtObservaciones->setObjectName("txtObservaciones");
        txtObservaciones->setGeometry(QRect(150, 140, 113, 24));
        label_EstadoMantenimiento = new QLabel(Mantenimientos);
        label_EstadoMantenimiento->setObjectName("label_EstadoMantenimiento");
        label_EstadoMantenimiento->setGeometry(QRect(20, 170, 121, 40));
        comboBox_EstadoMantenimiento = new QComboBox(Mantenimientos);
        comboBox_EstadoMantenimiento->addItem(QString());
        comboBox_EstadoMantenimiento->addItem(QString());
        comboBox_EstadoMantenimiento->setObjectName("comboBox_EstadoMantenimiento");
        comboBox_EstadoMantenimiento->setGeometry(QRect(20, 210, 111, 24));
        label_CostoMantenimiento = new QLabel(Mantenimientos);
        label_CostoMantenimiento->setObjectName("label_CostoMantenimiento");
        label_CostoMantenimiento->setGeometry(QRect(150, 170, 111, 40));
        txtCostoMantenimiento = new QLineEdit(Mantenimientos);
        txtCostoMantenimiento->setObjectName("txtCostoMantenimiento");
        txtCostoMantenimiento->setGeometry(QRect(150, 210, 113, 24));
        QTabWidget->addTab(Mantenimientos, QString());
        stackedWidget->addWidget(page_2);

        horizontalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QTabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_iniciarSesion->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesi\303\263n", nullptr));
        label_Usuario->setText(QCoreApplication::translate("MainWindow", "Usuario:", nullptr));
        label_Contrasena->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        btnIngresar->setText(QCoreApplication::translate("MainWindow", "Ingresar", nullptr));
        btnCerrar->setText(QCoreApplication::translate("MainWindow", "Cerrar", nullptr));
        label_marca->setText(QCoreApplication::translate("MainWindow", "Marca:", nullptr));
        label_modelo->setText(QCoreApplication::translate("MainWindow", "Modelo:", nullptr));
        label_anio->setText(QCoreApplication::translate("MainWindow", "A\303\261o:", nullptr));
        label_patente->setText(QCoreApplication::translate("MainWindow", "Patente:", nullptr));
        label_kilometraje->setText(QCoreApplication::translate("MainWindow", "Kilometraje:", nullptr));
        label_preciodia->setText(QCoreApplication::translate("MainWindow", "Precio por d\303\255a:", nullptr));
        label_estado->setText(QCoreApplication::translate("MainWindow", "Estado:", nullptr));
        comboBox_estado->setItemText(0, QCoreApplication::translate("MainWindow", "Disponible", nullptr));
        comboBox_estado->setItemText(1, QCoreApplication::translate("MainWindow", "Alquilado", nullptr));
        comboBox_estado->setItemText(2, QCoreApplication::translate("MainWindow", "En mantenimiento", nullptr));

        comboBox_color->setItemText(0, QCoreApplication::translate("MainWindow", "Negro", nullptr));
        comboBox_color->setItemText(1, QCoreApplication::translate("MainWindow", "Azul", nullptr));
        comboBox_color->setItemText(2, QCoreApplication::translate("MainWindow", "Naranja", nullptr));
        comboBox_color->setItemText(3, QCoreApplication::translate("MainWindow", "Rojo", nullptr));
        comboBox_color->setItemText(4, QCoreApplication::translate("MainWindow", "Blanco", nullptr));
        comboBox_color->setItemText(5, QCoreApplication::translate("MainWindow", "Gris", nullptr));

        label_color->setText(QCoreApplication::translate("MainWindow", "Color:", nullptr));
        btnGuardar_Autos->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        btnEliminar_Autos->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        label_ListaAutos->setText(QCoreApplication::translate("MainWindow", "Lista de autos", nullptr));
        txtBuscadorAutos->setPlaceholderText(QCoreApplication::translate("MainWindow", "Buscar por patente, color, a\303\261o, modelo, etc", nullptr));
        label_buscadorAutos->setText(QCoreApplication::translate("MainWindow", "Buscador:", nullptr));
        btnActualizar_Autos->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        QTabWidget->setTabText(QTabWidget->indexOf(Autos), QCoreApplication::translate("MainWindow", "Autos", nullptr));
        label_ListaClientes->setText(QCoreApplication::translate("MainWindow", "Lista de Clientes", nullptr));
        comboBox_ClaseLicencia->setItemText(0, QCoreApplication::translate("MainWindow", "B1", nullptr));
        comboBox_ClaseLicencia->setItemText(1, QCoreApplication::translate("MainWindow", "B2", nullptr));

        label_direccion->setText(QCoreApplication::translate("MainWindow", "Direcci\303\263n:", nullptr));
        label_nombre->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        btnGuardar_Clientes->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        label_email->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        label_dni->setText(QCoreApplication::translate("MainWindow", "Dni:", nullptr));
        label_telefono->setText(QCoreApplication::translate("MainWindow", "Telefono:", nullptr));
        btnEliminar_Clientes->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        txtBuscadorClientes->setPlaceholderText(QCoreApplication::translate("MainWindow", "Buscar por nombre, apellido, dni, telefono, email, etc", nullptr));
        label_claseLicencia->setText(QCoreApplication::translate("MainWindow", "Clase de licencia:", nullptr));
        label_buscadorClientes->setText(QCoreApplication::translate("MainWindow", "Buscador:", nullptr));
        label_apellido->setText(QCoreApplication::translate("MainWindow", "Apellido:", nullptr));
        btnActualizar_Clientes->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        label_edad->setText(QCoreApplication::translate("MainWindow", "Edad:", nullptr));
        QTabWidget->setTabText(QTabWidget->indexOf(Clientes), QCoreApplication::translate("MainWindow", "Clientes", nullptr));
        btnEliminar_Alquiler->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        label_metodoPago->setText(QCoreApplication::translate("MainWindow", "Metodo de pago:", nullptr));
        label_EstadoAlquiler->setText(QCoreApplication::translate("MainWindow", "Estado de alquiler:", nullptr));
        label_fechaInicio->setText(QCoreApplication::translate("MainWindow", "Fecha inicio:", nullptr));
        label_FechaFin->setText(QCoreApplication::translate("MainWindow", "Fecha Fin:", nullptr));
        comboBox_MetodoPago->setItemText(0, QCoreApplication::translate("MainWindow", "Efectivo", nullptr));
        comboBox_MetodoPago->setItemText(1, QCoreApplication::translate("MainWindow", "Debito", nullptr));
        comboBox_MetodoPago->setItemText(2, QCoreApplication::translate("MainWindow", "Transferencia", nullptr));
        comboBox_MetodoPago->setItemText(3, QCoreApplication::translate("MainWindow", "Credito", nullptr));

        btnGuardar_Alquiler->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        label_ListaAlquileres->setText(QCoreApplication::translate("MainWindow", "Lista de Alquileres", nullptr));
        label_buscadorAlquileres->setText(QCoreApplication::translate("MainWindow", "Buscador:", nullptr));
        txtBuscadorAlquileres->setPlaceholderText(QCoreApplication::translate("MainWindow", "Buscar por nombre, apellido, dni, telefono, email, etc", nullptr));
        btnActualizar_Alquiler->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        comboBox_EstadoAlquiler->setItemText(0, QCoreApplication::translate("MainWindow", "Activo", nullptr));
        comboBox_EstadoAlquiler->setItemText(1, QCoreApplication::translate("MainWindow", "Cancelado", nullptr));
        comboBox_EstadoAlquiler->setItemText(2, QCoreApplication::translate("MainWindow", "Finalizado", nullptr));

        label_precioTotal->setText(QCoreApplication::translate("MainWindow", "Precio total:", nullptr));
        label_total->setText(QCoreApplication::translate("MainWindow", "$ 0.00", nullptr));
        QTabWidget->setTabText(QTabWidget->indexOf(Alquiler), QCoreApplication::translate("MainWindow", "Page", nullptr));
        label_buscadorIncidentes->setText(QCoreApplication::translate("MainWindow", "Buscador:", nullptr));
        label_ListaIncidentes->setText(QCoreApplication::translate("MainWindow", "Lista de Incidentes", nullptr));
        btnEliminar_Incidente->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        label_TipoIncidente->setText(QCoreApplication::translate("MainWindow", "Tipo de incidente:", nullptr));
        btnActualizar_Incidente->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        txtBuscadorIncidentes->setPlaceholderText(QCoreApplication::translate("MainWindow", "Buscar por nombre, apellido, dni, telefono, email, etc", nullptr));
        label_FechaIncidente->setText(QCoreApplication::translate("MainWindow", "Fecha Incidente:", nullptr));
        btnGuardar_Incidente->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        label_Descripcion->setText(QCoreApplication::translate("MainWindow", "Descripci\303\263n:", nullptr));
        label_Costo->setText(QCoreApplication::translate("MainWindow", "Costo:", nullptr));
        QTabWidget->setTabText(QTabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Page", nullptr));
        label_buscadorMantenimiento->setText(QCoreApplication::translate("MainWindow", "Buscador:", nullptr));
        label_ListaMantenimientos->setText(QCoreApplication::translate("MainWindow", "Lista de Mantenimientos", nullptr));
        label_fechaIngreso->setText(QCoreApplication::translate("MainWindow", "Fecha ingreso:", nullptr));
        btnEliminarMantenimiento->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnActualizarMantenimiento->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        label_ObservacionesMantenimiento->setText(QCoreApplication::translate("MainWindow", "Observaciones:", nullptr));
        txtBuscadorMantenimientos->setPlaceholderText(QCoreApplication::translate("MainWindow", "Buscar por nombre, apellido, dni, telefono, email, etc", nullptr));
        label_FechaSalida->setText(QCoreApplication::translate("MainWindow", "Fecha Salida:", nullptr));
        btnGuardarMantenimiento->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        label_TipoMantenimiento->setText(QCoreApplication::translate("MainWindow", "Tipo_mantenimiento:", nullptr));
        label_EstadoMantenimiento->setText(QCoreApplication::translate("MainWindow", "Estado:", nullptr));
        comboBox_EstadoMantenimiento->setItemText(0, QCoreApplication::translate("MainWindow", "Iniciado", nullptr));
        comboBox_EstadoMantenimiento->setItemText(1, QCoreApplication::translate("MainWindow", "Finalizado", nullptr));

        label_CostoMantenimiento->setText(QCoreApplication::translate("MainWindow", "Costo:", nullptr));
        QTabWidget->setTabText(QTabWidget->indexOf(Mantenimientos), QCoreApplication::translate("MainWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
