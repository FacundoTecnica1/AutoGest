#ifndef MANTENIMIENTODAOIMPL_H
#define MANTENIMIENTODAOIMPL_H
#include "mantenimientodao.h"

using namespace std;

class MantenimientoDAOImpl : public MantenimientoDAO {
public:
    void insertar(Mantenimiento obj) override;
    void actualizar(Mantenimiento obj) override;
    void eliminar(Mantenimiento obj) override;
    Mantenimiento buscarPorId(int id) override;
    vector<Mantenimiento> listar() override;
};

#endif // MANTENIMIENTODAOIMPL_H