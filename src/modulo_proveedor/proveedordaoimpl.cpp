#include "proveedordaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>

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

    query.prepare("UPDATE proveedor SET nombre = :nombre, telefono = :telefono, "
                  "email = :email, direccion = :direccion WHERE id_proveedor = :id_proveedor");
    query.bindValue(":id_proveedor", obj.getid_proveedor());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":telefono", obj.getTelefono());
    query.bindValue(":email", obj.getEmail());
    query.bindValue(":direccion", obj.getDireccion());
    query.exec();
}

void ProveedorDAOImpl::eliminar(Proveedor obj) {
    QSqlQuery query(QSqlDatabase::database());

    //primero borramos dependencias en autoparte para evitar el error de Foreign Key
    query.prepare("DELETE FROM autoparte WHERE id_proveedor = :id_proveedor");
    query.bindValue(":id_proveedor", obj.getid_proveedor());
    query.exec();

    //ahora sí borramos el proveedor sin problema
    query.prepare("DELETE FROM proveedor WHERE id_proveedor = :id_proveedor");
    query.bindValue(":id_proveedor", obj.getid_proveedor());
    query.exec();
}

vector<Proveedor> ProveedorDAOImpl::listar() {
    vector<Proveedor> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM proveedor");
    if(query.exec()) {
        while(query.next()) {
            Proveedor obj;
            //hago coincidir los names de los values
            //asi pobla la tabla piola
            obj.setid_proveedor(query.value("id_proveedor").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setTelefono(query.value("telefono").toString());
            obj.setEmail(query.value("email").toString());
            obj.setDireccion(query.value("direccion").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<Proveedor> ProveedorDAOImpl::buscarCampo(const QString &busqueda) {
    vector<Proveedor> lista;
    QSqlQuery query(QSqlDatabase::database());

    //corrijo las columnas del select
    //para buscar bien el string
    query.prepare("SELECT * FROM proveedor WHERE id_proveedor LIKE :busqueda OR nombre LIKE :busqueda "
                  "OR telefono LIKE :busqueda OR email LIKE :busqueda OR direccion LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            Proveedor obj;
            obj.setid_proveedor(query.value("id_proveedor").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setTelefono(query.value("telefono").toString());
            obj.setEmail(query.value("email").toString());
            obj.setDireccion(query.value("direccion").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}