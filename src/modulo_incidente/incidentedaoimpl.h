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
    vector<Incidente> listar();
};

#endif // INCIDENTEDAOIMPL_H