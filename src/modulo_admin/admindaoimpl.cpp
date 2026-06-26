#include "admindaoimpl.h"
#include "conexion.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>

using namespace std;

void AdminDAOImpl::insertar(Admin obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO admin (user, password) VALUES (:user, :password)");
    query.bindValue(":user", obj.getUser());
    query.bindValue(":password", obj.getPassword());
    query.exec();
}

void AdminDAOImpl::actualizar(Admin obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE admin SET user = :user, password = :password WHERE id_admin = :id_admin");
    query.bindValue(":user", obj.getUser());
    query.bindValue(":password", obj.getPassword());
    query.bindValue(":id_admin", obj.getid_admin());
    query.exec();
}

void AdminDAOImpl::eliminar(Admin obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM admin WHERE id_admin = :id_admin");
    query.bindValue(":id_admin", obj.getid_admin());
    query.exec();
}


vector<Admin> AdminDAOImpl::listar() {
    vector<Admin> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM admin");
    if(query.exec()) {
        while(query.next()) {
            Admin obj;
            obj.setid_admin(query.value("id_admin").toInt());
            obj.setUser(query.value("user").toString());
            obj.setPassword(query.value("password").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}



bool AdminDAOImpl::validarLogin(const QString &user, const QString &password) {

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    // Buscamos un registro donde coincidan usuario y contraseña
    query.prepare("SELECT id_admin FROM admin WHERE user = ? AND password = ?");
    query.addBindValue(user);
    query.addBindValue(password);

    if (!query.exec()) {
        qDebug() << "Error al consultar el login:" << query.lastError().text();
        return false;
    }

    // Si query.next() devuelve true, significa que encontró una fila que coincide
    if (query.next()) {
        return true;
    }

    // Si no encontró nada, devuelve false
    return false;
}