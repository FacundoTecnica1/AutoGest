#ifndef PROVEEDORDAOIMPL_H
#define PROVEEDORDAOIMPL_H
#include "proveedordao.h"

using namespace std;

class ProveedorDAOImpl : public ProveedorDAO {
public:
    void insertar(Proveedor obj) override;
    void actualizar(Proveedor obj) override;
    void eliminar(Proveedor obj) override;
    Proveedor buscarPorId(int id) override;
    vector<Proveedor> listar() override;
};

#endif // PROVEEDORDAOIMPL_H