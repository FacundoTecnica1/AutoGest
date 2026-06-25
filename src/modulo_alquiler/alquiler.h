#ifndef ALQUILER_H
#define ALQUILER_H
#include <QString>

class Alquiler {
private:
    int id_alquiler;
    int id_auto;
    int id_cliente;
    int id_usuario;
    QString metodoPago;
    QString fechaInicio;
    QString fechaFin;
    double precioTotal;
    QString estado;

public:
    Alquiler();
    Alquiler(int id_alquiler, int id_auto, int id_cliente, int id_usuario, QString metodoPago, QString fechaInicio, QString fechaFin, double precioTotal, QString estado);

    int getid_alquiler() const;
    void setid_alquiler(int value);

    int getid_auto() const;
    void setid_auto(int value);

    int getid_cliente() const;
    void setid_cliente(int value);

    int getid_usuario() const;
    void setid_usuario(int value);

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