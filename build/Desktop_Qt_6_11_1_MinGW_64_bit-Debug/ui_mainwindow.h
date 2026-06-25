/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frameLogin;
    QGridLayout *gridLayout;
    QLabel *label_iniciarSesion;
    QLabel *label_Usuario;
    QLineEdit *txtUsuario;
    QLabel *label_Contrasena;
    QLineEdit *txtPassword;
    QPushButton *btnIngresar;
    QPushButton *btnCerrar;
    QWidget *page_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        frameLogin = new QFrame(page);
        frameLogin->setObjectName("frameLogin");
        frameLogin->setGeometry(QRect(300, 90, 176, 166));
        frameLogin->setFrameShape(QFrame::Shape::StyledPanel);
        frameLogin->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frameLogin);
        gridLayout->setObjectName("gridLayout");
        label_iniciarSesion = new QLabel(frameLogin);
        label_iniciarSesion->setObjectName("label_iniciarSesion");

        gridLayout->addWidget(label_iniciarSesion, 0, 0, 1, 2);

        label_Usuario = new QLabel(frameLogin);
        label_Usuario->setObjectName("label_Usuario");

        gridLayout->addWidget(label_Usuario, 1, 0, 1, 1);

        txtUsuario = new QLineEdit(frameLogin);
        txtUsuario->setObjectName("txtUsuario");
        txtUsuario->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout->addWidget(txtUsuario, 2, 0, 1, 2);

        label_Contrasena = new QLabel(frameLogin);
        label_Contrasena->setObjectName("label_Contrasena");

        gridLayout->addWidget(label_Contrasena, 3, 0, 1, 1);

        txtPassword = new QLineEdit(frameLogin);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout->addWidget(txtPassword, 4, 0, 1, 2);

        btnIngresar = new QPushButton(frameLogin);
        btnIngresar->setObjectName("btnIngresar");

        gridLayout->addWidget(btnIngresar, 5, 0, 1, 1);

        btnCerrar = new QPushButton(frameLogin);
        btnCerrar->setObjectName("btnCerrar");

        gridLayout->addWidget(btnCerrar, 5, 1, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        horizontalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_iniciarSesion->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesi\303\263n", nullptr));
        label_Usuario->setText(QCoreApplication::translate("MainWindow", "Usuario:", nullptr));
        label_Contrasena->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        btnIngresar->setText(QCoreApplication::translate("MainWindow", "Ingresar", nullptr));
        btnCerrar->setText(QCoreApplication::translate("MainWindow", "Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
