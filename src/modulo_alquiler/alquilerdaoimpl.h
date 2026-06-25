#ifndef ALQUILERDAOIMPL_H
#define ALQUILERDAOIMPL_H
#include "alquilerdao.h"

using namespace std;

class AlquilerDAOImpl : public AlquilerDAO {
public:
    void insertar(Alquiler obj);
    void actualizar(Alquiler obj);
    void eliminar(Alquiler obj);
    Alquiler buscarPorId(int id);
    vector<Alquiler> listar();
};

#endif // ALQUILERDAOIMPL_H