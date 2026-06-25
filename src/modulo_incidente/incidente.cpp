#include "incidente.h"

Incidente::Incidente() {
    idIncidente = 0;
    idAlquiler = 0;
    tipoIncidente = "";
    fechaIncidente = "";
    descripcion = "";
    costo = 0.0;
}

int Incidente::getIdIncidente() const {
    return idIncidente;
}

void Incidente::setIdIncidente(int value) {
    idIncidente = value;
}

int Incidente::getIdAlquiler() const {
    return idAlquiler;
}

void Incidente::setIdAlquiler(int value) {
    idAlquiler = value;
}

QString Incidente::getTipoIncidente() const {
    return tipoIncidente;
}

void Incidente::setTipoIncidente(const QString &value) {
    tipoIncidente = value;
}

QString Incidente::getFechaIncidente() const {
    return fechaIncidente;
}

void Incidente::setFechaIncidente(const QString &value) {
    fechaIncidente = value;
}

QString Incidente::getDescripcion() const {
    return descripcion;
}

void Incidente::setDescripcion(const QString &value) {
    descripcion = value;
}

double Incidente::getCosto() const {
    return costo;
}

void Incidente::setCosto(double value) {
    costo = value;
}