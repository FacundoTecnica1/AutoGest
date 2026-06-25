#include "autoparte.h"

Autoparte::Autoparte() {
    id_autoparte = 0;
    id_proveedor = 0;
    id_Mantenimiento = 0;
    nombre = "";
    marca = "";
    precio = 0.0;
    stock = 0;
}

int Autoparte::getid_autoparte() const {
    return id_autoparte;
}

void Autoparte::setid_autoparte(int value) {
    id_autoparte = value;
}

int Autoparte::getid_proveedor() const {
    return id_proveedor;
}

void Autoparte::setid_proveedor(int value) {
    id_proveedor = value;
}

int Autoparte::getid_Mantenimiento() const {
    return id_Mantenimiento;
}

void Autoparte::setid_Mantenimiento(int value) {
    id_Mantenimiento = value;
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