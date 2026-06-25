#include "Proveedor.h"

Proveedor::Proveedor() {
    id_proveedor = 0;
    nombre = "";
    telefono = "";
    email = "";
    direccion = "";
}

int Proveedor::getid_proveedor() const {
    return id_proveedor;
}

void Proveedor::setid_proveedor(int value) {
    id_proveedor = value;
}

QString Proveedor::getNombre() const {
    return nombre;
}

void Proveedor::setNombre(const QString &value) {
    nombre = value;
}

QString Proveedor::getTelefono() const {
    return telefono;
}

void Proveedor::setTelefono(const QString &value) {
    telefono = value;
}

QString Proveedor::getEmail() const {
    return email;
}

void Proveedor::setEmail(const QString &value) {
    email = value;
}

QString Proveedor::getDireccion() const {
    return direccion;
}

void Proveedor::setDireccion(const QString &value) {
    direccion = value;
}