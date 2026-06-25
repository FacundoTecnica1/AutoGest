#ifndef ALQUILERDAOIMPL_H
#define ALQUILERDAOIMPL_H
#include "alquilerdao.h"

using namespace std;

class AlquilerDAOImpl : public AlquilerDAO {
public:
    void insertar(Alquiler obj) override;
    void actualizar(Alquiler obj) override;
    void eliminar(Alquiler obj) override;
    Alquiler buscarPorId(int id) override;
    vector<Alquiler> listar() override;
};

#endif // ALQUILERDAOIMPL_H