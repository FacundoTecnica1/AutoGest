#ifndef TIPO_MantenimientoDAOIMPL_H
#define TIPO_MantenimientoDAOIMPL_H
#include "tipo_Mantenimientodao.h"
#include <QString>

using namespace std;

class TipoMantenimientoDAOImpl : public TipoMantenimientoDAO {
public:
    void insertar(TipoMantenimiento obj);
    void actualizar(TipoMantenimiento obj);
    void eliminar(TipoMantenimiento obj);
    vector<TipoMantenimiento> listar();
    vector<TipoMantenimiento> buscarCampo(const QString &busqueda);
};

#endif // TIPO_MantenimientoDAOIMPL_H