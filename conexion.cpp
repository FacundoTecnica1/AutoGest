#include "conexion.h"
#include <QSqlError>
#include <QDebug>

Conexion::Conexion(){
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Conexion::conectar(){

    db.setDatabaseName(
        "Driver={MySQL ODBC 9.7 Unicode Driver};"
        "Server=127.0.0.1;"
        "Database=autogest;"
        "User=root;"
        "Password=;"
        );

    if (!db.open()){
        qDebug() << "Error al conectar:";
        qDebug() << db.lastError().text();
        return false;
    }

    qDebug() << "Conexion exitosa a autogest via ODBC!";
    return true;
}

QSqlDatabase Conexion::getDB(){
    return db;
}

void Conexion::cerrar()
{
    if (db.isOpen()){
        db.close();
    }
}