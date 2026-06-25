#ifndef TIPO_MANTENIMIENTODAOIMPL_H
#define TIPO_MANTENIMIENTODAOIMPL_H
#include "tipo_mantenimientodao.h"

using namespace std;

class TipoMantenimientoDAOImpl : public TipoMantenimientoDAO {
public:
    void insertar(TipoMantenimiento obj) override;
    void actualizar(TipoMantenimiento obj) override;
    void eliminar(TipoMantenimiento obj) override;
    TipoMantenimiento buscarPorId(int id) override;
    vector<TipoMantenimiento> listar() override;
};

#endif // TIPO_MANTENIMIENTODAOIMPL_H