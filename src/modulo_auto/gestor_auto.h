#ifndef GESTOR_AUTO_H
#define GESTOR_AUTO_H

#include <QObject>
#include "autodaoimpl.h"

namespace Ui { class MainWindow; }

class GestorAuto : public QObject {
    Q_OBJECT
public:
    GestorAuto(Ui::MainWindow *ui, QObject *parent = nullptr);
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
    AutoDAOImpl daoAuto;
    int getIdSeleccionadoTabla();
    //funcion auxiliar para cargar la tabla y no repetir codigo entre listar y buscar
    void poblarTabla(const std::vector<Auto>& lista);
};
#endif