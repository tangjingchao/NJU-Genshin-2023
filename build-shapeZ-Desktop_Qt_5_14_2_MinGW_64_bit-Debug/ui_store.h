/********************************************************************************
** Form generated from reading UI file 'store.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORE_H
#define UI_STORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Store
{
public:
    QAction *actionexit;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuexit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Store)
    {
        if (Store->objectName().isEmpty())
            Store->setObjectName(QString::fromUtf8("Store"));
        Store->resize(800, 600);
        actionexit = new QAction(Store);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        centralwidget = new QWidget(Store);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 261, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 271, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 90, 161, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 50, 93, 28));
        Store->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Store);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuexit = new QMenu(menubar);
        menuexit->setObjectName(QString::fromUtf8("menuexit"));
        Store->setMenuBar(menubar);
        statusbar = new QStatusBar(Store);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Store->setStatusBar(statusbar);

        menubar->addAction(menuexit->menuAction());
        menuexit->addAction(actionexit);

        retranslateUi(Store);

        QMetaObject::connectSlotsByName(Store);
    } // setupUi

    void retranslateUi(QMainWindow *Store)
    {
        Store->setWindowTitle(QCoreApplication::translate("Store", "MainWindow", nullptr));
        actionexit->setText(QCoreApplication::translate("Store", "exit", nullptr));
        label->setText(QCoreApplication::translate("Store", "\347\202\271\346\255\244\345\244\204\344\275\277\345\276\227\344\272\244\344\273\230\346\211\200\345\276\227\351\207\221\345\270\201+1\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Store", "\344\272\244\344\273\230\347\211\251\345\223\201\346\211\200\345\276\227\345\216\237\345\247\213\351\207\221\345\270\201\357\274\2321", nullptr));
        label_3->setText(QCoreApplication::translate("Store", "\347\216\260\345\234\250\344\272\244\344\273\230\347\211\251\345\223\201\346\211\200\345\276\227\351\207\221\345\270\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Store", "PushButton", nullptr));
        menuexit->setTitle(QCoreApplication::translate("Store", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Store: public Ui_Store {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORE_H
