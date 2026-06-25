#ifndef ADMINDAO_H
#define ADMINDAO_H
#include "dao.h"
#include "admin.h"

//Aclaramos que hereda las funciones del dao con el ":"
class AdminDAO : public DAO<Admin> {
};

#endif // ADMINDAO_H