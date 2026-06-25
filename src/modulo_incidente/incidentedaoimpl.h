#ifndef INCIDENTEDAOIMPL_H
#define INCIDENTEDAOIMPL_H
#include "incidentedao.h"

using namespace std;

class IncidenteDAOImpl : public IncidenteDAO {
public:
    void insertar(Incidente obj);
    void actualizar(Incidente obj);
    void eliminar(Incidente obj);
    Incidente buscarPorId(int id);
    vector<Incidente> listar();
};

#endif // INCIDENTEDAOIMPL_H