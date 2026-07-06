#ifndef GESTOR_INCIDENTE_H
#define GESTOR_INCIDENTE_H

#include <QObject>
#include <vector>
#include "incidentedaoimpl.h"
#include "autodaoimpl.h"
#include "clientedaoimpl.h"

namespace Ui { class MainWindow; }

class GestorIncidente : public QObject {
    Q_OBJECT
public:
    GestorIncidente(Ui::MainWindow *ui, QObject *parent = nullptr);
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
    IncidenteDAOImpl daoIncidente;
    AutoDAOImpl daoAuto;
    ClienteDAOImpl daoCliente;
    int getIdSeleccionadoTabla();
    void poblarTabla(const std::vector<std::vector<QString>>& lista);
};
#endif // GESTOR_INCIDENTE_H
