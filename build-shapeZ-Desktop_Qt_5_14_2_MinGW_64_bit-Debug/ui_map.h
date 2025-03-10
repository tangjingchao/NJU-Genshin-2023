/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QAction *actionsave;
    QWidget *centralwidget;
    QToolButton *cutter;
    QToolButton *rubbish;
    QToolButton *digger;
    QToolButton *channel;
    QToolButton *store;
    QLabel *labelTask;
    QLabel *labelDeli;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName(QString::fromUtf8("Map"));
        Map->resize(836, 671);
        Map->setBaseSize(QSize(10, 0));
        actionsave = new QAction(Map);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        centralwidget = new QWidget(Map);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cutter = new QToolButton(centralwidget);
        cutter->setObjectName(QString::fromUtf8("cutter"));
        cutter->setGeometry(QRect(50, 500, 70, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/cutter1.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutter->setIcon(icon);
        cutter->setIconSize(QSize(70, 70));
        rubbish = new QToolButton(centralwidget);
        rubbish->setObjectName(QString::fromUtf8("rubbish"));
        rubbish->setGeometry(QRect(150, 500, 70, 70));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        rubbish->setIcon(icon1);
        rubbish->setIconSize(QSize(70, 70));
        digger = new QToolButton(centralwidget);
        digger->setObjectName(QString::fromUtf8("digger"));
        digger->setGeometry(QRect(250, 500, 70, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/miner.png"), QSize(), QIcon::Normal, QIcon::Off);
        digger->setIcon(icon2);
        digger->setIconSize(QSize(70, 70));
        channel = new QToolButton(centralwidget);
        channel->setObjectName(QString::fromUtf8("channel"));
        channel->setGeometry(QRect(350, 500, 70, 70));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pic/conveyor.png"), QSize(), QIcon::Normal, QIcon::Off);
        channel->setIcon(icon3);
        channel->setIconSize(QSize(70, 70));
        store = new QToolButton(centralwidget);
        store->setObjectName(QString::fromUtf8("store"));
        store->setGeometry(QRect(450, 500, 70, 70));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/pic/store.png"), QSize(), QIcon::Normal, QIcon::Off);
        store->setIcon(icon4);
        store->setIconSize(QSize(70, 70));
        labelTask = new QLabel(centralwidget);
        labelTask->setObjectName(QString::fromUtf8("labelTask"));
        labelTask->setGeometry(QRect(570, 500, 81, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        labelTask->setFont(font);
        labelDeli = new QLabel(centralwidget);
        labelDeli->setObjectName(QString::fromUtf8("labelDeli"));
        labelDeli->setGeometry(QRect(350, 175, 100, 100));
        Map->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Map);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 836, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Map->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionsave);

        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QMainWindow *Map)
    {
        Map->setWindowTitle(QCoreApplication::translate("Map", "MainWindow", nullptr));
        actionsave->setText(QCoreApplication::translate("Map", "\345\255\230\346\241\243", nullptr));
        cutter->setText(QString());
#if QT_CONFIG(shortcut)
        cutter->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        rubbish->setText(QString());
#if QT_CONFIG(shortcut)
        rubbish->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        digger->setText(QString());
#if QT_CONFIG(shortcut)
        digger->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        channel->setText(QString());
#if QT_CONFIG(shortcut)
        channel->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        store->setText(QString());
#if QT_CONFIG(shortcut)
        store->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(whatsthis)
        labelTask->setWhatsThis(QCoreApplication::translate("Map", "<html><head/><body><p><img src=\":/pic/circle.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        labelTask->setText(QCoreApplication::translate("Map", "\345\275\223\345\211\215\344\273\273\345\212\241\357\274\232", nullptr));
        labelDeli->setText(QCoreApplication::translate("Map", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("Map", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
