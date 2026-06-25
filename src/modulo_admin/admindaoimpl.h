#ifndef ADMINDAOIMPL_H
#define ADMINDAOIMPL_H
#include "admindao.h"

using namespace std;

class AdminDAOImpl : public AdminDAO {
public:
    void insertar(Admin obj) override;
    void actualizar(Admin obj) override;
    void eliminar(Admin obj) override;
    Admin buscarPorId(int id) override;
    vector<Admin> listar() override;
};

#endif // ADMINDAOIMPL_H