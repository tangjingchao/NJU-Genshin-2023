#ifndef MAP_H
#define MAP_H

#define BOTTEMLINE 500
#define WIDTHLINE 800
#define DELIVERY_X 350
#define DELIVERY_Y 175
#define LENNUM 16
#define HIGHNUM 9
#define GRIDSIZE 50

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QMouseEvent>
#include <QPoint>
#include <QImage>
#include <QDebug>
#include <QLabel>
#include <QLayout>
#include "mylabel.h"
#include "mymineral.h"
#include <QPropertyAnimation>
#include <QQueue>
#include <QVector>
#include <algorithm>
#include <math.h>
#include <QThread>
namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:


    Map(QWidget *parent = nullptr,int order=1);
    ~Map();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void canMove(QLabel *,int order);
    void clearAbandon(QVector<QLabel *> *);
    void channelSpeed(int lessTime);
    void diggerSpeed(int lessTime);
    void moneyAll(int moneyPre);
    void changeValue(int vale_);


    const QString cutterName="cutter";
    const QString rubbishName="rubbish";
    const QString channelName="channel";
    const QString diggerName="digger";
    QString nowName="";

    QString channelImg=":/pic/conveyor.png";
    QString cutterImg=":/pic/cutter1.png";
    QString rubbishImg=":/pic/eraser.png";
    QString storeImg=":/pic/store.png";
    QString diggerImg=":/pic/miner.png";
    QString nowImg="";

    QString circleImg=":/pic/circleSpecial.png";
    QString rectImg=":/pic/rectSpecial.png";

    QString up="up";
    QString down="down";
    QString left="left";
    QString right="right";
    QString strDre="";
    QString nowDre=up;
    int numDre=1;
    int value=1;
    int taskNum;
    int collection=0;
    int money=0;
    int speed=1;
    int diggerDure=460;
    int channelDure=150;
    int taskNeed=20;
    QLabel *label=new QLabel;
    QLabel *label2=new QLabel;
    QLabel *labelDemand= new QLabel(this);

    MyLabel *labelNow[(LENNUM+10)*(HIGHNUM+10)];
    int labelAbandon[(LENNUM+10)*(HIGHNUM+10)][3];
    MyLabel *labelDre;
    QVector<QLabel *> vec_circle_1;
    QVector<QLabel *> vec_circle_2;
    QVector<QLabel *> vec_circle_3;
    QVector<QLabel *> vec_circle_4;
    QVector<QLabel *> vec_circle_5;
    QVector<QLabel *> vec_circle_6;

    QVector<QLabel *> vec_rect_1;//7
    QVector<QLabel *> vec_rect_2;//8
    QVector<QLabel *> vec_rect_3;//9
    QVector<QLabel *> vec_rect_4;//10

    QTimer *produce1=new QTimer(this);
    QTimer *produce2=new QTimer(this);
    QTimer *produce3=new QTimer(this);
    QTimer *produce4=new QTimer(this);
    QTimer *produce5=new QTimer(this);
    QTimer *produce6=new QTimer(this);

    QTimer *produce7=new QTimer(this);
    QTimer *produce8=new QTimer(this);
    QTimer *produce9=new QTimer(this);
    QTimer *produce10=new QTimer(this);

    QTimer *fresh1=new QTimer(this);
    QTimer *fresh2=new QTimer(this);
    QTimer *fresh3=new QTimer(this);
    QTimer *fresh4=new QTimer(this);
    QTimer *fresh5=new QTimer(this);
    QTimer *fresh6=new QTimer(this);

    QTimer *fresh7=new QTimer(this);
    QTimer *fresh8=new QTimer(this);
    QTimer *fresh9=new QTimer(this);
    QTimer *fresh10=new QTimer(this);


public slots:
    void createMineral(int x,int y);
private slots:
    void differDigger(int order);
    void shang(int index,int order);
    void xia(int index,int order);
    void zuo(int index,int order);
    void you(int index,int order);
    //    void abandonUp(int x,int y,int index,QVector<QLabel *>);
    //    void abandonDown(int x,int y,int index,QVector<QLabel *>);
    //    void abandonLeft(int x,int y,int index,QVector<QLabel *>);
    //    void abandonRight(int x,int y,int index,QVector<QLabel *>);
signals:
    //    void goUp(int x,int y,int index);
    //    void goDown(int x,int y,int index);
    //    void goLeft(int x,int y,int index);
    //    void goRight(int x,int y,int index);
    void stopCreate(int order);
    void removeAll(int x,int y);
    void passLevel();
    void enterStore();
private:
    Ui::Map *ui;

};

#endif // MAP_H
