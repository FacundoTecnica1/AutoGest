#include "tipo_Mantenimiento.h"

TipoMantenimiento::TipoMantenimiento() {
    id_tipo_Mantenimiento = 0;
    nombre = "";
}

int TipoMantenimiento::getid_tipo_Mantenimiento() const {
    return id_tipo_Mantenimiento;
}

void TipoMantenimiento::setid_tipo_Mantenimiento(int value) {
    id_tipo_Mantenimiento = value;
}

QString TipoMantenimiento::getNombre() const {
    return nombre;
}

void TipoMantenimiento::setNombre(const QString &value) {
    nombre = value;
}