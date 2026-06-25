#include "autopartedaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
using namespace std;

void AutoparteDAOImpl::insertar(Autoparte obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO autoparte (`id proveedor`, `id mantenimiento`, nombre, marca, precio, stock) "
                  "VALUES (:id_proveedor, :id_mantenimiento, :nombre, :marca, :precio, :stock)");
    query.bindValue(":id_proveedor", obj.getIdProveedor());
    query.bindValue(":id_mantenimiento", obj.getIdMantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":precio", obj.getPrecio());
    query.bindValue(":stock", obj.getStock());
    query.exec();
}

void AutoparteDAOImpl::actualizar(Autoparte obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE autoparte SET `id proveedor` = :id_proveedor, `id mantenimiento` = :id_mantenimiento, nombre = :nombre, "
                  "marca = :marca, precio = :precio, stock = :stock WHERE `id autoparte` = :id_autoparte");
    query.bindValue(":id_autoparte", obj.getIdAutoparte());
    query.bindValue(":id_proveedor", obj.getIdProveedor());
    query.bindValue(":id_mantenimiento", obj.getIdMantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":precio", obj.getPrecio());
    query.bindValue(":stock", obj.getStock());
    query.exec();
}

void AutoparteDAOImpl::eliminar(Autoparte obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM autoparte WHERE `id autoparte` = :id_autoparte");
    query.bindValue(":id_autoparte", obj.getIdAutoparte());
    query.exec();
}

Autoparte AutoparteDAOImpl::buscarPorId(int id) {
    Autoparte obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM autoparte WHERE `id autoparte` = :id_autoparte");
    query.bindValue(":id_autoparte", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setIdAutoparte(query.value("id autoparte").toInt());
            obj.setIdProveedor(query.value("id proveedor").toInt());
            obj.setIdMantenimiento(query.value("id mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setMarca(query.value("marca").toString());
            obj.setPrecio(query.value("precio").toDouble());
            obj.setStock(query.value("stock").toInt());
        }
    }
    return obj;
}

vector<Autoparte> AutoparteDAOImpl::listar() {
    vector<Autoparte> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM autoparte");
    if(query.exec()) {
        while(query.next()) {
            Autoparte obj;
            obj.setIdAutoparte(query.value("id autoparte").toInt());
            obj.setIdProveedor(query.value("id proveedor").toInt());
            obj.setIdMantenimiento(query.value("id mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setMarca(query.value("marca").toString());
            obj.setPrecio(query.value("precio").toDouble());
            obj.setStock(query.value("stock").toInt());
            lista.push_back(obj);
        }
    }
    return lista;
}