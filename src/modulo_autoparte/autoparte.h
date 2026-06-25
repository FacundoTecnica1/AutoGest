#ifndef AUTOPARTE_H
#define AUTOPARTE_H
#include <QString>

class Autoparte {
private:
    int idAutoparte;
    int idProveedor;
    int idMantenimiento;
    QString nombre;
    QString marca;
    double precio;
    int stock;

public:
    Autoparte();

    int getIdAutoparte() const;
    void setIdAutoparte(int value);

    int getIdProveedor() const;
    void setIdProveedor(int value);

    int getIdMantenimiento() const;
    void setIdMantenimiento(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

    QString getMarca() const;
    void setMarca(const QString &value);

    double getPrecio() const;
    void setPrecio(double value);

    int getStock() const;
    void setStock(int value);
};

#endif // AUTOPARTE_H