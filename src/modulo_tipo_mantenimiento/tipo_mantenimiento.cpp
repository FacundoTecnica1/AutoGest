#include "tipo_mantenimiento.h"

TipoMantenimiento::TipoMantenimiento() {
    idTipoMantenimiento = 0;
    nombre = "";
}

int TipoMantenimiento::getIdTipoMantenimiento() const {
    return idTipoMantenimiento;
}

void TipoMantenimiento::setIdTipoMantenimiento(int value) {
    idTipoMantenimiento = value;
}

QString TipoMantenimiento::getNombre() const {
    return nombre;
}

void TipoMantenimiento::setNombre(const QString &value) {
    nombre = value;
}