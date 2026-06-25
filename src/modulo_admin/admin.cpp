#include "admin.h"

//Inicializamos las variables sin nada, para crear el objeto vacío
Admin::Admin() {
    id_admin = 0;
    user = "";
    password = "";
}

Admin::Admin(int id_admin, QString user, QString password) {
    this->id_admin = id_admin;
    this->user = user;
    this->password = password;
//Indico con el this las variables privadas, y después
//EL valor que se les va a pasar a cada una
}

//Los get devuelven lo que valen las variables

int Admin::getid_admin() const {
    return id_admin;
}

void Admin::setid_admin(int value) {
    id_admin = value; //Value es lo que el usuario escribio
}

QString Admin::getUser() const {
    return user;
}

void Admin::setUser(const QString &value) {
    user = value;
}

QString Admin::getPassword() const {
    return password;
}

void Admin::setPassword(const QString &value) {
    password = value;
}