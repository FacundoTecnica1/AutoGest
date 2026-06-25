#ifndef Mantenimiento_H
#define Mantenimiento_H
#include <QString>

class Mantenimiento {
private:
    int id_Mantenimiento;
    int id_auto;
    int id_tipo_Mantenimiento;
    QString fechaIngreso;
    QString fechaSalida;
    QString observaciones;
    double costo;
    QString estado;

public:
    Mantenimiento();

    int getid_Mantenimiento() const;
    void setid_Mantenimiento(int value);

    int getid_auto() const;
    void setid_auto(int value);

    int getid_tipo_Mantenimiento() const;
    void setid_tipo_Mantenimiento(int value);

    QString getFechaIngreso() const;
    void setFechaIngreso(const QString &value);

    QString getFechaSalida() const;
    void setFechaSalida(const QString &value);

    QString getObservaciones() const;
    void setObservaciones(const QString &value);

    double getCosto() const;
    void setCosto(double value);

    QString getEstado() const;
    void setEstado(const QString &value);
};

#endif // Mantenimiento_H