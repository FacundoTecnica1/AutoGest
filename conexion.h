#ifndef CONEXION_H
#define CONEXION_H
#include <QSqlDatabase>
#include <QSqlError>

class Conexion {
public:
    Conexion();
    bool conectar();
    void desconectar();


    QSqlDatabase getDB();
    void cerrar();

private:
    QSqlDatabase db;
};

#endif // CONEXION_H