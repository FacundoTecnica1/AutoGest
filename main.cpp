#include <QApplication>
#include <QDebug>
#include "conexion.h"
#include "mainwindow.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Conexion con;

    if(con.conectar())
    {
        qDebug() << "Conectado correctamente a autogest";
        con.cerrar();
    }
    else
    {
        qDebug() << "No se pudo conectar";
    }

    MainWindow w;
    w.show();

    return a.exec();
}