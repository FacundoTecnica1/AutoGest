#ifndef CLIENTEDAOIMPL_H
#define CLIENTEDAOIMPL_H
#include "clientedao.h"
#include <QString>

using namespace std;

class ClienteDAOImpl : public ClienteDAO {
public:
    void insertar(Cliente obj);
    void actualizar(Cliente obj);
    void eliminar(Cliente obj);
    vector<Cliente> listar();
};

#endif // CLIENTEDAOIMPL_H