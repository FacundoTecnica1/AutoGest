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
    vector<vector<QString>> listar();
    vector<vector<QString>> buscarCampo(const QString &busqueda);
    bool alquilerCerrado(int id_auto);
};

#endif // MantenimientoDAOIMPL_H
