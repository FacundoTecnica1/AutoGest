#ifndef INCIDENTEDAOIMPL_H
#define INCIDENTEDAOIMPL_H
#include "incidentedao.h"

using namespace std;

class IncidenteDAOImpl : public IncidenteDAO {
public:
    void insertar(Incidente obj) override;
    void actualizar(Incidente obj) override;
    void eliminar(Incidente obj) override;
    Incidente buscarPorId(int id) override;
    vector<Incidente> listar() override;
};

#endif // INCIDENTEDAOIMPL_H