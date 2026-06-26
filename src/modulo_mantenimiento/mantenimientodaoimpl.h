#ifndef MantenimientoDAOIMPL_H
#define MantenimientoDAOIMPL_H
#include "Mantenimientodao.h"
#include <QString>
#include <QString>

using namespace std;

class MantenimientoDAOImpl : public MantenimientoDAO {
public:
    void insertar(Mantenimiento obj) ;
    void actualizar(Mantenimiento obj) ;
    void eliminar(Mantenimiento obj) ;
    vector<Mantenimiento> listar();
};

#endif // MantenimientoDAOIMPL_H