#ifndef TIPO_Mantenimiento_H
#define TIPO_Mantenimiento_H
#include <QString>

class TipoMantenimiento {
private:
    int id_tipo_Mantenimiento;
    QString nombre;

public:
    TipoMantenimiento();

    int getid_tipo_Mantenimiento() const;
    void setid_tipo_Mantenimiento(int value);

    QString getNombre() const;
    void setNombre(const QString &value);
};

#endif // TIPO_Mantenimiento_H