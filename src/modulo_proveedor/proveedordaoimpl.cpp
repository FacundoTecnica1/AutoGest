#include "Proveedordaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>
using namespace std;

void ProveedorDAOImpl::insertar(Proveedor obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO Proveedor (nombre, telefono, email, direccion) "
                  "VALUES (:nombre, :telefono, :email, :direccion)");
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":telefono", obj.getTelefono());
    query.bindValue(":email", obj.getEmail());
    query.bindValue(":direccion", obj.getDireccion());
    query.exec();
}

void ProveedorDAOImpl::actualizar(Proveedor obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE Proveedor SET nombre = :nombre, telefono = :telefono, email = :email, direccion = :direccion "
                  "WHERE `id_Proveedor` = :id_Proveedor");
    query.bindValue(":id_Proveedor", obj.getid_proveedor());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":telefono", obj.getTelefono());
    query.bindValue(":email", obj.getEmail());
    query.bindValue(":direccion", obj.getDireccion());
    query.exec();
}

void ProveedorDAOImpl::eliminar(Proveedor obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM Proveedor WHERE `id_Proveedor` = :id_Proveedor");
    query.bindValue(":id_Proveedor", obj.getid_proveedor());
    query.exec();
}


vector<Proveedor> ProveedorDAOImpl::listar() {
    vector<Proveedor> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM Proveedor");
    if(query.exec()) {
        while(query.next()) {
            Proveedor obj;
            obj.setid_proveedor(query.value("id_Proveedor").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setTelefono(query.value("telefono").toString());
            obj.setEmail(query.value("email").toString());
            obj.setDireccion(query.value("direccion").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}