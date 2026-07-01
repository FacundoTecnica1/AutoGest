#ifndef GESTOR_MANTENIMIENTO_H
#define GESTOR_MANTENIMIENTO_H

#include <QObject>
#include <vector>
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
    void limpiarFormulario();

public slots:
    void buscar(const QString &texto);
    void cargarDatos();

private:
    Ui::MainWindow *ui;
    MantenimientoDAOImpl daoMantenimiento;
    AutoDAOImpl daoAuto;
    TipoMantenimientoDAOImpl daoTipo;
    int getIdSeleccionadoTabla();
    void poblarTabla(const std::vector<std::vector<QString>>& lista);
};
#endif