#ifndef ProveedorDAOIMPL_H
#define ProveedorDAOIMPL_H
#include "Proveedordao.h"

using namespace std;

class ProveedorDAOImpl : public ProveedorDAO {
public:
    void insertar(Proveedor obj);
    void actualizar(Proveedor obj);
    void eliminar(Proveedor obj);
    Proveedor buscarPorId(int id);
    vector<Proveedor> listar();
};

#endif // ProveedorDAOIMPL_H