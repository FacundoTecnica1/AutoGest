#include "tipo_Mantenimientodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>
using namespace std;

void TipoMantenimientoDAOImpl::insertar(TipoMantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO tipo_Mantenimiento (nombre) VALUES (:nombre)");
    query.bindValue(":nombre", obj.getNombre());
    query.exec();
}

void TipoMantenimientoDAOImpl::actualizar(TipoMantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE tipo_Mantenimiento SET nombre = :nombre WHERE id_tipo_Mantenimiento = :id_tipo_Mantenimiento");
    query.bindValue(":id_tipo_Mantenimiento", obj.getid_tipo_Mantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.exec();
}

void TipoMantenimientoDAOImpl::eliminar(TipoMantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM tipo_Mantenimiento WHERE id_tipo_Mantenimiento = :id_tipo_Mantenimiento");
    query.bindValue(":id_tipo_Mantenimiento", obj.getid_tipo_Mantenimiento());
    query.exec();
}


vector<TipoMantenimiento> TipoMantenimientoDAOImpl::listar() {
    vector<TipoMantenimiento> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM tipo_Mantenimiento");
    if(query.exec()) {
        while(query.next()) {
            TipoMantenimiento obj;
            obj.setid_tipo_Mantenimiento(query.value("id_tipo_Mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<TipoMantenimiento> TipoMantenimientoDAOImpl::buscarCampo(const QString &busqueda) {
    vector<TipoMantenimiento> lista;
    QSqlQuery query(QSqlDatabase::database());

    query.prepare("SELECT * FROM tipo_Mantenimiento WHERE id_tipo_Mantenimiento LIKE :busqueda OR nombre LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            TipoMantenimiento obj;
            obj.setid_tipo_Mantenimiento(query.value("id_tipo_Mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}