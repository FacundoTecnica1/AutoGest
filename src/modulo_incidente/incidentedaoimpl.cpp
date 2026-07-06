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


vector<vector<QString>> IncidenteDAOImpl::listar() {
    vector<vector<QString>> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT i.id_incidente, i.id_alquiler, i.tipo_incidente, c.nombre, c.apellido, "
                  "a.marca, a.modelo, a.patente, i.fecha_incidente, i.descripcion, i.costo "
                  "FROM incidente i "
                  "INNER JOIN alquiler alq ON i.id_alquiler = alq.id_alquiler "
                  "INNER JOIN cliente c ON alq.id_cliente = c.id_cliente "
                  "INNER JOIN auto a ON alq.id_auto = a.id_auto");
    if(query.exec()) {
        while(query.next()) {
            vector<QString> fila;
            fila.push_back(query.value(0).toString());
            fila.push_back(query.value(1).toString());
            fila.push_back(query.value(2).toString());
            fila.push_back(query.value(3).toString() + " " + query.value(4).toString());
            fila.push_back(query.value(5).toString() + " " + query.value(6).toString() + " (" + query.value(7).toString() + ")");
            fila.push_back(query.value(8).toString());
            fila.push_back(query.value(9).toString());
            fila.push_back(query.value(10).toString());
            lista.push_back(fila);
        }
    }
    return lista;
}

vector<vector<QString>> IncidenteDAOImpl::buscarCampo(const QString &busqueda) {
    vector<vector<QString>> lista;
    QSqlQuery query(QSqlDatabase::database());

    //la busqueda usa los datos visibles de incidente, cliente y auto
    //asi no depende de que la persona sepa el id del alquiler
    query.prepare("SELECT i.id_incidente, i.id_alquiler, i.tipo_incidente, c.nombre, c.apellido, "
                  "a.marca, a.modelo, a.patente, i.fecha_incidente, i.descripcion, i.costo "
                  "FROM incidente i "
                  "INNER JOIN alquiler alq ON i.id_alquiler = alq.id_alquiler "
                  "INNER JOIN cliente c ON alq.id_cliente = c.id_cliente "
                  "INNER JOIN auto a ON alq.id_auto = a.id_auto "
                  "WHERE i.id_incidente LIKE :busqueda OR i.tipo_incidente LIKE :busqueda "
                  "OR c.nombre LIKE :busqueda OR c.apellido LIKE :busqueda "
                  "OR a.marca LIKE :busqueda OR a.modelo LIKE :busqueda OR a.patente LIKE :busqueda "
                  "OR i.fecha_incidente LIKE :busqueda OR i.descripcion LIKE :busqueda OR i.costo LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            vector<QString> fila;
            fila.push_back(query.value(0).toString());
            fila.push_back(query.value(1).toString());
            fila.push_back(query.value(2).toString());
            fila.push_back(query.value(3).toString() + " " + query.value(4).toString());
            fila.push_back(query.value(5).toString() + " " + query.value(6).toString() + " (" + query.value(7).toString() + ")");
            fila.push_back(query.value(8).toString());
            fila.push_back(query.value(9).toString());
            fila.push_back(query.value(10).toString());
            lista.push_back(fila);
        }
    }
    return lista;
}

int IncidenteDAOImpl::buscarAlquilerActivo(int id_auto, int id_cliente, const QString& fechaIncidente) {
    QSqlQuery query(QSqlDatabase::database());

    //el incidente se ata al alquiler que contiene esa fecha
    //por eso se filtra por auto, cliente y rango del alquiler
    query.prepare("SELECT id_alquiler FROM alquiler "
                  "WHERE id_auto = :id_auto AND id_cliente = :id_cliente "
                  "AND fecha_inicio <= :fecha_incidente AND fecha_fin >= :fecha_incidente "
                  "AND estado IN ('activo', 'finalizado') "
                  "ORDER BY id_alquiler DESC");
    query.bindValue(":id_auto", id_auto);
    query.bindValue(":id_cliente", id_cliente);
    query.bindValue(":fecha_incidente", fechaIncidente);

    if(query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}

void IncidenteDAOImpl::finalizarAlquilerSiCorresponde(int id_alquiler, const QString& fechaIncidente) {
    QSqlQuery query(QSqlDatabase::database());

    //si la fecha cae en medio del alquiler, queda finalizado
    //esto marca que el auto ya no sigue disponible para ese alquiler
    query.prepare("UPDATE alquiler SET estado = 'finalizado' "
                  "WHERE id_alquiler = :id_alquiler "
                  "AND fecha_inicio <= :fecha_incidente AND fecha_fin >= :fecha_incidente");
    query.bindValue(":id_alquiler", id_alquiler);
    query.bindValue(":fecha_incidente", fechaIncidente);
    query.exec();
}
