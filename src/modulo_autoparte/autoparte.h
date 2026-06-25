#ifndef AUTOPARTE_H
#define AUTOPARTE_H
#include <QString>

class Autoparte {
private:
    int id_autoparte;
    int id_proveedor;
    int id_Mantenimiento;
    QString nombre;
    QString marca;
    double precio;
    int stock;

public:
    Autoparte();

    int getid_autoparte() const;
    void setid_autoparte(int value);

    int getid_proveedor() const;
    void setid_proveedor(int value);

    int getid_Mantenimiento() const;
    void setid_Mantenimiento(int value);

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