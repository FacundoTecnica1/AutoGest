#ifndef AUTOPARTEDAOIMPL_H
#define AUTOPARTEDAOIMPL_H
#include "autopartedao.h"

using namespace std;

class AutoparteDAOImpl : public AutoparteDAO {
public:
    void insertar(Autoparte obj) override;
    void actualizar(Autoparte obj) override;
    void eliminar(Autoparte obj) override;
    Autoparte buscarPorId(int id) override;
    vector<Autoparte> listar() override;
};

#endif // AUTOPARTEDAOIMPL_H