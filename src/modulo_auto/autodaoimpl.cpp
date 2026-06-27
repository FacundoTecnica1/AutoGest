#include "autodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>
using namespace std;

void AutoDAOImpl::insertar(Auto obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO auto (marca, modelo, patente, anio, color, kilometraje, precio_por_dia, estado, fecha_ingreso) "
                  "VALUES (:marca, :modelo, :patente, :anio, :color, :kilometraje, :precio_por_dia, :estado, :fecha_ingreso)");
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":modelo", obj.getModelo());
    query.bindValue(":patente", obj.getPatente());
    query.bindValue(":anio", obj.getAnio());
    query.bindValue(":color", obj.getColor());
    query.bindValue(":kilometraje", obj.getKilometraje());
    query.bindValue(":precio_por_dia", obj.getPrecio_por_dia());
    query.bindValue(":estado", obj.getEstado());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.exec();
}

void AutoDAOImpl::actualizar(Auto obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE auto SET marca = :marca, modelo = :modelo, patente = :patente, anio = :anio, color = :color, "
                  "kilometraje = :kilometraje, precio_por_dia = :precio_por_dia, estado = :estado, fecha_ingreso = :fecha_ingreso "
                  "WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":modelo", obj.getModelo());
    query.bindValue(":patente", obj.getPatente());
    query.bindValue(":anio", obj.getAnio());
    query.bindValue(":color", obj.getColor());
    query.bindValue(":kilometraje", obj.getKilometraje());
    query.bindValue(":precio_por_dia", obj.getPrecio_por_dia());
    query.bindValue(":estado", obj.getEstado());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.exec();
}

void AutoDAOImpl::eliminar(Auto obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM auto WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    query.exec();
}


vector<Auto> AutoDAOImpl::listar() {
    vector<Auto> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM auto");
    if(query.exec()) {
        while(query.next()) {
            Auto obj;
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setMarca(query.value("marca").toString());
            obj.setModelo(query.value("modelo").toString());
            obj.setPatente(query.value("patente").toString());
            obj.setAnio(query.value("anio").toInt());
            obj.setColor(query.value("color").toString());
            obj.setKilometraje(query.value("kilometraje").toInt());
            obj.setPrecio_por_dia(query.value("precio_por_dia").toDouble());
            obj.setEstado(query.value("estado").toString());
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<Auto> AutoDAOImpl::buscarCampo(const QString &busqueda) {
    vector<Auto> lista;
    QSqlQuery query(QSqlDatabase::database());

    query.prepare("SELECT * FROM auto WHERE id_auto LIKE :busqueda OR marca LIKE :busqueda "
                  "OR modelo LIKE :busqueda OR patente LIKE :busqueda OR anio LIKE :busqueda "
                  "OR color LIKE :busqueda OR kilometraje LIKE :busqueda OR precio_por_dia LIKE :busqueda "
                  "OR estado LIKE :busqueda OR fecha_ingreso LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            Auto obj;
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setMarca(query.value("marca").toString());
            obj.setModelo(query.value("modelo").toString());
            obj.setPatente(query.value("patente").toString());
            obj.setAnio(query.value("anio").toInt());
            obj.setColor(query.value("color").toString());
            obj.setKilometraje(query.value("kilometraje").toInt());
            obj.setPrecio_por_dia(query.value("precio_por_dia").toDouble());
            obj.setEstado(query.value("estado").toString());
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}