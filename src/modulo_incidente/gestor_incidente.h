#ifndef GESTOR_INCIDENTE_H
#define GESTOR_INCIDENTE_H

#include <QObject>
#include "incidentedaoimpl.h"

namespace Ui { class MainWindow; }

class GestorIncidente : public QObject {
    Q_OBJECT
public:
    GestorIncidente(Ui::MainWindow *ui, QObject *parent = nullptr);
    void listar();
    void guardar();
    void actualizar();
    void eliminar();

private:
    Ui::MainWindow *ui;
    IncidenteDAOImpl daoIncidente;
    int getIdSeleccionadoTabla();
};
#endif // GESTOR_INCIDENTE_H