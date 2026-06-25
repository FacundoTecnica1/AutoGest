#include "mantenimiento.h"

Mantenimiento::Mantenimiento() {
    idMantenimiento = 0;
    idAuto = 0;
    idTipoMantenimiento = 0;
    fechaIngreso = "";
    fechaSalida = "";
    observaciones = "";
    costo = 0.0;
    estado = "";
}

int Mantenimiento::getIdMantenimiento() const {
    return idMantenimiento;
}

void Mantenimiento::setIdMantenimiento(int value) {
    idMantenimiento = value;
}

int Mantenimiento::getIdAuto() const {
    return idAuto;
}

void Mantenimiento::setIdAuto(int value) {
    idAuto = value;
}

int Mantenimiento::getIdTipoMantenimiento() const {
    return idTipoMantenimiento;
}

void Mantenimiento::setIdTipoMantenimiento(int value) {
    idTipoMantenimiento = value;
}

QString Mantenimiento::getFechaIngreso() const {
    return fechaIngreso;
}

void Mantenimiento::setFechaIngreso(const QString &value) {
    fechaIngreso = value;
}

QString Mantenimiento::getFechaSalida() const {
    return fechaSalida;
}

void Mantenimiento::setFechaSalida(const QString &value) {
    fechaSalida = value;
}

QString Mantenimiento::getObservaciones() const {
    return observaciones;
}

void Mantenimiento::setObservaciones(const QString &value) {
    observaciones = value;
}

double Mantenimiento::getCosto() const {
    return costo;
}

void Mantenimiento::setCosto(double value) {
    costo = value;
}

QString Mantenimiento::getEstado() const {
    return estado;
}

void Mantenimiento::setEstado(const QString &value) {
    estado = value;
}