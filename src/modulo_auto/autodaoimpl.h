#ifndef AUTODAOIMPL_H
#define AUTODAOIMPL_H
#include "autodao.h"
#include <QString>

using namespace std;

class AutoDAOImpl : public AutoDAO {
public:
    void insertar(Auto obj);
    void actualizar(Auto obj);
    void eliminar(Auto obj);
    vector<Auto> listar();
    vector<Auto> buscarCampo(const QString &busqueda);
};

#endif // AUTODAOIMPL_H