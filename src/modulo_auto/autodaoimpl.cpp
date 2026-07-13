#include "autodaoimpl.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QString>
#include <vector>
using namespace std;

void AutoDAOImpl::insertar(Auto obj) {
    QSqlQuery query(QSqlDatabase::database());
    //inserta un nuevo auto en la tabla auto con su estado actual
    //el estado se deriva despues de la carga para que no quede desfasado
    query.prepare("INSERT INTO auto (marca, modelo, patente, anio, color, kilometraje, precio_por_dia, estado, fecha_ingreso) "
                  "VALUES (:marca, :modelo, :patente, :anio, :color, :kilometraje, :precio_por_dia, :estado, :fecha_ingreso)");
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":modelo", obj.getModelo());
    query.bindValue(":patente", obj.getPatente());
    query.bindValue(":anio", obj.getAnio());
    query.bindValue(":color", obj.getColor());
    query.bindValue(":kilometraje", obj.getKilometraje());
    query.bindValue(":precio_por_dia", obj.getPrecio_por_dia());
    query.bindValue(":estado", obj.getEstado().isEmpty() ? "Disponible" : obj.getEstado());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.exec();
}

void AutoDAOImpl::actualizar(Auto obj) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE auto SET marca = :marca, modelo = :modelo, patente = :patente, anio = :anio, color = :color, "
                  "kilometraje = :kilometraje, precio_por_dia = :precio_por_dia, fecha_ingreso = :fecha_ingreso "
                  "WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    query.bindValue(":marca", obj.getMarca());
    query.bindValue(":modelo", obj.getModelo());
    query.bindValue(":patente", obj.getPatente());
    query.bindValue(":anio", obj.getAnio());
    query.bindValue(":color", obj.getColor());
    query.bindValue(":kilometraje", obj.getKilometraje());
    query.bindValue(":precio_por_dia", obj.getPrecio_por_dia());
    query.bindValue(":fecha_ingreso", obj.getFechaIngreso());
    query.exec();
    sincronizarEstado(obj.getid_auto());
}

void AutoDAOImpl::eliminar(Auto obj) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    //se hace todo junto para no dejar datos a mitad de borrar
    if(!db.transaction()) return;

    //primero salen los incidentes que dependen de los alquileres del auto
    query.prepare("DELETE FROM incidente WHERE id_alquiler IN "
                  "(SELECT id_alquiler FROM alquiler WHERE id_auto = :id_auto)");
    query.bindValue(":id_auto", obj.getid_auto());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    //despues se borran los alquileres que todavia apuntan al auto
    query.prepare("DELETE FROM alquiler WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    //las autopartes se borran antes que sus mantenimientos por la clave foranea
    query.prepare("DELETE FROM autoparte WHERE id_mantenimiento IN "
                  "(SELECT id_mantenimiento FROM mantenimiento WHERE id_auto = :id_auto)");
    query.bindValue(":id_auto", obj.getid_auto());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    query.prepare("DELETE FROM mantenimiento WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    //cuando ya no queda ninguna referencia se puede borrar el auto tranquilo
    query.prepare("DELETE FROM auto WHERE id_auto = :id_auto");
    query.bindValue(":id_auto", obj.getid_auto());
    if(!query.exec()) {
        db.rollback();
        return;
    }

    if(!db.commit()) db.rollback();
}


vector<Auto> AutoDAOImpl::listar() {
    vector<Auto> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM auto");
    if(query.exec()) {
        while(query.next()) {
            Auto obj;
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setMarca(query.value("marca").toString());
            obj.setModelo(query.value("modelo").toString());
            obj.setPatente(query.value("patente").toString());
            obj.setAnio(query.value("anio").toInt());
            obj.setColor(query.value("color").toString());
            obj.setKilometraje(query.value("kilometraje").toInt());
            obj.setPrecio_por_dia(query.value("precio_por_dia").toDouble());
            obj.setEstado(calcularEstado(obj.getid_auto()));
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

vector<Auto> AutoDAOImpl::listarDisponiblesParaMantenimiento() {
    vector<Auto> lista;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM auto");
    if(query.exec()) {
        while(query.next()) {
            Auto obj;
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setMarca(query.value("marca").toString());
            obj.setModelo(query.value("modelo").toString());
            obj.setPatente(query.value("patente").toString());
            obj.setAnio(query.value("anio").toInt());
            obj.setColor(query.value("color").toString());
            obj.setKilometraje(query.value("kilometraje").toInt());
            obj.setPrecio_por_dia(query.value("precio_por_dia").toDouble());
            obj.setEstado(calcularEstado(obj.getid_auto()));
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            if(obj.getEstado() == "Disponible") {
                lista.push_back(obj);
            }
        }
    }
    return lista;
}

vector<Auto> AutoDAOImpl::listarDisponiblesParaAlquiler() {
    vector<Auto> lista;
    QSqlQuery query(QSqlDatabase::database());

    //el combo se arma con el estado guardado del auto
    //asi no se cuela uno alquilado o en mantenimiento
    query.prepare("SELECT a.* FROM auto a "
                  "WHERE LOWER(TRIM(a.estado)) = 'disponible' "
                  "ORDER BY a.marca, a.modelo, a.patente");
    if(query.exec()) {
        while(query.next()) {
            Auto obj;
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setMarca(query.value("marca").toString());
            obj.setModelo(query.value("modelo").toString());
            obj.setPatente(query.value("patente").toString());
            obj.setAnio(query.value("anio").toInt());
            obj.setColor(query.value("color").toString());
            obj.setKilometraje(query.value("kilometraje").toInt());
            obj.setPrecio_por_dia(query.value("precio_por_dia").toDouble());
            obj.setEstado("Disponible");
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

QString AutoDAOImpl::calcularEstado(int id_auto) {
    QSqlQuery query(QSqlDatabase::database());
    //si hay un alquiler activo para este auto, su estado debe ser Alquilado
    query.prepare("SELECT COUNT(*) FROM alquiler WHERE id_auto = :id_auto AND estado = 'activo'");
    query.bindValue(":id_auto", id_auto);
    if(query.exec() && query.next() && query.value(0).toInt() > 0) {
        return "Alquilado";
    }

    //si no esta alquilado pero hay un mantenimiento iniciado, lo marcamos en mantenimiento
    query.prepare("SELECT COUNT(*) FROM mantenimiento WHERE id_auto = :id_auto AND estado = 'iniciado'");
    query.bindValue(":id_auto", id_auto);
    if(query.exec() && query.next() && query.value(0).toInt() > 0) {
        return "En mantenimiento";
    }

    //si no hay ocupacion ni mantenimiento, el auto queda disponible
    return "Disponible";
}

vector<Auto> AutoDAOImpl::buscarCampo(const QString &busqueda) {
    vector<Auto> lista;
    QSqlQuery query(QSqlDatabase::database());

    //busca en todos los campos visibles del auto para que el filtro sea amplio
    query.prepare("SELECT * FROM auto WHERE id_auto LIKE :busqueda OR marca LIKE :busqueda "
                  "OR modelo LIKE :busqueda OR patente LIKE :busqueda OR anio LIKE :busqueda "
                  "OR color LIKE :busqueda OR kilometraje LIKE :busqueda OR precio_por_dia LIKE :busqueda "
                  "OR estado LIKE :busqueda OR fecha_ingreso LIKE :busqueda");
    query.bindValue(":busqueda", "%" + busqueda + "%");

    if(query.exec()) {
        while(query.next()) {
            Auto obj;
            obj.setid_auto(query.value("id_auto").toInt());
            obj.setMarca(query.value("marca").toString());
            obj.setModelo(query.value("modelo").toString());
            obj.setPatente(query.value("patente").toString());
            obj.setAnio(query.value("anio").toInt());
            obj.setColor(query.value("color").toString());
            obj.setKilometraje(query.value("kilometraje").toInt());
            obj.setPrecio_por_dia(query.value("precio_por_dia").toDouble());
            obj.setEstado(calcularEstado(obj.getid_auto()));
            obj.setFechaIngreso(query.value("fecha_ingreso").toString());
            lista.push_back(obj);
        }
    }
    return lista;
}

void AutoDAOImpl::sincronizarEstado(int id_auto) {
    QSqlQuery query(QSqlDatabase::database());
    QString estado = calcularEstado(id_auto);

    //actualiza el estado del auto a partir de la situacion real
    //de alquileres y mantenimientos vigentes en la base de datos
    query.prepare("UPDATE auto SET estado = :estado WHERE id_auto = :id_auto");
    query.bindValue(":estado", estado);
    query.bindValue(":id_auto", id_auto);
    query.exec();
}

void AutoDAOImpl::actualizarEstado(int id_auto, const QString& estado) {
    Q_UNUSED(estado);
    sincronizarEstado(id_auto);
}
