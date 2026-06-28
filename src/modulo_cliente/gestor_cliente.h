#ifndef GESTOR_CLIENTE_H
#define GESTOR_CLIENTE_H

#include <QObject>
#include "clientedaoimpl.h"

namespace Ui { class MainWindow; }

class GestorCliente : public QObject {
    Q_OBJECT
public:
    GestorCliente(Ui::MainWindow *ui, QObject *parent = nullptr);
    void listar();
    void guardar();
    void actualizar();
    void eliminar();

private:
    Ui::MainWindow *ui;
    ClienteDAOImpl daoCliente;
    int getIdSeleccionadoTabla();
};
#endif