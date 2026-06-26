#ifndef ALQUILERDAOIMPL_H
#define ALQUILERDAOIMPL_H
#include "alquilerdao.h"
#include <QString>

using namespace std;

class AlquilerDAOImpl : public AlquilerDAO {
public:
    void insertar(Alquiler obj);
    void actualizar(Alquiler obj);
    void eliminar(Alquiler obj);
    vector<Alquiler> listar();
};

#endif // ALQUILERDAOIMPL_H