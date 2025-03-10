/********************************************************************************
** Form generated from reading UI file 'gradescene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADESCENE_H
#define UI_GRADESCENE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GradeScene
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GradeScene)
    {
        if (GradeScene->objectName().isEmpty())
            GradeScene->setObjectName(QString::fromUtf8("GradeScene"));
        GradeScene->resize(800, 600);
        centralwidget = new QWidget(GradeScene);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 190, 181, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        label->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(540, 310, 70, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/cutter1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(70, 70));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 310, 70, 70));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/conveyor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(70, 70));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 310, 70, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/miner.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(70, 70));
        GradeScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GradeScene);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        GradeScene->setMenuBar(menubar);
        statusbar = new QStatusBar(GradeScene);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GradeScene->setStatusBar(statusbar);

        retranslateUi(GradeScene);

        QMetaObject::connectSlotsByName(GradeScene);
    } // setupUi

    void retranslateUi(QMainWindow *GradeScene)
    {
        GradeScene->setWindowTitle(QCoreApplication::translate("GradeScene", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("GradeScene", "\350\257\267\351\200\211\346\213\251\344\275\240\350\246\201\345\215\207\347\272\247\347\232\204\345\267\245\345\205\267", nullptr));
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GradeScene: public Ui_GradeScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADESCENE_H
