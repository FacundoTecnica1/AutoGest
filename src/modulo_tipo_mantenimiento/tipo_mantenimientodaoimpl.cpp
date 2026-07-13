#include "tipo_mantenimientodaoimpl.h"
#include "../modulo_auto/autodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>
using namespace std;

void TipoMantenimientoDAOImpl::insertar(TipoMantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    //pongo el nombre de la tabla en minuscula
    //para que haga juego con la db
    query.prepare("INSERT INTO tipo_mantenimiento (nombre) VALUES (:nombre)");
    query.bindValue(":nombre", obj.getNombre());
    query.exec();
}

void TipoMantenimientoDAOImpl::actualizar(TipoMantenimiento obj) {
    QSqlQuery query(QSqlDatabase::database());
    //corrijo id_tipo_mantenimiento
    //para que el where actualice piola
    query.prepare("UPDATE tipo_mantenimiento SET nombre = :nombre WHERE id_tipo_mantenimiento = :id_tipo_mantenimiento");
    query.bindValue(":id_tipo_mantenimiento", obj.getid_tipo_Mantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.exec();
}

void TipoMantenimientoDAOImpl::eliminar(TipoMantenimiento obj) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    vector<int> autosAfectados;

    //guardamos los autos porque al final pueden volver a quedar disponibles
    query.prepare("SELECT DISTINCT id_auto FROM mantenimiento "
                  "WHERE id_tipo_mantenimiento = :id_tipo_mantenimiento");
    query.bindValue(":id_tipo_mantenimiento", obj.getid_tipo_Mantenimiento());
    if(query.exec()) {
        while(query.next()) autosAfectados.push_back(query.value(0).toInt());
    }
    query.finish();

    //el tipo puede tener mantenimientos y autopartes relacionadas
    //por eso se borran las referencias desde la mas dependiente
    if(!db.transaction()) return;

    query.prepare("DELETE FROM autoparte WHERE id_mantenimiento IN "
                  "(SELECT id_mantenimiento FROM mantenimiento WHERE id_tipo_mantenimiento = :id_tipo_mantenimiento)");
    query.bindValue(":id_tipo_mantenimiento", obj.getid_tipo_Mantenimiento());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    query.prepare("DELETE FROM mantenimiento WHERE id_tipo_mantenimiento = :id_tipo_mantenimiento");
    query.bindValue(":id_tipo_mantenimiento", obj.getid_tipo_Mantenimiento());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    query.prepare("DELETE FROM tipo_mantenimiento WHERE id_tipo_mantenimiento = :id_tipo_mantenimiento");
    query.bindValue(":id_tipo_mantenimiento", obj.getid_tipo_Mantenimiento());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    if(!db.commit()) {
        db.rollback();
        return;
    }

    AutoDAOImpl autoDao;
    for(int idAuto : autosAfectados) autoDao.sincronizarEstado(idAuto);
}

vector<TipoMantenimiento> TipoMantenimientoDAOImpl::listar() {
    vector<TipoMantenimiento> lista;
    QSqlQuery query(QSqlDatabase::database());
    //ajusto el select
    //para que traiga bien las opciones
    query.prepare("SELECT id_tipo_mantenimiento, nombre FROM tipo_mantenimiento ORDER BY id_tipo_mantenimiento");
    if(query.exec()) {
        while(query.next()) {
            TipoMantenimiento obj;
            //saco la mayuscula del string del value
            //asi puede agarrar el id
            obj.setid_tipo_Mantenimiento(query.value("id_tipo_mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<TipoMantenimiento> TipoMantenimientoDAOImpl::buscarCampo(const QString &busqueda) {
    vector<TipoMantenimiento> lista;
    QSqlQuery query(QSqlDatabase::database());
    //actualizo los nombres aca tambien
    //para que el filtro funcione bien
    query.prepare("SELECT * FROM tipo_mantenimiento WHERE id_tipo_mantenimiento LIKE :busqueda OR nombre LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            TipoMantenimiento obj;
            obj.setid_tipo_Mantenimiento(query.value("id_tipo_mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}
