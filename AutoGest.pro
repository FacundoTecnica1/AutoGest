QT += widgets core gui sql

CONFIG += c++17 release

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    conexion.cpp \
    main.cpp \
    mainwindow.cpp \
    src/modulo_admin/admin.cpp \
    src/modulo_admin/admindaoimpl.cpp \
    src/modulo_alquiler/alquiler.cpp \
    src/modulo_alquiler/alquilerdaoimpl.cpp \
    src/modulo_alquiler/gestor_alquiler.cpp \
    src/modulo_auto/auto.cpp \
    src/modulo_auto/autodaoimpl.cpp \
    src/modulo_auto/gestor_auto.cpp \
    src/modulo_autoparte/autoparte.cpp \
    src/modulo_autoparte/autopartedaoimpl.cpp \
    src/modulo_autoparte/gestor_autoparte.cpp \
    src/modulo_cliente/cliente.cpp \
    src/modulo_cliente/clientedaoimpl.cpp \
    src/modulo_cliente/gestor_cliente.cpp \
    src/modulo_incidente/gestor_incidente.cpp \
    src/modulo_incidente/incidente.cpp \
    src/modulo_incidente/incidentedaoimpl.cpp \
    src/modulo_Mantenimiento/Mantenimiento.cpp \
    src/modulo_Mantenimiento/Mantenimientodaoimpl.cpp \
    src/modulo_Proveedor/Proveedor.cpp \
    src/modulo_Proveedor/Proveedordaoimpl.cpp \
    src/modulo_mantenimiento/gestor_mantenimiento.cpp \
    src/modulo_proveedor/gestor_proveedor.cpp \
    src/modulo_tipo_Mantenimiento/tipo_Mantenimiento.cpp \
    src/modulo_tipo_Mantenimiento/tipo_Mantenimientodaoimpl.cpp

HEADERS += \
    conexion.h \
    dao.h \
    mainwindow.h \
    src/modulo_admin/admin.h \
    src/modulo_admin/admindao.h \
    src/modulo_admin/admindaoimpl.h \
    src/modulo_alquiler/alquiler.h \
    src/modulo_alquiler/alquilerdao.h \
    src/modulo_alquiler/alquilerdaoimpl.h \
    src/modulo_alquiler/gestor_alquiler.h \
    src/modulo_auto/auto.h \
    src/modulo_auto/autodao.h \
    src/modulo_auto/autodaoimpl.h \
    src/modulo_auto/gestor_auto.h \
    src/modulo_autoparte/autoparte.h \
    src/modulo_autoparte/autopartedao.h \
    src/modulo_autoparte/autopartedaoimpl.h \
    src/modulo_autoparte/gestor_autoparte.h \
    src/modulo_cliente/cliente.h \
    src/modulo_cliente/clientedao.h \
    src/modulo_cliente/clientedaoimpl.h \
    src/modulo_cliente/gestor_cliente.h \
    src/modulo_incidente/gestor_incidente.h \
    src/modulo_incidente/incidente.h \
    src/modulo_incidente/incidentedao.h \
    src/modulo_incidente/incidentedaoimpl.h \
    src/modulo_Mantenimiento/Mantenimiento.h \
    src/modulo_Mantenimiento/Mantenimientodao.h \
    src/modulo_Mantenimiento/Mantenimientodaoimpl.h \
    src/modulo_Proveedor/Proveedor.h \
    src/modulo_Proveedor/Proveedordao.h \
    src/modulo_Proveedor/Proveedordaoimpl.h \
    src/modulo_mantenimiento/gestor_mantenimiento.h \
    src/modulo_proveedor/gestor_proveedor.h \
    src/modulo_tipo_Mantenimiento/tipo_Mantenimiento.h \
    src/modulo_tipo_Mantenimiento/tipo_Mantenimientodao.h \
    src/modulo_tipo_Mantenimiento/tipo_Mantenimientodaoimpl.h

FORMS += \
    mainwindow.ui

#Esto es para que no tenga que colocar las / a la hora de incluir un header o algo
INCLUDEPATH += src/modulo_admin \
               src/modulo_alquiler \
               src/modulo_auto \
               src/modulo_autoparte \
               src/modulo_cliente \
               src/modulo_incidente \
               src/modulo_Mantenimiento \
               src/modulo_Proveedor \
               src/modulo_tipo_Mantenimiento


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
