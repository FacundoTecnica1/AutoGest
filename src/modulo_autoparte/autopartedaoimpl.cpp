#include "autopartedaoimpl.h"
#include "autodaoimpl.h"
#include "auto.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
using namespace std;

void AutoparteDAOImpl::insertar(Autoparte obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO autoparte (`id_Proveedor`, `id_Mantenimiento`, nombre, marca, precio, stock) "
                  "VALUES (:id_Proveedor, :id_Mantenimiento, :nombre, :marca, :precio, :stock)");
    query.bindValue(":id_Proveedor", obj.getid_proveedor());
    query.bindValue(":id_Mantenimiento", obj.getid_Mantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":precio", obj.getPrecio());
    query.bindValue(":stock", obj.getStock());
    query.exec();
}

void AutoparteDAOImpl::actualizar(Autoparte obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE autoparte SET `id_Proveedor` = :id_Proveedor, `id_Mantenimiento` = :id_Mantenimiento, nombre = :nombre, "
                  "marca = :marca, precio = :precio, stock = :stock WHERE `id autoparte` = :id_autoparte");
    query.bindValue(":id_autoparte", obj.getid_autoparte());
    query.bindValue(":id_Proveedor", obj.getid_proveedor());
    query.bindValue(":id_Mantenimiento", obj.getid_Mantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":precio", obj.getPrecio());
    query.bindValue(":stock", obj.getStock());
    query.exec();
}

void AutoDAOImpl::eliminar(Auto obj) {
    QSqlQuery query(QSqlDatabase::database());

    //limpia incidentes pegados a los alquileres de este auto
    query.prepare("DELETE FROM incidente WHERE id_alquiler IN (SELECT id_alquiler FROM alquiler WHERE id_auto = :id_auto)");
    query.bindValue(":id_auto", obj.getid_auto());
    query.exec();

    //despues se limpiar alquileres
    query.prepare("DELETE FROM alquiler WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    query.exec();

    //despues se borra autopartes pegadas a los mantenimientos de este auto
    query.prepare("DELETE FROM autoparte WHERE id_Mantenimiento IN (SELECT id_Mantenimiento FROM mantenimiento WHERE id_auto = :id_auto)");
    query.bindValue(":id_auto", obj.getid_auto());
    query.exec();

    //se borra directamente mantenimientos
    query.prepare("DELETE FROM mantenimiento WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    query.exec();

    //y por ultimo se borra el auto
    query.prepare("DELETE FROM auto WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    query.exec();
}

vector<Autoparte> AutoparteDAOImpl::listar() {
    vector<Autoparte> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM autoparte");
    if(query.exec()) {
        while(query.next()) {
            Autoparte obj;
            obj.setid_autoparte(query.value("id autoparte").toInt());
            obj.setid_proveedor(query.value("id_Proveedor").toInt());
            obj.setid_Mantenimiento(query.value("id_Mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setMarca(query.value("marca").toString());
            obj.setPrecio(query.value("precio").toDouble());
            obj.setStock(query.value("stock").toInt());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<Autoparte> AutoparteDAOImpl::buscarCampo(const QString &busqueda) {
    vector<Autoparte> lista;
    QSqlQuery query(QSqlDatabase::database());

    query.prepare("SELECT * FROM autoparte WHERE `id autoparte` LIKE :busqueda OR id_Proveedor LIKE :busqueda "
                  "OR id_Mantenimiento LIKE :busqueda OR nombre LIKE :busqueda OR marca LIKE :busqueda "
                  "OR precio LIKE :busqueda OR stock LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            Autoparte obj;
            obj.setid_autoparte(query.value("id autoparte").toInt());
            obj.setid_proveedor(query.value("id_Proveedor").toInt());
            obj.setid_Mantenimiento(query.value("id_Mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setMarca(query.value("marca").toString());
            obj.setPrecio(query.value("precio").toDouble());
            obj.setStock(query.value("stock").toInt());
            lista.push_back(obj);
        }
    }
    return lista;
}