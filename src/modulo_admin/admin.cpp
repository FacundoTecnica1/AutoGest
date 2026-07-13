#include "admin.h"

//inicializamos el objeto de usuario con valores por defecto
Admin::Admin() {
    id_usuario = 0;
    user = "";
    password = "";
    rol = "";
}

Admin::Admin(int id_usuario, QString user, QString password, QString rol) {
    this->id_usuario = id_usuario;
    this->user = user;
    this->password = password;
    this->rol = rol;
}

int Admin::getid_usuario() const {
    return id_usuario;
}

void Admin::setid_usuario(int value) {
    id_usuario = value;
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

QString Admin::getRol() const {
    return rol;
}

void Admin::setRol(const QString &value) {
    rol = value;
}