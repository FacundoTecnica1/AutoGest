#ifndef CLIENTE_H
#define CLIENTE_H
#include <QString>

class Cliente {
private:
    int id_cliente;
    QString nombre;
    QString apellido;
    int edad;
    QString dni;
    QString telefono;
    QString email;
    QString direccion;
    QString claseLicencia;
    QString fechaRegistro;

public:
    Cliente();

    int getid_cliente() const;
    void setid_cliente(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

    QString getApellido() const;
    void setApellido(const QString &value);

    int getEdad() const;
    void setEdad(int value);

    QString getDni() const;
    void setDni(const QString &value);

    QString getTelefono() const;
    void setTelefono(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getDireccion() const;
    void setDireccion(const QString &value);

    QString getClaseLicencia() const;
    void setClaseLicencia(const QString &value);

    QString getFechaRegistro() const;
    void setFechaRegistro(const QString &value);
};

#endif // CLIENTE_H