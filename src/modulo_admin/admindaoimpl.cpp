#include "admindaoimpl.h"
#include "conexion.h"
#include "../modulo_auto/autodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>

using namespace std;

void AdminDAOImpl::insertar(Admin obj) {
    QSqlQuery query(QSqlDatabase::database());
    //insertar en la tabla admin con rol incluido
    query.prepare("INSERT INTO admin (user, password, rol) VALUES (:user, :password, :rol)");
    query.bindValue(":user", obj.getUser());
    query.bindValue(":password", obj.getPassword());
    query.bindValue(":rol", obj.getRol());
    query.exec();
}

void AdminDAOImpl::actualizar(Admin obj) {
    QSqlQuery query(QSqlDatabase::database());
    //actualiza usuario, contraseña y rol mediante id_admin
    query.prepare("UPDATE admin SET user = :user, password = :password, rol = :rol WHERE id_admin = :id_admin");
    query.bindValue(":user", obj.getUser());
    query.bindValue(":password", obj.getPassword());
    query.bindValue(":rol", obj.getRol());
    query.bindValue(":id_admin", obj.getid_usuario());
    query.exec();
}

void AdminDAOImpl::eliminar(Admin obj) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    vector<int> autosAfectados;

    //guardamos los autos de sus alquileres para acomodar el estado despues
    query.prepare("SELECT DISTINCT id_auto FROM alquiler WHERE id_usuario = :id_admin");
    query.bindValue(":id_admin", obj.getid_usuario());
    if(query.exec()) {
        while(query.next()) autosAfectados.push_back(query.value(0).toInt());
    }
    query.finish();

    //primero se limpian los registros que dependen del usuario
    if(!db.transaction()) return;

    query.prepare("DELETE FROM incidente WHERE id_alquiler IN "
                  "(SELECT id_alquiler FROM alquiler WHERE id_usuario = :id_admin)");
    query.bindValue(":id_admin", obj.getid_usuario());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    query.prepare("DELETE FROM alquiler WHERE id_usuario = :id_admin");
    query.bindValue(":id_admin", obj.getid_usuario());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    //sin alquileres relacionados ya se puede borrar el usuario
    query.prepare("DELETE FROM admin WHERE id_admin = :id_admin");
    query.bindValue(":id_admin", obj.getid_usuario());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    if(!db.commit()) {
        db.rollback();
        return;
    }

    AutoDAOImpl autoDao;
    for(int idAuto : autosAfectados) autoDao.sincronizarEstado(idAuto);
}


vector<Admin> AdminDAOImpl::listar() {
    vector<Admin> lista;
    QSqlQuery query(QSqlDatabase::database());
    //lista todos los usuarios y recupera el rol para cada uno
    query.prepare("SELECT id_admin, user, password, rol FROM admin");
    if(query.exec()) {
        while(query.next()) {
            Admin obj;
            obj.setid_usuario(query.value("id_admin").toInt());
            obj.setUser(query.value("user").toString());
            obj.setPassword(query.value("password").toString());
            obj.setRol(query.value("rol").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}



bool AdminDAOImpl::validarLogin(const QString &user, const QString &password, QString &rol) {

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    //buscamos usuario y rol en la tabla admin
    //el rol se devuelve para que la aplicacion pueda aplicar restricciones
    query.prepare("SELECT id_admin, rol FROM admin WHERE user = ? AND password = ?");
    query.addBindValue(user);
    query.addBindValue(password);

    if (!query.exec()) {
        qDebug() << "Error al consultar el login:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        rol = query.value("rol").toString();
        return true;
    }

    return false;
}
