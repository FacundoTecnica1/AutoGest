#ifndef AUTOPARTEDAOIMPL_H
#define AUTOPARTEDAOIMPL_H
#include "autopartedao.h"
#include <QString>

using namespace std;

class AutoparteDAOImpl : public AutoparteDAO {
public:
    void insertar(Autoparte obj);
    void actualizar(Autoparte obj);
    void eliminar(Autoparte obj);
    vector<Autoparte> listar();
};

#endif // AUTOPARTEDAOIMPL_H