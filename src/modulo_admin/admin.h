#ifndef ADMIN_H
#define ADMIN_H
#include <QString>

class Admin {
private:
    int id_admin;
    QString user;
    QString password;

public:

    //Creo dos constructores, uno sin nada
    //y el otro con los parametros que va a recibir
    Admin();
    Admin(int id_admin, QString user, QString password);

    int getid_admin() const;
    void setid_admin(int value); //En value se va a guardar lo que ingreso el usuario

    QString getUser() const;
    void setUser(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);
};

#endif // ADMIN_H