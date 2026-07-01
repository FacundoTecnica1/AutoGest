#ifndef GESTOR_ALQUILER_H
#define GESTOR_ALQUILER_H

#include <QObject>
#include <vector>
#include "alquilerdaoimpl.h"
#include "autodaoimpl.h"
#include "clientedaoimpl.h"

namespace Ui { class MainWindow; }

class GestorAlquiler : public QObject {
    Q_OBJECT
public:
    GestorAlquiler(Ui::MainWindow *ui, QObject *parent = nullptr);
    void cargarListasCombo();
    void listar();
    void guardar();
    void actualizar();
    void eliminar();
    void limpiarFormulario();

public slots:
    void calcularTotal();
    void buscar(const QString &texto);
    void cargarDatos();

private:
    Ui::MainWindow *ui;
    AlquilerDAOImpl daoAlquiler;
    AutoDAOImpl daoAuto;
    ClienteDAOImpl daoCliente;
    int getIdSeleccionadoTabla();
    void poblarTabla(const std::vector<std::vector<QString>>& lista);
};
#endif // GESTOR_ALQUILER_H