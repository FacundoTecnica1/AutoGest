#ifndef CLIENTEDAOIMPL_H
#define CLIENTEDAOIMPL_H
#include "clientedao.h"

using namespace std;

class ClienteDAOImpl : public ClienteDAO {
public:
    void insertar(Cliente obj) override;
    void actualizar(Cliente obj) override;
    void eliminar(Cliente obj) override;
    Cliente buscarPorId(int id) override;
    vector<Cliente> listar() override;
};

#endif // CLIENTEDAOIMPL_H