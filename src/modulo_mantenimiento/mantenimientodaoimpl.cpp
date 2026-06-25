#include "mantenimientodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
using namespace std;

void MantenimientoDAOImpl::insertar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO mantenimiento (id_auto, id_tipo_mantenimiento, fecha_ingreso, fecha_salida, observaciones, costo, estado) "
                  "VALUES (:id_auto, :id_tipo_mantenimiento, :fecha_ingreso, :fecha_salida, :observaciones, :costo, :estado)");
    query.bindValue(":id_auto", obj.getIdAuto());
    query.bindValue(":id_tipo_mantenimiento", obj.getIdTipoMantenimiento());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.bindValue(":fecha_salida", obj.getFechaSalida());
    query.bindValue(":observaciones", obj.getObservaciones());
    query.bindValue(":costo", obj.getCosto());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void MantenimientoDAOImpl::actualizar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE mantenimiento SET id_auto = :id_auto, id_tipo_mantenimiento = :id_tipo_mantenimiento, "
                  "fecha_ingreso = :fecha_ingreso, fecha_salida = :fecha_salida, observaciones = :observaciones, costo = :costo, "
                  "estado = :estado WHERE id_mantenimiento = :id_mantenimiento");
    query.bindValue(":id_mantenimiento", obj.getIdMantenimiento());
    query.bindValue(":id_auto", obj.getIdAuto());
    query.bindValue(":id_tipo_mantenimiento", obj.getIdTipoMantenimiento());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.bindValue(":fecha_salida", obj.getFechaSalida());
    query.bindValue(":observaciones", obj.getObservaciones());
    query.bindValue(":costo", obj.getCosto());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void MantenimientoDAOImpl::eliminar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM mantenimiento WHERE id_mantenimiento = :id_mantenimiento");
    query.bindValue(":id_mantenimiento", obj.getIdMantenimiento());
    query.exec();
}

Mantenimiento MantenimientoDAOImpl::buscarPorId(int id) {
    Mantenimiento obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM mantenimiento WHERE id_mantenimiento = :id_mantenimiento");
    query.bindValue(":id_mantenimiento", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setIdMantenimiento(query.value("id_mantenimiento").toInt());
            obj.setIdAuto(query.value("id_auto").toInt());
            obj.setIdTipoMantenimiento(query.value("id_tipo_mantenimiento").toInt());
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            obj.setFechaSalida(query.value("fecha_salida").toString());
            obj.setObservaciones(query.value("observaciones").toString());
            obj.setCosto(query.value("costo").toDouble());
            obj.setEstado(query.value("estado").toString());
        }
    }
    return obj;
}

vector<Mantenimiento> MantenimientoDAOImpl::listar() {
    vector<Mantenimiento> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM mantenimiento");
    if(query.exec()) {
        while(query.next()) {
            Mantenimiento obj;
            obj.setIdMantenimiento(query.value("id_mantenimiento").toInt());
            obj.setIdAuto(query.value("id_auto").toInt());
            obj.setIdTipoMantenimiento(query.value("id_tipo_mantenimiento").toInt());
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