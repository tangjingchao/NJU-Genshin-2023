/********************************************************************************
** Form generated from reading UI file 'grade.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADE_H
#define UI_GRADE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Grade
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Grade)
    {
        if (Grade->objectName().isEmpty())
            Grade->setObjectName(QString::fromUtf8("Grade"));
        Grade->resize(800, 600);
        label = new QLabel(Grade);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 230, 181, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        label->setFont(font);
        pushButton = new QPushButton(Grade);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 350, 70, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8("pic/miner.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(70, 70));
        pushButton_2 = new QPushButton(Grade);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 350, 70, 70));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("pic/conveyor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(70, 70));
        pushButton_3 = new QPushButton(Grade);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 350, 70, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("pic/cutter1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(70, 70));

        retranslateUi(Grade);

        QMetaObject::connectSlotsByName(Grade);
    } // setupUi

    void retranslateUi(QWidget *Grade)
    {
        Grade->setWindowTitle(QCoreApplication::translate("Grade", "Form", nullptr));
        label->setText(QCoreApplication::translate("Grade", "\350\257\267\351\200\211\346\213\251\344\275\240\350\246\201\345\215\207\347\272\247\347\232\204\345\267\245\345\205\267", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Grade: public Ui_Grade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADE_H
