#include "gradescene.h"
#include "ui_gradescene.h"

GradeScene::GradeScene(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeScene)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    setWindowTitle("升级");

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        emit gradeDigger();
    });

    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        emit gradeChannel();
    });
}

GradeScene::~GradeScene()
{
    delete ui;
}
