#include "tipo_mantenimientodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
using namespace std;

void TipoMantenimientoDAOImpl::insertar(TipoMantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO tipo_mantenimiento (nombre) VALUES (:nombre)");
    query.bindValue(":nombre", obj.getNombre());
    query.exec();
}

void TipoMantenimientoDAOImpl::actualizar(TipoMantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE tipo_mantenimiento SET nombre = :nombre WHERE id_tipo_mantenimiento = :id_tipo_mantenimiento");
    query.bindValue(":id_tipo_mantenimiento", obj.getIdTipoMantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.exec();
}

void TipoMantenimientoDAOImpl::eliminar(TipoMantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM tipo_mantenimiento WHERE id_tipo_mantenimiento = :id_tipo_mantenimiento");
    query.bindValue(":id_tipo_mantenimiento", obj.getIdTipoMantenimiento());
    query.exec();
}

TipoMantenimiento TipoMantenimientoDAOImpl::buscarPorId(int id) {
    TipoMantenimiento obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM tipo_mantenimiento WHERE id_tipo_mantenimiento = :id_tipo_mantenimiento");
    query.bindValue(":id_tipo_mantenimiento", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setIdTipoMantenimiento(query.value("id_tipo_mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
        }
    }
    return obj;
}

vector<TipoMantenimiento> TipoMantenimientoDAOImpl::listar() {
    vector<TipoMantenimiento> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM tipo_mantenimiento");
    if(query.exec()) {
        while(query.next()) {
            TipoMantenimiento obj;
            obj.setIdTipoMantenimiento(query.value("id_tipo_mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}