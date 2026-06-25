#include <QApplication>
#include <QDebug>
#include "conexion.h"
#include "mainwindow.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Conexion con;

    // Intentamos conectar a la base de datos antes de mostrar la app
    if(con.conectar())
    {
        qDebug() << "Conectado correctamente a autogest";
        // NO cerramos la conexión acá, la dejamos abierta para que la use el Login
    }
    else
    {
        qDebug() << "No se pudo conectar a la base de datos. El programa podría fallar.";
    }

    MainWindow w;
    w.show();

    return a.exec();
}