#include "clientedaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
using namespace std;

void ClienteDAOImpl::insertar(Cliente obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO cliente (nombre, apellido, edad, dni, telefono, email, direccion, clase_licencia, fecha_registro) "
                  "VALUES (:nombre, :apellido, :edad, :dni, :telefono, :email, :direccion, :clase_licencia, :fecha_registro)");
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":apellido", obj.getApellido());
    query.bindValue(":edad", obj.getEdad());
    query.bindValue(":dni", obj.getDni());
    query.bindValue(":telefono", obj.getTelefono());
    query.bindValue(":email", obj.getEmail());
    query.bindValue(":direccion", obj.getDireccion());
    query.bindValue(":clase_licencia", obj.getClaseLicencia());
    query.bindValue(":fecha_registro", obj.getFechaRegistro());
    query.exec();
}

void ClienteDAOImpl::actualizar(Cliente obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE cliente SET nombre = :nombre, apellido = :apellido, edad = :edad, dni = :dni, telefono = :telefono, "
                  "email = :email, direccion = :direccion, clase_licencia = :clase_licencia, fecha_registro = :fecha_registro "
                  "WHERE id_cliente = :id_cliente");
    query.bindValue(":id_cliente", obj.getid_cliente());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":apellido", obj.getApellido());
    query.bindValue(":edad", obj.getEdad());
    query.bindValue(":dni", obj.getDni());
    query.bindValue(":telefono", obj.getTelefono());
    query.bindValue(":email", obj.getEmail());
    query.bindValue(":direccion", obj.getDireccion());
    query.bindValue(":clase_licencia", obj.getClaseLicencia());
    query.bindValue(":fecha_registro", obj.getFechaRegistro());
    query.exec();
}

void ClienteDAOImpl::eliminar(Cliente obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM cliente WHERE id_cliente = :id_cliente");
    query.bindValue(":id_cliente", obj.getid_cliente());
    query.exec();
}

Cliente ClienteDAOImpl::buscarPorId(int id) {
    Cliente obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM cliente WHERE id_cliente = :id_cliente");
    query.bindValue(":id_cliente", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setid_cliente(query.value("id_cliente").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setApellido(query.value("apellido").toString());
            obj.setEdad(query.value("edad").toInt());
            obj.setDni(query.value("dni").toString());
            obj.setTelefono(query.value("telefono").toString());
            obj.setEmail(query.value("email").toString());
            obj.setDireccion(query.value("direccion").toString());
            obj.setClaseLicencia(query.value("clase_licencia").toString());
            obj.setFechaRegistro(query.value("fecha_registro").toString());
        }
    }
    return obj;
}

vector<Cliente> ClienteDAOImpl::listar() {
    vector<Cliente> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM cliente");
    if(query.exec()) {
        while(query.next()) {
            Cliente obj;
            obj.setid_cliente(query.value("id_cliente").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setApellido(query.value("apellido").toString());
            obj.setEdad(query.value("edad").toInt());
            obj.setDni(query.value("dni").toString());
            obj.setTelefono(query.value("telefono").toString());
            obj.setEmail(query.value("email").toString());
            obj.setDireccion(query.value("direccion").toString());
            obj.setClaseLicencia(query.value("clase_licencia").toString());
            obj.setFechaRegistro(query.value("fecha_registro").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}