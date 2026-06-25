#include "incidentedaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
using namespace std;

void IncidenteDAOImpl::insertar(Incidente obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO incidente (id_alquiler, tipo_incidente, fecha_incidente, descripcion, costo) "
                  "VALUES (:id_alquiler, :tipo_incidente, :fecha_incidente, :descripcion, :costo)");
    query.bindValue(":id_alquiler", obj.getIdAlquiler());
    query.bindValue(":tipo_incidente", obj.getTipoIncidente());
    query.bindValue(":fecha_incidente", obj.getFechaIncidente());
    query.bindValue(":descripcion", obj.getDescripcion());
    query.bindValue(":costo", obj.getCosto());
    query.exec();
}

void IncidenteDAOImpl::actualizar(Incidente obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE incidente SET id_alquiler = :id_alquiler, tipo_incidente = :tipo_incidente, "
                  "fecha_incidente = :fecha_incidente, descripcion = :descripcion, costo = :costo WHERE id_incidente = :id_incidente");
    query.bindValue(":id_incidente", obj.getIdIncidente());
    query.bindValue(":id_alquiler", obj.getIdAlquiler());
    query.bindValue(":tipo_incidente", obj.getTipoIncidente());
    query.bindValue(":fecha_incidente", obj.getFechaIncidente());
    query.bindValue(":descripcion", obj.getDescripcion());
    query.bindValue(":costo", obj.getCosto());
    query.exec();
}

void IncidenteDAOImpl::eliminar(Incidente obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM incidente WHERE id_incidente = :id_incidente");
    query.bindValue(":id_incidente", obj.getIdIncidente());
    query.exec();
}

Incidente IncidenteDAOImpl::buscarPorId(int id) {
    Incidente obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM incidente WHERE id_incidente = :id_incidente");
    query.bindValue(":id_incidente", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setIdIncidente(query.value("id_incidente").toInt());
            obj.setIdAlquiler(query.value("id_alquiler").toInt());
            obj.setTipoIncidente(query.value("tipo_incidente").toString());
            obj.setFechaIncidente(query.value("fecha_incidente").toString());
            obj.setDescripcion(query.value("descripcion").toString());
            obj.setCosto(query.value("costo").toDouble());
        }
    }
    return obj;
}

vector<Incidente> IncidenteDAOImpl::listar() {
    vector<Incidente> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM incidente");
    if(query.exec()) {
        while(query.next()) {
            Incidente obj;
            obj.setIdIncidente(query.value("id_incidente").toInt());
            obj.setIdAlquiler(query.value("id_alquiler").toInt());
            obj.setTipoIncidente(query.value("tipo_incidente").toString());
            obj.setFechaIncidente(query.value("fecha_incidente").toString());
            obj.setDescripcion(query.value("descripcion").toString());
            obj.setCosto(query.value("costo").toDouble());
            lista.push_back(obj);
        }
    }
    return lista;
}