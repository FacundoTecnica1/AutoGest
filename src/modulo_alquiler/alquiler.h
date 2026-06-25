#ifndef ALQUILER_H
#define ALQUILER_H
#include <QString>

class Alquiler {
private:
    int idAlquiler;
    int idAuto;
    int idCliente;
    int idUsuario;
    QString metodoPago;
    QString fechaInicio;
    QString fechaFin;
    double precioTotal;
    QString estado;

public:
    Alquiler();
    Alquiler(int idAlquiler, int idAuto, int idCliente, int idUsuario, QString metodoPago, QString fechaInicio, QString fechaFin, double precioTotal, QString estado);

    int getIdAlquiler() const;
    void setIdAlquiler(int value);

    int getIdAuto() const;
    void setIdAuto(int value);

    int getIdCliente() const;
    void setIdCliente(int value);

    int getIdUsuario() const;
    void setIdUsuario(int value);

    QString getMetodoPago() const;
    void setMetodoPago(const QString &value);

    QString getFechaInicio() const;
    void setFechaInicio(const QString &value);

    QString getFechaFin() const;
    void setFechaFin(const QString &value);

    double getPrecioTotal() const;
    void setPrecioTotal(double value);

    QString getEstado() const;
    void setEstado(const QString &value);
};

#endif // ALQUILER_H