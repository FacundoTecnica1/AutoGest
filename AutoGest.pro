QT += widgets core gui sql

CONFIG += c++17

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
    src/modulo_auto/auto.cpp \
    src/modulo_auto/autodaoimpl.cpp \
    src/modulo_autoparte/autoparte.cpp \
    src/modulo_autoparte/autopartedaoimpl.cpp \
    src/modulo_cliente/cliente.cpp \
    src/modulo_cliente/clientedaoimpl.cpp \
    src/modulo_incidente/incidente.cpp \
    src/modulo_incidente/incidentedaoimpl.cpp \
    src/modulo_mantenimiento/mantenimiento.cpp \
    src/modulo_mantenimiento/mantenimientodaoimpl.cpp \
    src/modulo_proveedor/proveedor.cpp \
    src/modulo_proveedor/proveedordaoimpl.cpp \
    src/modulo_tipo_mantenimiento/tipo_mantenimiento.cpp \
    src/modulo_tipo_mantenimiento/tipo_mantenimientodaoimpl.cpp

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
    src/modulo_auto/auto.h \
    src/modulo_auto/autodao.h \
    src/modulo_auto/autodaoimpl.h \
    src/modulo_autoparte/autoparte.h \
    src/modulo_autoparte/autopartedao.h \
    src/modulo_autoparte/autopartedaoimpl.h \
    src/modulo_cliente/cliente.h \
    src/modulo_cliente/clientedao.h \
    src/modulo_cliente/clientedaoimpl.h \
    src/modulo_incidente/incidente.h \
    src/modulo_incidente/incidentedao.h \
    src/modulo_incidente/incidentedaoimpl.h \
    src/modulo_mantenimiento/mantenimiento.h \
    src/modulo_mantenimiento/mantenimientodao.h \
    src/modulo_mantenimiento/mantenimientodaoimpl.h \
    src/modulo_proveedor/proveedor.h \
    src/modulo_proveedor/proveedordao.h \
    src/modulo_proveedor/proveedordaoimpl.h \
    src/modulo_tipo_mantenimiento/tipo_mantenimiento.h \
    src/modulo_tipo_mantenimiento/tipo_mantenimientodao.h \
    src/modulo_tipo_mantenimiento/tipo_mantenimientodaoimpl.h

FORMS += \
    mainwindow.ui

#Esto es para que no tenga que colocar las / a la hora de incluir un header o algo
INCLUDEPATH += src/modulo_admin \
               src/modulo_alquiler \
               src/modulo_auto \
               src/modulo_autoparte \
               src/modulo_cliente \
               src/modulo_incidente \
               src/modulo_mantenimiento \
               src/modulo_proveedor \
               src/modulo_tipo_mantenimiento


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
