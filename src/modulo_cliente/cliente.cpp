#include "cliente.h"

Cliente::Cliente() {
    idCliente = 0;
    nombre = "";
    apellido = "";
    edad = 0;
    dni = "";
    telefono = "";
    email = "";
    direccion = "";
    claseLicencia = "";
    fechaRegistro = "";
}

int Cliente::getIdCliente() const {
    return idCliente;
}

void Cliente::setIdCliente(int value) {
    idCliente = value;
}

QString Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const QString &value) {
    nombre = value;
}

QString Cliente::getApellido() const {
    return apellido;
}

void Cliente::setApellido(const QString &value) {
    apellido = value;
}

int Cliente::getEdad() const {
    return edad;
}

void Cliente::setEdad(int value) {
    edad = value;
}

QString Cliente::getDni() const {
    return dni;
}

void Cliente::setDni(const QString &value) {
    dni = value;
}

QString Cliente::getTelefono() const {
    return telefono;
}

void Cliente::setTelefono(const QString &value) {
    telefono = value;
}

QString Cliente::getEmail() const {
    return email;
}

void Cliente::setEmail(const QString &value) {
    email = value;
}

QString Cliente::getDireccion() const {
    return direccion;
}

void Cliente::setDireccion(const QString &value) {
    direccion = value;
}

QString Cliente::getClaseLicencia() const {
    return claseLicencia;
}

void Cliente::setClaseLicencia(const QString &value) {
    claseLicencia = value;
}

QString Cliente::getFechaRegistro() const {
    return fechaRegistro;
}

void Cliente::setFechaRegistro(const QString &value) {
    fechaRegistro = value;
}