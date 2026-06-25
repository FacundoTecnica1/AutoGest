#ifndef AUTODAOIMPL_H
#define AUTODAOIMPL_H
#include "autodao.h"

using namespace std;

class AutoDAOImpl : public AutoDAO {
public:
    void insertar(Auto obj) override;
    void actualizar(Auto obj) override;
    void eliminar(Auto obj) override;
    Auto buscarPorId(int id) override;
    vector<Auto> listar() override;
};

#endif // AUTODAOIMPL_H