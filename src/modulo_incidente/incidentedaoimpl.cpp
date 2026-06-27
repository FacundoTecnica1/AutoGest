#include "incidentedaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>
using namespace std;

void IncidenteDAOImpl::insertar(Incidente obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO incidente (id_alquiler, tipo_incidente, fecha_incidente, descripcion, costo) "
                  "VALUES (:id_alquiler, :tipo_incidente, :fecha_incidente, :descripcion, :costo)");
    query.bindValue(":id_alquiler", obj.getid_alquiler());
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
    query.bindValue(":id_incidente", obj.getid_incidente());
    query.bindValue(":id_alquiler", obj.getid_alquiler());
    query.bindValue(":tipo_incidente", obj.getTipoIncidente());
    query.bindValue(":fecha_incidente", obj.getFechaIncidente());
    query.bindValue(":descripcion", obj.getDescripcion());
    query.bindValue(":costo", obj.getCosto());
    query.exec();
}

void IncidenteDAOImpl::eliminar(Incidente obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM incidente WHERE id_incidente = :id_incidente");
    query.bindValue(":id_incidente", obj.getid_incidente());
    query.exec();
}


vector<Incidente> IncidenteDAOImpl::listar() {
    vector<Incidente> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM incidente");
    if(query.exec()) {
        while(query.next()) {
            Incidente obj;
            obj.setid_incidente(query.value("id_incidente").toInt());
            obj.setid_alquiler(query.value("id_alquiler").toInt());
            obj.setTipoIncidente(query.value("tipo_incidente").toString());
            obj.setFechaIncidente(query.value("fecha_incidente").toString());
            obj.setDescripcion(query.value("descripcion").toString());
            obj.setCosto(query.value("costo").toDouble());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<Incidente> IncidenteDAOImpl::buscarCampo(const QString &busqueda) {
    vector<Incidente> lista;
    QSqlQuery query(QSqlDatabase::database());

    query.prepare("SELECT * FROM incidente WHERE id_incidente LIKE :busqueda OR id_alquiler LIKE :busqueda "
                  "OR tipo_incidente LIKE :busqueda OR fecha_incidente LIKE :busqueda OR descripcion LIKE :busqueda "
                  "OR costo LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            Incidente obj;
            obj.setid_incidente(query.value("id_incidente").toInt());
            obj.setid_alquiler(query.value("id_alquiler").toInt());
            obj.setTipoIncidente(query.value("tipo_incidente").toString());
            obj.setFechaIncidente(query.value("fecha_incidente").toString());
            obj.setDescripcion(query.value("descripcion").toString());
            obj.setCosto(query.value("costo").toDouble());
            lista.push_back(obj);
        }
    }
    return lista;
}