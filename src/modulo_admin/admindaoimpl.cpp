#include "admindaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
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
    query.bindValue(":id_admin", obj.getIdAdmin());
    query.exec();
}

void AdminDAOImpl::eliminar(Admin obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM admin WHERE id_admin = :id_admin");
    query.bindValue(":id_admin", obj.getIdAdmin());
    query.exec();
}

Admin AdminDAOImpl::buscarPorId(int id) {
    Admin obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM admin WHERE id_admin = :id_admin");
    query.bindValue(":id_admin", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setIdAdmin(query.value("id_admin").toInt());
            obj.setUser(query.value("user").toString());
            obj.setPassword(query.value("password").toString());
        }
    }
    return obj;
}

vector<Admin> AdminDAOImpl::listar() {
    vector<Admin> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM admin");
    if(query.exec()) {
        while(query.next()) {
            Admin obj;
            obj.setIdAdmin(query.value("id_admin").toInt());
            obj.setUser(query.value("user").toString());
            obj.setPassword(query.value("password").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}