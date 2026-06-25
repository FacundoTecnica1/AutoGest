#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include <QString>

class Proveedor {
private:
    int idProveedor;
    QString nombre;
    QString telefono;
    QString email;
    QString direccion;

public:
    Proveedor();

    int getIdProveedor() const;
    void setIdProveedor(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

    QString getTelefono() const;
    void setTelefono(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getDireccion() const;
    void setDireccion(const QString &value);
};

#endif // PROVEEDOR_H