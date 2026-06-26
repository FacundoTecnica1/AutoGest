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
    bool validarLogin(const QString &user, const QString &password); //Sirve para buscar al admin dentro
                                                                       //De la base de datos
};

#endif // ADMINDAOIMPL_H