#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    //设置标题
    setWindowTitle("shapeZ");
    //设置固定大小
    this->setFixedSize(800,600);
    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //进入游戏

    mapscene1->setAttribute(Qt::WA_DeleteOnClose,true);
    mapscene2->setAttribute(Qt::WA_DeleteOnClose,true);
    mapscene3->setAttribute(Qt::WA_DeleteOnClose,true);
    gradescene1->setAttribute(Qt::WA_DeleteOnClose,true);
    gradescene2->setAttribute(Qt::WA_DeleteOnClose,true);

    //第一关

    connect(ui->pushButton_1,&QPushButton::clicked,this,[=](){
        this->hide();
        mapscene1->show();
    });

//升级界面
    connect(mapscene1,&Map::passLevel,[=](){
        level=2;
        mapscene2->moneyAll(mapscene1->money);
        mapscene1->close();
        gradescene1->show();
        QEventLoop loop;
        loop.exec();
    });

//升完级，第二关
    connect(gradescene1,&GradeScene::gradeDigger,this,[=](){

        mapscene2->diggerSpeed(50);
        gradescene1->close();
        mapscene2->show();
        QEventLoop loop1;
        loop1.exec();
    });

    connect(gradescene1,&GradeScene::gradeChannel,this,[=](){
        mapscene2->channelSpeed(50);
        gradescene1->close();
        mapscene2->show();
        QEventLoop loop2;
        loop2.exec();
    });
//升级
    connect(mapscene2,&Map::passLevel,[=](){
        level=3;
        mapscene3->moneyAll(mapscene2->money);
        mapscene2->close();
        gradescene2->show();
        QEventLoop loop3;
        loop3.exec();
    });
//升完级，第三关
    connect(gradescene2,&GradeScene::gradeDigger,this,[=](){
        mapscene3->diggerSpeed(50);
        gradescene2->close();
        mapscene3->show();
        QEventLoop loop4;
        loop4.exec();
    });

    connect(gradescene2,&GradeScene::gradeChannel,this,[=](){
        mapscene3->channelSpeed(50);
        gradescene2->close();
        mapscene3->show();
        QEventLoop loop5;
        loop5.exec();
    });

//进入商店
    connect(mapscene1,&Map::enterStore,this,[=](){
        if(level!=1) return ;
        mapscene1->hide();
        store->show();
        QEventLoop loop6;
        loop6.exec();
    });

    //从商店返回
    connect(store,&Store::returnMap,this,[=](){
        if(level!=1) return ;
        store->hide();
        mapscene1->show();
        QEventLoop loop7;
        loop7.exec();
    });

    //进入商店

    connect(mapscene2,&Map::enterStore,this,[=](){
        if(level!=2) return ;
        mapscene2->hide();
        store->show();
        QEventLoop loop6;
        loop6.exec();
    });

    //从商店返回
    connect(store,&Store::returnMap,this,[=](){
        if(level!=2) return ;
        store->hide();
        mapscene2->show();
        QEventLoop loop7;
        loop7.exec();
    });
    //进入商店
    connect(mapscene3,&Map::enterStore,this,[=](){
        if(level!=3) return ;
        mapscene3->hide();
        store->show();
        QEventLoop loop6;
        loop6.exec();
    });

    //从商店返回
    connect(store,&Store::returnMap,this,[=](){
        if(level!=3) return ;
        store->hide();
        mapscene3->show();
        QEventLoop loop7;
        loop7.exec();
    });

    connect(store,&Store::addValue,this,&MainWindow::changeAll);


}

void MainWindow::changeAll(int value){
    mapscene1->changeValue(value);
    mapscene2->changeValue(value);
    mapscene3->changeValue(value);
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);

    QImage originalImage;
    originalImage.load(":/pic/mainPic.png");

    // 启用抗锯齿和平滑变换
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    // 计算目标矩形
    QRect targetRect(0, 0, width(), height());

    // 缩放图像
    QImage scaledImage = originalImage.scaled(targetRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // 绘制图像
    painter.drawImage(targetRect, scaledImage);


}

MainWindow::~MainWindow()
{
    delete ui;
}




