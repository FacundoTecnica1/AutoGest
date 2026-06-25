#include "autoparte.h"

Autoparte::Autoparte() {
    idAutoparte = 0;
    idProveedor = 0;
    idMantenimiento = 0;
    nombre = "";
    marca = "";
    precio = 0.0;
    stock = 0;
}

int Autoparte::getIdAutoparte() const {
    return idAutoparte;
}

void Autoparte::setIdAutoparte(int value) {
    idAutoparte = value;
}

int Autoparte::getIdProveedor() const {
    return idProveedor;
}

void Autoparte::setIdProveedor(int value) {
    idProveedor = value;
}

int Autoparte::getIdMantenimiento() const {
    return idMantenimiento;
}

void Autoparte::setIdMantenimiento(int value) {
    idMantenimiento = value;
}

QString Autoparte::getNombre() const {
    return nombre;
}

void Autoparte::setNombre(const QString &value) {
    nombre = value;
}

QString Autoparte::getMarca() const {
    return marca;
}

void Autoparte::setMarca(const QString &value) {
    marca = value;
}

double Autoparte::getPrecio() const {
    return precio;
}

void Autoparte::setPrecio(double value) {
    precio = value;
}

int Autoparte::getStock() const {
    return stock;
}

void Autoparte::setStock(int value) {
    stock = value;
}