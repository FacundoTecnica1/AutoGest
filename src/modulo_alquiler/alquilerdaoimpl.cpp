#include "alquilerdaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <QDate>
#include <vector>

using namespace std;

void AlquilerDAOImpl::insertar(Alquiler obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO alquiler (id_auto, id_cliente, id_usuario, metodo_pago, fecha_inicio, fecha_fin, precio_total, estado) "
                  "VALUES (:id_auto, :id_cliente, :id_usuario, :metodo_pago, :fecha_inicio, :fecha_fin, :precio_total, :estado)");
    query.bindValue(":id_auto", obj.getid_auto());
    query.bindValue(":id_cliente", obj.getid_cliente());
    query.bindValue(":id_usuario", obj.getid_usuario());
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
    query.bindValue(":id_alquiler", obj.getid_alquiler());
    query.bindValue(":id_auto", obj.getid_auto());
    query.bindValue(":id_cliente", obj.getid_cliente());
    query.bindValue(":id_usuario", obj.getid_usuario());
    query.bindValue(":metodo_pago", obj.getMetodoPago());
    query.bindValue(":fecha_inicio", obj.getFechaInicio());
    query.bindValue(":fecha_fin", obj.getFechaFin());
    query.bindValue(":precio_total", obj.getPrecioTotal());
    query.bindValue(":estado", obj.getEstado());
    query.exec();
}

void AlquilerDAOImpl::eliminar(Alquiler obj) {
    QSqlQuery query(QSqlDatabase::database());

    //primero borramos dependencias en incidentes para evitar el error de Foreign Key
    query.prepare("DELETE FROM incidente WHERE id_alquiler = :id_alquiler");
    query.bindValue(":id_alquiler", obj.getid_alquiler());
    query.exec();

    //ahora sí borramos el alquiler sin problema
    query.prepare("DELETE FROM alquiler WHERE id_alquiler = :id_alquiler");
    query.bindValue(":id_alquiler", obj.getid_alquiler());
    query.exec();
}

vector<vector<QString>> AlquilerDAOImpl::listar() {
    vector<vector<QString>> lista;
    QSqlQuery q(QSqlDatabase::database());
    q.prepare("SELECT alq.id_alquiler, alq.id_auto, alq.id_cliente, a.marca, a.modelo, a.patente, c.nombre, c.apellido, "
              "alq.metodo_pago, alq.fecha_inicio, alq.fecha_fin, alq.precio_total, alq.estado "
              "FROM alquiler alq "
              "INNER JOIN auto a ON alq.id_auto = a.id_auto "
              "INNER JOIN cliente c ON alq.id_cliente = c.id_cliente");

    if(q.exec()) {
        while(q.next()) {
            vector<QString> fila;
            fila.push_back(q.value(0).toString()); // ID
            fila.push_back(q.value(1).toString()); // ID auto
            fila.push_back(q.value(2).toString()); // ID cliente
            fila.push_back(q.value(3).toString() + " " + q.value(4).toString() + " (" + q.value(5).toString() + ")"); // Auto
            fila.push_back(q.value(6).toString() + " " + q.value(7).toString()); // Cliente
            fila.push_back(q.value(8).toString()); // Metodo
            fila.push_back(q.value(9).toString()); // Inicio
            fila.push_back(q.value(10).toString()); // Fin
            fila.push_back(q.value(11).toString()); // Total
            fila.push_back(q.value(12).toString()); // Estado
            lista.push_back(fila);
        }
    }
    return lista;
}

vector<vector<QString>> AlquilerDAOImpl::buscarCampo(const QString &busqueda) {
    vector<vector<QString>> lista;
    QSqlQuery q(QSqlDatabase::database());
    // Hacemos el JOIN e incluimos todos los campos en el WHERE para que busque por cualquier lado
    q.prepare("SELECT alq.id_alquiler, alq.id_auto, alq.id_cliente, a.marca, a.modelo, a.patente, c.nombre, c.apellido, "
              "alq.metodo_pago, alq.fecha_inicio, alq.fecha_fin, alq.precio_total, alq.estado "
              "FROM alquiler alq "
              "INNER JOIN auto a ON alq.id_auto = a.id_auto "
              "INNER JOIN cliente c ON alq.id_cliente = c.id_cliente "
              "WHERE alq.id_alquiler LIKE :busqueda OR a.marca LIKE :busqueda OR a.modelo LIKE :busqueda "
              "OR a.patente LIKE :busqueda OR c.nombre LIKE :busqueda OR c.apellido LIKE :busqueda "
              "OR alq.metodo_pago LIKE :busqueda OR alq.fecha_inicio LIKE :busqueda "
              "OR alq.fecha_fin LIKE :busqueda OR alq.precio_total LIKE :busqueda OR alq.estado LIKE :busqueda");

    q.bindValue(":busqueda", "%" + busqueda + "%");

    if(q.exec()) {
        while(q.next()) {
            vector<QString> fila;
            fila.push_back(q.value(0).toString());
            fila.push_back(q.value(1).toString());
            fila.push_back(q.value(2).toString());
            fila.push_back(q.value(3).toString() + " " + q.value(4).toString() + " (" + q.value(5).toString() + ")");
            fila.push_back(q.value(6).toString() + " " + q.value(7).toString());
            fila.push_back(q.value(8).toString());
            fila.push_back(q.value(9).toString());
            fila.push_back(q.value(10).toString());
            fila.push_back(q.value(11).toString());
            fila.push_back(q.value(12).toString());
            lista.push_back(fila);
        }
    }
    return lista;
}




double AlquilerDAOImpl::calcularTotal(int id_auto, const QString& fechaInicio, const QString& fechaFin) {
    QDate inicio = QDate::fromString(fechaInicio, "yyyy-MM-dd");
    QDate fin = QDate::fromString(fechaFin, "yyyy-MM-dd");

    int dias = inicio.daysTo(fin);
    if(dias <= 0) dias = 1;

    double precioDia = 0.0;
    QSqlQuery q(QSqlDatabase::database());
    q.prepare("SELECT precio_por_dia FROM auto WHERE id_auto = :id_auto");
    q.bindValue(":id_auto", id_auto);

    if(q.exec() && q.next()) {
        precioDia = q.value(0).toDouble();
    }

    return dias * precioDia;
}
