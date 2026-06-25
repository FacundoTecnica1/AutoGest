#ifndef AUTO_H
#define AUTO_H
#include <QString>

class Auto {
private:
    int idAuto;
    QString marca;
    QString modelo;
    QString patente;
    int anio;
    QString color;
    int kilometraje;
    double precioPorDia;
    QString estado;
    QString fechaIngreso;

public:
    Auto();

    int getIdAuto() const;
    void setIdAuto(int value);

    QString getMarca() const;
    void setMarca(const QString &value);

    QString getModelo() const;
    void setModelo(const QString &value);

    QString getPatente() const;
    void setPatente(const QString &value);

    int getAnio() const;
    void setAnio(int value);

    QString getColor() const;
    void setColor(const QString &value);

    int getKilometraje() const;
    void setKilometraje(int value);

    double getPrecioPorDia() const;
    void setPrecioPorDia(double value);

    QString getEstado() const;
    void setEstado(const QString &value);

    QString getFechaIngreso() const;
    void setFechaIngreso(const QString &value);
};

#endif // AUTO_H