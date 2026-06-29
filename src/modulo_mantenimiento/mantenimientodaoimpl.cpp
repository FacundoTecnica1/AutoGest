#include "Mantenimientodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>

using namespace std;

void MantenimientoDAOImpl::insertar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO mantenimiento (id_auto, id_tipo_Mantenimiento, fecha_ingreso, fecha_salida, observaciones, costo, estado) "
                  "VALUES (:id_auto, :id_tipo_Mantenimiento, :fecha_ingreso, :fecha_salida, :observaciones, :costo, :estado)");
    query.bindValue(":id_auto", obj.getid_auto());
    query.bindValue(":id_tipo_Mantenimiento", obj.getid_tipo_Mantenimiento());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.bindValue(":fecha_salida", obj.getFechaSalida());
    query.bindValue(":observaciones", obj.getObservaciones());
    query.bindValue(":costo", obj.getCosto());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void MantenimientoDAOImpl::actualizar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE mantenimiento SET id_auto = :id_auto, id_tipo_Mantenimiento = :id_tipo_Mantenimiento, "
                  "fecha_ingreso = :fecha_ingreso, fecha_salida = :fecha_salida, observaciones = :observaciones, costo = :costo, "
                  "estado = :estado WHERE id_Mantenimiento = :id_Mantenimiento");
    query.bindValue(":id_Mantenimiento", obj.getid_Mantenimiento());
    query.bindValue(":id_auto", obj.getid_auto());
    query.bindValue(":id_tipo_Mantenimiento", obj.getid_tipo_Mantenimiento());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.bindValue(":fecha_salida", obj.getFechaSalida());
    query.bindValue(":observaciones", obj.getObservaciones());
    query.bindValue(":costo", obj.getCosto());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void MantenimientoDAOImpl::eliminar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());

    //primero borramos las autopartes de este mantenimiento
    query.prepare("DELETE FROM autoparte WHERE id_Mantenimiento = :id_Mantenimiento");
    query.bindValue(":id_Mantenimiento", obj.getid_Mantenimiento());
    query.exec();

    //ahora se puede borrar el mantenimiento
    query.prepare("DELETE FROM mantenimiento WHERE id_Mantenimiento = :id_Mantenimiento");
    query.bindValue(":id_Mantenimiento", obj.getid_Mantenimiento());
    query.exec();
}

vector<Mantenimiento> MantenimientoDAOImpl::listar() {
    vector<Mantenimiento> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM mantenimiento");
    if(query.exec()) {
        while(query.next()) {
            Mantenimiento obj;
            obj.setid_Mantenimiento(query.value("id_Mantenimiento").toInt());
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setid_tipo_Mantenimiento(query.value("id_tipo_Mantenimiento").toInt());
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            obj.setFechaSalida(query.value("fecha_salida").toString());
            obj.setObservaciones(query.value("observaciones").toString());
            obj.setCosto(query.value("costo").toDouble());
            obj.setEstado(query.value("estado").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<Mantenimiento> MantenimientoDAOImpl::buscarCampo(const QString &busqueda) {
    vector<Mantenimiento> lista;
    QSqlQuery query(QSqlDatabase::database());

    query.prepare("SELECT * FROM mantenimiento WHERE id_Mantenimiento LIKE :busqueda OR id_auto LIKE :busqueda "
                  "OR id_tipo_Mantenimiento LIKE :busqueda OR fecha_ingreso LIKE :busqueda OR fecha_salida LIKE :busqueda "
                  "OR observaciones LIKE :busqueda OR costo LIKE :busqueda OR estado LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            Mantenimiento obj;
            obj.setid_Mantenimiento(query.value("id_Mantenimiento").toInt());
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setid_tipo_Mantenimiento(query.value("id_tipo_Mantenimiento").toInt());
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            obj.setFechaSalida(query.value("fecha_salida").toString());
            obj.setObservaciones(query.value("observaciones").toString());
            obj.setCosto(query.value("costo").toDouble());
            obj.setEstado(query.value("estado").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

//buscatodo con los inner joins
vector<vector<QString>> MantenimientoDAOImpl::listarDetalles() {
    vector<vector<QString>> lista;
    QSqlQuery q(QSqlDatabase::database());
    q.prepare("SELECT m.id_Mantenimiento, a.marca, a.modelo, a.patente, t.nombre, "
              "m.fecha_ingreso, m.fecha_salida, m.costo, m.estado "
              "FROM mantenimiento m "
              "INNER JOIN auto a ON m.id_auto = a.id_auto "
              "INNER JOIN tipo_mantenimiento t ON m.id_tipo_Mantenimiento = t.id_tipo_Mantenimiento");

    if(q.exec()) {
        while(q.next()) {
            vector<QString> fila;
            fila.push_back(q.value(0).toString()); // ID
            fila.push_back(q.value(1).toString() + " " + q.value(2).toString() + " (" + q.value(3).toString() + ")"); // Auto (Marca Modelo y Patente)
            fila.push_back(q.value(4).toString()); // Tipo mantenimiento (Nombre)
            fila.push_back(q.value(5).toString()); // Fecha Ingreso
            fila.push_back(q.value(6).toString()); // Fecha Salida
            fila.push_back(q.value(7).toString()); // Costo
            fila.push_back(q.value(8).toString()); // Estado
            lista.push_back(fila);
        }
    }
    return lista;
}