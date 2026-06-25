#include "auto.h"

Auto::Auto() {
    id_auto = 0;
    marca = "";
    modelo = "";
    patente = "";
    anio = 0;
    color = "";
    kilometraje = 0;
    precioPorDia = 0.0;
    estado = "";
    fechaIngreso = "";
}

int Auto::getid_auto() const {
    return id_auto;
}

void Auto::setid_auto(int value) {
    id_auto = value;
}

QString Auto::getMarca() const {
    return marca;
}

void Auto::setMarca(const QString &value) {
    marca = value;
}

QString Auto::getModelo() const {
    return modelo;
}

void Auto::setModelo(const QString &value) {
    modelo = value;
}

QString Auto::getPatente() const {
    return patente;
}

void Auto::setPatente(const QString &value) {
    patente = value;
}

int Auto::getAnio() const {
    return anio;
}

void Auto::setAnio(int value) {
    anio = value;
}

QString Auto::getColor() const {
    return color;
}

void Auto::setColor(const QString &value) {
    color = value;
}

int Auto::getKilometraje() const {
    return kilometraje;
}

void Auto::setKilometraje(int value) {
    kilometraje = value;
}

double Auto::getPrecioPorDia() const {
    return precioPorDia;
}

void Auto::setPrecioPorDia(double value) {
    precioPorDia = value;
}

QString Auto::getEstado() const {
    return estado;
}

void Auto::setEstado(const QString &value) {
    estado = value;
}

QString Auto::getFechaIngreso() const {
    return fechaIngreso;
}

void Auto::setFechaIngreso(const QString &value) {
    fechaIngreso = value;
}