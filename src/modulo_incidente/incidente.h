#ifndef INCIDENTE_H
#define INCIDENTE_H
#include <QString>

class Incidente {
private:
    int id_incidente;
    int id_alquiler;
    QString tipoIncidente;
    QString fechaIncidente;
    QString descripcion;
    double costo;

public:
    Incidente();

    int getid_incidente() const;
    void setid_incidente(int value);

    int getid_alquiler() const;
    void setid_alquiler(int value);

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