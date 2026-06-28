#ifndef GESTOR_PROVEEDOR_H
#define GESTOR_PROVEEDOR_H

#include <QObject>
#include "Proveedordaoimpl.h"

//le avisamos al gestor que existe la ventana principal
namespace Ui { class MainWindow; }

class GestorProveedor : public QObject {
    Q_OBJECT
public:
    GestorProveedor(Ui::MainWindow *ui, QObject *parent = nullptr);

    //estas son las funciones que va a usar el mainwindow cuando toquemos los botones
    void listar();
    void guardar();
    void actualizar();
    void eliminar();

private:
    Ui::MainWindow *ui;
    ProveedorDAOImpl daoProveedor;

    //esta funcion cortita nos sirve para no repetir codigo al buscar el id seleccionado
    int getIdSeleccionadoTabla();
};
#endif // GESTOR_PROVEEDOR_H