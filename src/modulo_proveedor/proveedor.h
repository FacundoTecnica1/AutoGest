#ifndef Proveedor_H
#define Proveedor_H
#include <QString>

class Proveedor {
private:
    int id_proveedor;
    QString nombre;
    QString telefono;
    QString email;
    QString direccion;

public:
    Proveedor();

    int getid_proveedor() const;
    void setid_proveedor(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

    QString getTelefono() const;
    void setTelefono(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getDireccion() const;
    void setDireccion(const QString &value);
};

#endif // Proveedor_H