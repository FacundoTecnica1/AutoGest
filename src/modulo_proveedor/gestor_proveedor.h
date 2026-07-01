#ifndef GESTOR_PROVEEDOR_H
#define GESTOR_PROVEEDOR_H

#include <QObject>
#include <vector>
#include "Proveedordaoimpl.h"

namespace Ui { class MainWindow; }

class GestorProveedor : public QObject {
    Q_OBJECT
public:
    GestorProveedor(Ui::MainWindow *ui, QObject *parent = nullptr);
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
    ProveedorDAOImpl daoProveedor;
    int getIdSeleccionadoTabla();
    void poblarTabla(const std::vector<Proveedor>& lista);
};
#endif // GESTOR_PROVEEDOR_H