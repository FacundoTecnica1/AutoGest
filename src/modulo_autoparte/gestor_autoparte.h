#ifndef GESTOR_AUTOPARTE_H
#define GESTOR_AUTOPARTE_H

#include <QObject>
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

private:
    Ui::MainWindow *ui;
    AutoparteDAOImpl daoAutoparte;
    int getIdSeleccionadoTabla();
};
#endif // GESTOR_AUTOPARTE_H