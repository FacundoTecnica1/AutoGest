#ifndef AUTODAOIMPL_H
#define AUTODAOIMPL_H
#include "autodao.h"

using namespace std;

class AutoDAOImpl : public AutoDAO {
public:
    void insertar(Auto obj);
    void actualizar(Auto obj);
    void eliminar(Auto obj);
    Auto buscarPorId(int id);
    vector<Auto> listar();
};

#endif // AUTODAOIMPL_H