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
    void limpiarFormulario();

public slots:
    void buscar(const QString &texto);
    void cargarDatos();

private:
    Ui::MainWindow *ui;
    ClienteDAOImpl daoCliente;
    int getIdSeleccionadoTabla();
    void poblarTabla(const std::vector<Cliente>& lista);
};
#endif