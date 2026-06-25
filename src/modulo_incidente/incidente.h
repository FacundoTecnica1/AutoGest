#ifndef INCIDENTE_H
#define INCIDENTE_H
#include <QString>

class Incidente {
private:
    int idIncidente;
    int idAlquiler;
    QString tipoIncidente;
    QString fechaIncidente;
    QString descripcion;
    double costo;

public:
    Incidente();

    int getIdIncidente() const;
    void setIdIncidente(int value);

    int getIdAlquiler() const;
    void setIdAlquiler(int value);

    QString getTipoIncidente() const;
    void setTipoIncidente(const QString &value);

    QString getFechaIncidente() const;
    void setFechaIncidente(const QString &value);

    QString getDescripcion() const;
    void setDescripcion(const QString &value);

    double getCosto() const;
    void setCosto(double value);
};

#endif // INCIDENTE_H