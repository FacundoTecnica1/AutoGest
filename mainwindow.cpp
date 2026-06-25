#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "admindaoimpl.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Boton para cerrar la apliación
void MainWindow::on_btnCerrar_clicked(){
    //Cierra la app
    this->close();
}

//Boton de ingresar
void MainWindow::on_btnIngresar_clicked(){
    // Sacamos lo que escribió el usuario. El .trimmed() saca los espacios
    //Que ingreso el usuario
    QString usuario = ui->txtUsuario->text().trimmed();
    QString password = ui->txtPassword->text();

    //Si el usuario no escribio nada, damos un mensaje de advertencia
    if (usuario.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, ingresá tu usuario y contraseña.");
        return;
    }

    //Llamamos a la clase que creamos
    AdminDAOImpl dao;

    //Le pasamos el usuario y contraseña a la consulta SQL para ver si se encuentra en la bd
    if (dao.validarLogin(usuario, password)) {
        QMessageBox::information(this, "Éxito", "¡Bienvenido a AutoGest!");

        //El Stacked Widget tiene índice 0 (Login)
        //y pasamos al índice 1 para mostrar las demás partes del programa
        ui->stackedWidget->setCurrentIndex(1);

        //Limpiamos los campos por seguridad, así no queda la clave escrita de fondo
        ui->txtUsuario->clear();
        ui->txtPassword->clear();
    }else{

        QMessageBox::critical(this, "Error de Login", "Usuario o contraseña incorrectos.");

        //borramos la contraseña vieja para que no tenga que borrarla a mano
        ui->txtPassword->clear();
    }
}