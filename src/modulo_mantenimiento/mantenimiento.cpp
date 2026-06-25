#include "Mantenimiento.h"

Mantenimiento::Mantenimiento() {
    id_Mantenimiento = 0;
    id_auto = 0;
    id_tipo_Mantenimiento = 0;
    fechaIngreso = "";
    fechaSalida = "";
    observaciones = "";
    costo = 0.0;
    estado = "";
}

int Mantenimiento::getid_Mantenimiento() const {
    return id_Mantenimiento;
}

void Mantenimiento::setid_Mantenimiento(int value) {
    id_Mantenimiento = value;
}

int Mantenimiento::getid_auto() const {
    return id_auto;
}

void Mantenimiento::setid_auto(int value) {
    id_auto = value;
}

int Mantenimiento::getid_tipo_Mantenimiento() const {
    return id_tipo_Mantenimiento;
}

void Mantenimiento::setid_tipo_Mantenimiento(int value) {
    id_tipo_Mantenimiento = value;
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