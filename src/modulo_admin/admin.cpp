#include "admin.h"

Admin::Admin() {
    idAdmin = 0;
    user = "";
    password = "";
}

Admin::Admin(int idAdmin, QString user, QString password) {
    this->idAdmin = idAdmin;
    this->user = user;
    this->password = password;
}

int Admin::getIdAdmin() const {
    return idAdmin;
}

void Admin::setIdAdmin(int value) {
    idAdmin = value;
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