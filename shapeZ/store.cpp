#include "store.h"
#include "ui_store.h"
#include <QPushButton>
#include <QString>
#include <QDebug>

Store::Store(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);

    this->setFixedSize(800,600);
    setWindowTitle("商店");

    connect(ui->pushButton,&QPushButton::clicked,[&](){
        value++;
        num->setFixedSize(500,50);
        QString str=QString("%1").arg(value);
        num->setText(str);
        num->move(205,98);
        num->show();

    });

    connect(ui->actionexit,&QAction::triggered,[&](){
        emit returnMap();
    });

    connect(ui->pushButton,&QPushButton::clicked,[&](){
        emit addValue(value);
    });
}

Store::~Store()
{
    delete ui;
}
