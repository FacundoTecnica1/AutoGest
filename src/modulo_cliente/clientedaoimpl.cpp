#include "clientedaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>
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

    //primero borramos incidentes de alquileres de este cliente
    query.prepare("DELETE FROM incidente WHERE id_alquiler IN (SELECT id_alquiler FROM alquiler WHERE id_cliente = :id_cliente)");
    query.bindValue(":id_cliente", obj.getid_cliente());
    query.exec();

    //borramos los alquileres
    query.prepare("DELETE FROM alquiler WHERE id_cliente = :id_cliente");
    query.bindValue(":id_cliente", obj.getid_cliente());
    query.exec();

    //y por ultimo al cliente
    query.prepare("DELETE FROM cliente WHERE id_cliente = :id_cliente");
    query.bindValue(":id_cliente", obj.getid_cliente());
    query.exec();
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

vector<Cliente> ClienteDAOImpl::buscarCampo(const QString &busqueda) {
    vector<Cliente> lista;
    QSqlQuery query(QSqlDatabase::database());

    query.prepare("SELECT * FROM cliente WHERE id_cliente LIKE :busqueda OR nombre LIKE :busqueda "
                  "OR apellido LIKE :busqueda OR edad LIKE :busqueda OR dni LIKE :busqueda "
                  "OR telefono LIKE :busqueda OR email LIKE :busqueda OR direccion LIKE :busqueda "
                  "OR clase_licencia LIKE :busqueda OR fecha_registro LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

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