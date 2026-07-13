#ifndef ADMINDAOIMPL_H
#define ADMINDAOIMPL_H
#include "admindao.h"
#include <QString>

using namespace std;

class AdminDAOImpl : public AdminDAO {

public:
    void insertar(Admin obj);
    void actualizar(Admin obj);
    void eliminar(Admin obj);
    vector<Admin> listar();
    bool validarLogin(const QString &user, const QString &password, QString &rol); //busca usuario y devuelve rol
};

#endif // ADMINDAOIMPL_H