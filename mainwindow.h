#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTableWidgetItem>
#include <QString>
#include <vector>
#include <QMainWindow>

//Incluimos los gestores que vamos a crear
class GestorAuto;
class GestorCliente;
class GestorAlquiler;
class GestorMantenimiento;
class GestorProveedor;
class GestorAutoparte;
class GestorIncidente;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_btnCerrar_clicked();
    void on_btnIngresar_clicked();
    void on_btnVolverLoginAutos_clicked();
    void on_btnVolverLoginClientes_clicked();
    void on_btnVolverLoginAlquileres_clicked();
    void on_btnVolverLoginIncidentes_clicked();
    void on_btnVolverLoginMantenimientos_clicked();
    void on_btnVolverLoginAutopartes_clicked();
    void on_btnVolverLoginProveedores_clicked();

    //Agregamos slots para disparar las funciones de cada gestor al hacer click
    //Autos
    void on_btnGuardarAuto_clicked();
    void on_btnActualizarAuto_clicked();
    void on_btnEliminarAuto_clicked();

    //Clientes
    void on_btnGuardarCliente_clicked();
    void on_btnActualizarCliente_clicked();
    void on_btnEliminarCliente_clicked();

    //Alquileres
    void on_btnGuardarAlquiler_clicked();
    void on_btnActualizarAlquiler_clicked();
    void on_btnEliminarAlquiler_clicked();

    //Mantenimientos
    void on_btnGuardarMantenimiento_clicked();
    void on_btnActualizarMantenimiento_clicked();
    void on_btnEliminarMantenimiento_clicked();

    //Proveedores, Autopartes e Incidentes
    void on_btnGuardarProveedor_clicked();
    void on_btnActualizarProveedor_clicked();
    void on_btnEliminarProveedor_clicked();

    void on_btnGuardarAutoparte_clicked();
    void on_btnActualizarAutoparte_clicked();
    void on_btnEliminarAutoparte_clicked();

    void on_btnGuardarIncidente_clicked();
    void on_btnActualizarIncidente_clicked();
    void on_btnEliminarIncidente_clicked();

private:
    Ui::MainWindow *ui;
    QString currentUserRole; //rol actual para usar luego en restricciones de vistas

    void aplicarPermisosPorRol();
    void cerrarSesion();

    //Punteros a nuestros gestores
    GestorAuto* gestorAuto;
    GestorCliente* gestorCliente;
    GestorAlquiler* gestorAlquiler;
    GestorMantenimiento* gestorMantenimiento;
    GestorProveedor* gestorProveedor;
    GestorAutoparte* gestorAutoparte;
    GestorIncidente* gestorIncidente;
};
#endif // MAINWINDOW_H