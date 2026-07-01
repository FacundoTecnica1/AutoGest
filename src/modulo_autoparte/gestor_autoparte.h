#ifndef GESTOR_AUTOPARTE_H
#define GESTOR_AUTOPARTE_H

#include <QObject>
#include <vector>
#include "autopartedaoimpl.h"

namespace Ui { class MainWindow; }

class GestorAutoparte : public QObject {
    Q_OBJECT
public:
    GestorAutoparte(Ui::MainWindow *ui, QObject *parent = nullptr);
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
    AutoparteDAOImpl daoAutoparte;
    int getIdSeleccionadoTabla();
    void poblarTabla(const std::vector<Autoparte>& lista);
};
#endif // GESTOR_AUTOPARTE_H