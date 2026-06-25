#include "proveedordaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
using namespace std;

void ProveedorDAOImpl::insertar(Proveedor obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO proveedor (nombre, telefono, email, direccion) "
                  "VALUES (:nombre, :telefono, :email, :direccion)");
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":telefono", obj.getTelefono());
    query.bindValue(":email", obj.getEmail());
    query.bindValue(":direccion", obj.getDireccion());
    query.exec();
}

void ProveedorDAOImpl::actualizar(Proveedor obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE proveedor SET nombre = :nombre, telefono = :telefono, email = :email, direccion = :direccion "
                  "WHERE `id proveedor` = :id_proveedor");
    query.bindValue(":id_proveedor", obj.getIdProveedor());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":telefono", obj.getTelefono());
    query.bindValue(":email", obj.getEmail());
    query.bindValue(":direccion", obj.getDireccion());
    query.exec();
}

void ProveedorDAOImpl::eliminar(Proveedor obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM proveedor WHERE `id proveedor` = :id_proveedor");
    query.bindValue(":id_proveedor", obj.getIdProveedor());
    query.exec();
}

Proveedor ProveedorDAOImpl::buscarPorId(int id) {
    Proveedor obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM proveedor WHERE `id proveedor` = :id_proveedor");
    query.bindValue(":id_proveedor", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setIdProveedor(query.value("id proveedor").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setTelefono(query.value("telefono").toString());
            obj.setEmail(query.value("email").toString());
            obj.setDireccion(query.value("direccion").toString());
        }
    }
    return obj;
}

vector<Proveedor> ProveedorDAOImpl::listar() {
    vector<Proveedor> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM proveedor");
    if(query.exec()) {
        while(query.next()) {
            Proveedor obj;
            obj.setIdProveedor(query.value("id proveedor").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setTelefono(query.value("telefono").toString());
            obj.setEmail(query.value("email").toString());
            obj.setDireccion(query.value("direccion").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}