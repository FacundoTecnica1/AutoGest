#include "incidente.h"

Incidente::Incidente() {
    id_incidente = 0;
    id_alquiler = 0;
    tipoIncidente = "";
    fechaIncidente = "";
    descripcion = "";
    costo = 0.0;
}

int Incidente::getid_incidente() const {
    return id_incidente;
}

void Incidente::setid_incidente(int value) {
    id_incidente = value;
}

int Incidente::getid_alquiler() const {
    return id_alquiler;
}

void Incidente::setid_alquiler(int value) {
    id_alquiler = value;
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