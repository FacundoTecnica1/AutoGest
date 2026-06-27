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
    vector<Autoparte> buscarCampo(const QString &busqueda);
};

#endif // AUTOPARTEDAOIMPL_H