#ifndef INCIDENTEDAOIMPL_H
#define INCIDENTEDAOIMPL_H
#include "incidentedao.h"
#include <QString>

using namespace std;

class IncidenteDAOImpl : public IncidenteDAO {
public:
    void insertar(Incidente obj);
    void actualizar(Incidente obj);
    void eliminar(Incidente obj);
    vector<vector<QString>> listar();
    vector<vector<QString>> buscarCampo(const QString &busqueda);
    int buscarAlquilerActivo(int id_auto, int id_cliente, const QString& fechaIncidente);
    void finalizarAlquilerSiCorresponde(int id_alquiler, const QString& fechaIncidente);
};

#endif // INCIDENTEDAOIMPL_H
