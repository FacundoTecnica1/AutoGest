#include "mantenimientodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>

using namespace std;

void MantenimientoDAOImpl::insertar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    //saco la mayuscula de tipo_mantenimiento
    //para que inserte bien el id foraneo
    query.prepare("INSERT INTO mantenimiento (id_auto, id_tipo_mantenimiento, fecha_ingreso, fecha_salida, observaciones, costo, estado) "
                  "VALUES (:id_auto, :id_tipo_mantenimiento, :fecha_ingreso, :fecha_salida, :observaciones, :costo, :estado)");
    query.bindValue(":id_auto", obj.getid_auto());
    query.bindValue(":id_tipo_mantenimiento", obj.getid_tipo_Mantenimiento());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.bindValue(":fecha_salida", obj.getFechaSalida());
    query.bindValue(":observaciones", obj.getObservaciones());
    query.bindValue(":costo", obj.getCosto());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void MantenimientoDAOImpl::actualizar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    //corrijo el id principal y el foraneo
    //para que guarde los cambios
    query.prepare("UPDATE mantenimiento SET id_auto = :id_auto, id_tipo_mantenimiento = :id_tipo_mantenimiento, "
                  "fecha_ingreso = :fecha_ingreso, fecha_salida = :fecha_salida, observaciones = :observaciones, costo = :costo, "
                  "estado = :estado WHERE id_mantenimiento = :id_mantenimiento");
    query.bindValue(":id_mantenimiento", obj.getid_Mantenimiento());
    query.bindValue(":id_auto", obj.getid_auto());
    query.bindValue(":id_tipo_mantenimiento", obj.getid_tipo_Mantenimiento());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.bindValue(":fecha_salida", obj.getFechaSalida());
    query.bindValue(":observaciones", obj.getObservaciones());
    query.bindValue(":costo", obj.getCosto());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void MantenimientoDAOImpl::eliminar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());

    //pongo todo el where en minuscula
    //asi borra primero las autopartes
    query.prepare("DELETE FROM autoparte WHERE id_mantenimiento = :id_mantenimiento");
    query.bindValue(":id_mantenimiento", obj.getid_Mantenimiento());
    query.exec();

    //y despues borra piola el mantenimiento
    //sin quejarse por las foreanas
    query.prepare("DELETE FROM mantenimiento WHERE id_mantenimiento = :id_mantenimiento");
    query.bindValue(":id_mantenimiento", obj.getid_Mantenimiento());
    query.exec();
}

vector<vector<QString>> MantenimientoDAOImpl::listar() {
    vector<vector<QString>> lista;
    QSqlQuery q(QSqlDatabase::database());
    //arreglo las tablas del join
    //para que devuelva los datos armados
    q.prepare("SELECT m.id_mantenimiento, a.marca, a.modelo, a.patente, t.nombre, "
              "m.fecha_ingreso, m.fecha_salida, m.costo, m.estado "
              "FROM mantenimiento m "
              "INNER JOIN auto a ON m.id_auto = a.id_auto "
              "INNER JOIN tipo_mantenimiento t ON m.id_tipo_mantenimiento = t.id_tipo_mantenimiento");

    if(q.exec()) {
        while(q.next()) {
            vector<QString> fila;
            fila.push_back(q.value(0).toString());
            fila.push_back(q.value(1).toString() + " " + q.value(2).toString() + " (" + q.value(3).toString() + ")");
            fila.push_back(q.value(4).toString());
            fila.push_back(q.value(5).toString());
            fila.push_back(q.value(6).toString());
            fila.push_back(q.value(7).toString());
            fila.push_back(q.value(8).toString());
            lista.push_back(fila);
        }
    }
    return lista;
}

vector<vector<QString>> MantenimientoDAOImpl::buscarCampo(const QString &busqueda) {
    vector<vector<QString>> lista;
    QSqlQuery q(QSqlDatabase::database());
    //actualizo las variables sql en la busqueda
    //asi el txtBuscador hace su magia
    q.prepare("SELECT m.id_mantenimiento, a.marca, a.modelo, a.patente, t.nombre, "
              "m.fecha_ingreso, m.fecha_salida, m.costo, m.estado "
              "FROM mantenimiento m "
              "INNER JOIN auto a ON m.id_auto = a.id_auto "
              "INNER JOIN tipo_mantenimiento t ON m.id_tipo_mantenimiento = t.id_tipo_mantenimiento "
              "WHERE m.id_mantenimiento LIKE :busqueda OR a.marca LIKE :busqueda OR a.modelo LIKE :busqueda "
              "OR a.patente LIKE :busqueda OR t.nombre LIKE :busqueda OR m.fecha_ingreso LIKE :busqueda "
              "OR m.fecha_salida LIKE :busqueda OR m.costo LIKE :busqueda OR m.estado LIKE :busqueda");

    q.bindValue(":busqueda", "%" + busqueda + "%");

    if(q.exec()) {
        while(q.next()) {
            vector<QString> fila;
            fila.push_back(q.value(0).toString());
            fila.push_back(q.value(1).toString() + " " + q.value(2).toString() + " (" + q.value(3).toString() + ")");
            fila.push_back(q.value(4).toString());
            fila.push_back(q.value(5).toString());
            fila.push_back(q.value(6).toString());
            fila.push_back(q.value(7).toString());
            fila.push_back(q.value(8).toString());
            lista.push_back(fila);
        }
    }
    return lista;
}