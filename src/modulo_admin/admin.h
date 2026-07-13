#ifndef ADMIN_H
#define ADMIN_H
#include <QString>

class Admin {
private:
    int id_usuario;
    QString user;
    QString password;
    QString rol;

public:
    Admin();
    Admin(int id_usuario, QString user, QString password, QString rol);

    int getid_usuario() const;
    void setid_usuario(int value);

    QString getUser() const;
    void setUser(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    QString getRol() const;
    void setRol(const QString &value);
};

#endif // ADMIN_H