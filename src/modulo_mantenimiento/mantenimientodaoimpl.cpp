#include "Mantenimientodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
using namespace std;

void MantenimientoDAOImpl::insertar(Mantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO Mantenimiento (id_auto, id_tipo_Mantenimiento, fecha_ingreso, fecha_salida, observaciones, costo, estado) "
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
    query.prepare("UPDATE Mantenimiento SET id_auto = :id_auto, id_tipo_Mantenimiento = :id_tipo_Mantenimiento, "
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
    query.prepare("DELETE FROM Mantenimiento WHERE id_Mantenimiento = :id_Mantenimiento");
    query.bindValue(":id_Mantenimiento", obj.getid_Mantenimiento());
    query.exec();
}

Mantenimiento MantenimientoDAOImpl::buscarPorId(int id) {
    Mantenimiento obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM Mantenimiento WHERE id_Mantenimiento = :id_Mantenimiento");
    query.bindValue(":id_Mantenimiento", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setid_Mantenimiento(query.value("id_Mantenimiento").toInt());
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setid_tipo_Mantenimiento(query.value("id_tipo_Mantenimiento").toInt());
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
    query.prepare("SELECT * FROM Mantenimiento");
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