#include "alquilerdaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
using namespace std;

void AlquilerDAOImpl::insertar(Alquiler obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO alquiler (id_auto, id_cliente, id_usuario, metodo_pago, fecha_inicio, fecha_fin, precio_total, estado) "
                  "VALUES (:id_auto, :id_cliente, :id_usuario, :metodo_pago, :fecha_inicio, :fecha_fin, :precio_total, :estado)");
    query.bindValue(":id_auto", obj.getIdAuto());
    query.bindValue(":id_cliente", obj.getIdCliente());
    query.bindValue(":id_usuario", obj.getIdUsuario());
    query.bindValue(":metodo_pago", obj.getMetodoPago());
    query.bindValue(":fecha_inicio", obj.getFechaInicio());
    query.bindValue(":fecha_fin", obj.getFechaFin());
    query.bindValue(":precio_total", obj.getPrecioTotal());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void AlquilerDAOImpl::actualizar(Alquiler obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE alquiler SET id_auto = :id_auto, id_cliente = :id_cliente, id_usuario = :id_usuario, metodo_pago = :metodo_pago, "
                  "fecha_inicio = :fecha_inicio, fecha_fin = :fecha_fin, precio_total = :precio_total, estado = :estado WHERE id_alquiler = :id_alquiler");
    query.bindValue(":id_alquiler", obj.getIdAlquiler());
    query.bindValue(":id_auto", obj.getIdAuto());
    query.bindValue(":id_cliente", obj.getIdCliente());
    query.bindValue(":id_usuario", obj.getIdUsuario());
    query.bindValue(":metodo_pago", obj.getMetodoPago());
    query.bindValue(":fecha_inicio", obj.getFechaInicio());
    query.bindValue(":fecha_fin", obj.getFechaFin());
    query.bindValue(":precio_total", obj.getPrecioTotal());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void AlquilerDAOImpl::eliminar(Alquiler obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM alquiler WHERE id_alquiler = :id_alquiler");
    query.bindValue(":id_alquiler", obj.getIdAlquiler());
    query.exec();
}

Alquiler AlquilerDAOImpl::buscarPorId(int id) {
    Alquiler obj;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM alquiler WHERE id_alquiler = :id_alquiler");
    query.bindValue(":id_alquiler", id);
    if(query.exec()) {
        if(query.next()) {
            obj.setIdAlquiler(query.value("id_alquiler").toInt());
            obj.setIdAuto(query.value("id_auto").toInt());
            obj.setIdCliente(query.value("id_cliente").toInt());
            obj.setIdUsuario(query.value("id_usuario").toInt());
            obj.setMetodoPago(query.value("metodo_pago").toString());
            obj.setFechaInicio(query.value("fecha_inicio").toString());
            obj.setFechaFin(query.value("fecha_fin").toString());
            obj.setPrecioTotal(query.value("precio_total").toDouble());
            obj.setEstado(query.value("estado").toString());
        }
    }
    return obj;
}

vector<Alquiler> AlquilerDAOImpl::listar() {
    vector<Alquiler> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM alquiler");
    if(query.exec()) {
        while(query.next()) {
            Alquiler obj;
            obj.setIdAlquiler(query.value("id_alquiler").toInt());
            obj.setIdAuto(query.value("id_auto").toInt());
            obj.setIdCliente(query.value("id_cliente").toInt());
            obj.setIdUsuario(query.value("id_usuario").toInt());
            obj.setMetodoPago(query.value("metodo_pago").toString());
            obj.setFechaInicio(query.value("fecha_inicio").toString());
            obj.setFechaFin(query.value("fecha_fin").toString());
            obj.setPrecioTotal(query.value("precio_total").toDouble());
            obj.setEstado(query.value("estado").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}