#ifndef ProveedorDAOIMPL_H
#define ProveedorDAOIMPL_H
#include "Proveedordao.h"
#include <QString>


using namespace std;

class ProveedorDAOImpl : public ProveedorDAO {
public:
    void insertar(Proveedor obj);
    void actualizar(Proveedor obj);
    void eliminar(Proveedor obj);
    vector<Proveedor> listar();
    vector<Proveedor> buscarCampo(const QString &busqueda);
};

#endif // ProveedorDAOIMPL_H