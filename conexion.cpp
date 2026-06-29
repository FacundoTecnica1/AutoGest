#include "conexion.h"
#include <QSqlError>
#include <QDebug>

Conexion::Conexion(){
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Conexion::conectar(){

    db.setDatabaseName(
        "Driver={MySQL ODBC 9.7 Unicode Driver};"
        "Server=5.180.151.26;"
        "Database=autogest_noriega;"
        "User=autogest_user;"
        "Password=Autogestion_NicoNoriega2026!;"
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