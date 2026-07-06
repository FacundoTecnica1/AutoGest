#ifndef PROVEEDORDAOIMPL_H
#define PROVEEDORDAOIMPL_H
#include "proveedordao.h"
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

#endif // PROVEEDORDAOIMPL_H