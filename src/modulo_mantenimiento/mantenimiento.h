#ifndef MANTENIMIENTO_H
#define MANTENIMIENTO_H
#include <QString>

class Mantenimiento {
private:
    int idMantenimiento;
    int idAuto;
    int idTipoMantenimiento;
    QString fechaIngreso;
    QString fechaSalida;
    QString observaciones;
    double costo;
    QString estado;

public:
    Mantenimiento();

    int getIdMantenimiento() const;
    void setIdMantenimiento(int value);

    int getIdAuto() const;
    void setIdAuto(int value);

    int getIdTipoMantenimiento() const;
    void setIdTipoMantenimiento(int value);

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

#endif // MANTENIMIENTO_H