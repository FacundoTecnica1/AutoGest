#ifndef GESTOR_MANTENIMIENTO_H
#define GESTOR_MANTENIMIENTO_H

#include <QObject>
#include "Mantenimientodaoimpl.h"
#include "autodaoimpl.h"
#include "tipo_Mantenimientodaoimpl.h"

namespace Ui { class MainWindow; }

class GestorMantenimiento : public QObject {
    Q_OBJECT
public:
    GestorMantenimiento(Ui::MainWindow *ui, QObject *parent = nullptr);
    void cargarListasCombo();
    void listar();
    void guardar();
    void actualizar();
    void eliminar();

private:
    Ui::MainWindow *ui;
    MantenimientoDAOImpl daoMantenimiento;
    AutoDAOImpl daoAuto;
    TipoMantenimientoDAOImpl daoTipo;
    int getIdSeleccionadoTabla();
};
#endif