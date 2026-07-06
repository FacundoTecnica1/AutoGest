#ifndef ALQUILERDAOIMPL_H
#define ALQUILERDAOIMPL_H
#include "alquilerdao.h"
#include <QString>

using namespace std;

class AlquilerDAOImpl : public AlquilerDAO {
public:
    void insertar(Alquiler obj);
    void actualizar(Alquiler obj);
    void eliminar(Alquiler obj);
    vector<vector<QString>> listar();
    vector<vector<QString>> buscarCampo(const QString &busqueda);
    double calcularTotal(int id_auto, const QString& fechaInicio, const QString& fechaFin);
    bool autoDisponibleParaAlquiler(int id_auto, const QString& fechaInicio, const QString& fechaFin, int id_alquilerIgnorar = -1);
    bool mantenimientoFinalizado(int id_auto);
    //sirve para calcular cuanto costara el precio del alquiler
};

#endif // ALQUILERDAOIMPL_H
