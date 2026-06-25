#ifndef TIPO_MANTENIMIENTO_H
#define TIPO_MANTENIMIENTO_H
#include <QString>

class TipoMantenimiento {
private:
    int idTipoMantenimiento;
    QString nombre;

public:
    TipoMantenimiento();

    int getIdTipoMantenimiento() const;
    void setIdTipoMantenimiento(int value);

    QString getNombre() const;
    void setNombre(const QString &value);
};

#endif // TIPO_MANTENIMIENTO_H