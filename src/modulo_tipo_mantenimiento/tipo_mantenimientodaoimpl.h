#ifndef TIPO_MantenimientoDAOIMPL_H
#define TIPO_MantenimientoDAOIMPL_H
#include "tipo_Mantenimientodao.h"

using namespace std;

class TipoMantenimientoDAOImpl : public TipoMantenimientoDAO {
public:
    void insertar(TipoMantenimiento obj);
    void actualizar(TipoMantenimiento obj);
    void eliminar(TipoMantenimiento obj);
    TipoMantenimiento buscarPorId(int id);
    vector<TipoMantenimiento> listar();
};

#endif // TIPO_MantenimientoDAOIMPL_H