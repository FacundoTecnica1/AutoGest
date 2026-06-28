#ifndef GESTOR_ALQUILER_H
#define GESTOR_ALQUILER_H

#include <QObject>
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

public slots:
    void calcularTotal(); //Se ejecuta cuando cambian las fechas o el auto

private:
    Ui::MainWindow *ui;
    AlquilerDAOImpl daoAlquiler;
    AutoDAOImpl daoAuto;
    ClienteDAOImpl daoCliente;
    int getIdSeleccionadoTabla(); //Ayuda para saber que fila tocaron
};
#endif // GESTOR_ALQUILER_H