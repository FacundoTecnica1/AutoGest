#include "autopartedaoimpl.h"
#include "autodaoimpl.h"
#include "auto.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
using namespace std;

void AutoparteDAOImpl::insertar(Autoparte obj) {
    QSqlQuery query(QSqlDatabase::database());
    //arreglo los nombres de las keys foraneas
    //para meter datos en autoparte
    query.prepare("INSERT INTO autoparte (id_proveedor, id_mantenimiento, nombre, marca, precio, stock) "
                  "VALUES (:id_proveedor, :id_mantenimiento, :nombre, :marca, :precio, :stock)");
    query.bindValue(":id_proveedor", obj.getid_proveedor());
    query.bindValue(":id_mantenimiento", obj.getid_Mantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":precio", obj.getPrecio());
    query.bindValue(":stock", obj.getStock());
    query.exec();
}

void AutoparteDAOImpl::actualizar(Autoparte obj) {
    QSqlQuery query(QSqlDatabase::database());
    //ajusto el update quitando backticks
    //y espacios fantasma
    query.prepare("UPDATE autoparte SET id_proveedor = :id_proveedor, id_mantenimiento = :id_mantenimiento, nombre = :nombre, "
                  "marca = :marca, precio = :precio, stock = :stock WHERE id_autoparte = :id_autoparte");
    query.bindValue(":id_autoparte", obj.getid_autoparte());
    query.bindValue(":id_proveedor", obj.getid_proveedor());
    query.bindValue(":id_mantenimiento", obj.getid_Mantenimiento());
    query.bindValue(":nombre", obj.getNombre());
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":precio", obj.getPrecio());
    query.bindValue(":stock", obj.getStock());
    query.exec();
}

void AutoparteDAOImpl::eliminar(Autoparte obj) {
    QSqlQuery query(QSqlDatabase::database());
    //escribo id_autoparte de manera correcta
    //asi puede hacer match con el registro
    query.prepare("DELETE FROM autoparte WHERE id_autoparte = :id_autoparte");
    query.bindValue(":id_autoparte", obj.getid_autoparte());
    query.exec();
}

vector<Autoparte> AutoparteDAOImpl::listar() {
    vector<Autoparte> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM autoparte");
    if(query.exec()) {
        while(query.next()) {
            Autoparte obj;
            //hago coincidir los names de los values
            //asi pobla la tabla piola
            obj.setid_autoparte(query.value("id_autoparte").toInt());
            obj.setid_proveedor(query.value("id_proveedor").toInt());
            obj.setid_Mantenimiento(query.value("id_mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setMarca(query.value("marca").toString());
            obj.setPrecio(query.value("precio").toDouble());
            obj.setStock(query.value("stock").toInt());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<Autoparte> AutoparteDAOImpl::buscarCampo(const QString &busqueda) {
    vector<Autoparte> lista;
    QSqlQuery query(QSqlDatabase::database());

    //corrijo las columnas del select
    //para buscar bien el string
    query.prepare("SELECT * FROM autoparte WHERE id_autoparte LIKE :busqueda OR id_proveedor LIKE :busqueda "
                  "OR id_mantenimiento LIKE :busqueda OR nombre LIKE :busqueda OR marca LIKE :busqueda "
                  "OR precio LIKE :busqueda OR stock LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            Autoparte obj;
            obj.setid_autoparte(query.value("id_autoparte").toInt());
            obj.setid_proveedor(query.value("id_proveedor").toInt());
            obj.setid_Mantenimiento(query.value("id_mantenimiento").toInt());
            obj.setNombre(query.value("nombre").toString());
            obj.setMarca(query.value("marca").toString());
            obj.setPrecio(query.value("precio").toDouble());
            obj.setStock(query.value("stock").toInt());
            lista.push_back(obj);
        }
    }
    return lista;
}