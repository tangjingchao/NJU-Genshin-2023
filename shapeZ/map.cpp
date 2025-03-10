#include "map.h"
#include "ui_map.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QLabel>


Map::Map(QWidget *parent,int order) :
    QMainWindow(parent),
    ui(new Ui::Map)
{

    //局部升级改变速率

    qDebug()<<diggerDure;

    //第几个场景
    taskNum=order;

    ui->setupUi(this);

    this->setFixedSize(800,600);
    setWindowTitle("游戏进行");

    //初始化抛弃物品列表
    std::fill(&labelAbandon[0][0], &labelAbandon[0][0] + ((LENNUM+10)*(HIGHNUM+10)*3), -1);


    //交付中心
    ui->labelDeli->setPixmap(QPixmap(":/pic/delivery.png").scaled(100,100,Qt::KeepAspectRatio));

    //当前任务显示

    labelDemand->setFixedSize(70,70);

    if(taskNum==1){
        labelDemand->setPixmap(QPixmap(":/pic/circle.png").scaled(70,70,Qt::KeepAspectRatio));
    }else if(taskNum==2){
        labelDemand->setPixmap(QPixmap(":/pic/rectangle.png").scaled(70,70,Qt::KeepAspectRatio));
    }
    labelDemand->move(670,530);
    labelDemand->show();

    //金币显示


    label->setParent(this);
    label->setFixedSize(500,50);
    if(taskNum==1){
    QString str=QString("金币:%1").arg(money);
    label->setText(str);
    }
    label->move(DELIVERY_X+15,DELIVERY_Y+25);
    label->show();



    //收集显示

    label2->setParent(this);
    label2->setFixedSize(500,50);
    QString str2=QString("收集:%1/%2").arg(this->collection).arg(taskNeed);
    label2->setText(str2);
    label2->move(DELIVERY_X+15,DELIVERY_Y+50);
    label2->show();
    //地图每个格子小窗口
    for(int labelX=0;labelX<=LENNUM-1;labelX++){
        for(int labelY=1;labelY<=HIGHNUM;labelY++){
            labelNow[labelY+labelX*LENNUM]=new MyLabel(labelX,labelY,nowDre,"");
            connect(labelNow[labelY+labelX*LENNUM],&MyLabel::clearLabel,labelNow[labelY+labelX*LENNUM],&QLabel::close);
            connect(labelNow[labelY+labelX*LENNUM],&MyLabel::produceMineral,this,&Map::createMineral);

        }
    }
    //规定交付中心
    for(int labelX=7;labelX<=8;labelX++){
        for(int labelY=4;labelY<=5;labelY++){
            labelNow[labelY+labelX*LENNUM]->toolName="Deli";

        }
    }
    //画矿


    for(int mineX=2;mineX<=4;mineX++){
        for(int mineY=7;mineY<=8;mineY++){
            QLabel *labelMine=new QLabel;
            labelMine->setParent(this);
            labelMine->setFixedSize(GRIDSIZE,GRIDSIZE);
            labelMine->setPixmap(QPixmap(":/pic/circle.png").scaled(50,50,Qt::KeepAspectRatio));
            labelMine->move(mineX*GRIDSIZE,mineY*GRIDSIZE);
            labelMine->show();
            labelNow[mineY+mineX*LENNUM]->toolName="mine";
        }
    }

    //画另一个矿
    for(int mineX=12;mineX<=13;mineX++){
        for(int mineY=2;mineY<=3;mineY++){
            QLabel *labelMine=new QLabel;
            labelMine->setParent(this);
            labelMine->setFixedSize(GRIDSIZE,GRIDSIZE);
            labelMine->setPixmap(QPixmap(":/pic/rectangle.png").scaled(50,50,Qt::KeepAspectRatio));
            labelMine->move(mineX*GRIDSIZE,mineY*GRIDSIZE);
            labelMine->show();
            labelNow[mineY+mineX*LENNUM]->toolName="mine";
        }
    }
    //显示当前方向
    labelDre=new MyLabel(0,0,"","");
    labelDre->setParent(this);
    labelDre->setFixedSize(500,25);
    labelDre->setWordWrap(true);

    labelDre->setText("当前方向:up");
    labelDre->move(0,25);
    labelDre->show();

    connect(labelDre,&MyLabel::clearDre,labelDre,&QLabel::clear);



    //保持追踪鼠标
    setMouseTracking(true);



    //判断现在方向状态
    connect(ui->channel,&QPushButton::clicked,[=](){
        nowImg=channelImg;
        //名字
        nowName=channelName;
        qDebug()<<"channel";
    });
    connect(ui->rubbish,&QPushButton::clicked,[=](){
        nowImg=rubbishImg;
        //名字
        nowName=rubbishName;
    });
    connect(ui->digger,&QPushButton::clicked,[=](){
        nowImg=diggerImg;
        //名字
        nowName=diggerName;
    });
    connect(ui->cutter,&QPushButton::clicked,[=](){
        nowImg=cutterImg;
        //名字
        nowName=cutterName;
    });

    connect(ui->store,&QPushButton::clicked,[=](){
        nowImg=storeImg;
        emit enterStore();
    });

    //将废弃物判定和废弃物移动函数链接
    //    connect(this,&Map::goUp,&Map::abandonUp);
    //    connect(this,&Map::goDown,&Map::abandonDown);
    //    connect(this,&Map::goLeft,&Map::abandonLeft);
    //    connect(this,&Map::goRight,&Map::abandonRight);

    //停止运动计时器，物体滞留
    connect(this,&Map::stopCreate,this,&Map::differDigger);

    //放下挖掘机，开始挖矿的计时器
    fresh1->start(diggerDure);
    fresh2->start(diggerDure);
    fresh3->start(diggerDure);
    fresh4->start(diggerDure);
    fresh5->start(diggerDure);
    fresh6->start(diggerDure);

    fresh7->start(diggerDure);
    fresh8->start(diggerDure);
    fresh9->start(diggerDure);
    fresh10->start(diggerDure);
    //运动的计时器
    produce1->start(channelDure);
    produce2->start(channelDure);
    produce3->start(channelDure);
    produce4->start(channelDure);
    produce5->start(channelDure);
    produce6->start(channelDure);
    produce7->start(channelDure);
    produce8->start(channelDure);
    produce9->start(channelDure);
    produce10->start(channelDure);

    //清除所有label
    connect(this,&Map::removeAll,[&](){
        clearAbandon(&vec_rect_1);
        clearAbandon(&vec_rect_2);
        clearAbandon(&vec_rect_3);
        clearAbandon(&vec_rect_4);
        clearAbandon(&vec_circle_1);
        clearAbandon(&vec_circle_2);
        clearAbandon(&vec_circle_3);
        clearAbandon(&vec_circle_4);
        clearAbandon(&vec_circle_5);
        clearAbandon(&vec_circle_6);
    });


}

Map::~Map()
{
    delete ui;
}

void Map::changeValue(int value_){
    value=value_;
}

void Map::channelSpeed(int lessTime){
    channelDure-=lessTime;
    qDebug()<<channelDure;
}

void Map::diggerSpeed(int lessTime){
    diggerDure-=lessTime;
}

void Map::moneyAll(int moneyPre){
    money+=moneyPre;
}

void Map::clearAbandon(QVector<QLabel *> *vecPointer){
    for(auto item=vecPointer->begin();item!=vecPointer->end();){
        int x_ = ((*item)->pos().x()+20) / GRIDSIZE;
        int y_ = ((*item)->pos().y()+20) / GRIDSIZE;
        if(labelNow[y_+x_*LENNUM]->toolName==rubbishName){
            (*item)->close();
            vecPointer->erase(item);
        }else{
            item++;
        }
    }
}

void Map::differDigger(int order){
    if(order==1){
        produce1->stop();
    }else if(order==2){
        produce2->stop();
    }else if(order==3){
        produce3->stop();
    }else if(order==4){
        produce4->stop();
    }else if(order==5){
        produce5->stop();
    }else if(order==6){
        produce6->stop();
    }else if(order==7){
        produce7->stop();
    }else if(order==8){
        produce8->stop();
    }else if(order==9){
        produce9->stop();
    }else if(order==10){
        produce10->stop();
    }
}

void Map::createMineral(int labelX,int labelY){

    QLabel *circle=new QLabel(this);
    if(labelX>=2 && labelX<=4){
        circle->setPixmap(QPixmap(circleImg).scaled(40,40,Qt::KeepAspectRatio));
    }else{
        circle->setPixmap(QPixmap(":/pic/rectSpecial.png").scaled(40,40,Qt::KeepAspectRatio));
    }

    circle->move(labelX*GRIDSIZE+5,labelY*GRIDSIZE+5);
    circle->show();

    if(labelX==2 && labelY==7){
        vec_circle_1.push_back(circle);
        connect(produce1,&QTimer::timeout,this,[=](){
            canMove(circle,1);
        });
    }
    else if(labelX==3 && labelY==7){
        vec_circle_2.push_back(circle);
        connect(produce2,&QTimer::timeout,this,[=](){
            canMove(circle,2);
        });

    }else if(labelX==4 && labelY==7){
        vec_circle_3.push_back(circle);
        connect(produce3,&QTimer::timeout,this,[=](){
            canMove(circle,3);
        });

    }else if(labelX==2 && labelY==8){
        vec_circle_4.push_back(circle);
        connect(produce4,&QTimer::timeout,this,[=](){
            canMove(circle,4);
        });

    }else if(labelX==3 && labelY==8){
        vec_circle_5.push_back(circle);
        connect(produce5,&QTimer::timeout,this,[=](){
            canMove(circle,5);
        });
    }
    else if(labelX==4 && labelY==8){
        vec_circle_6.push_back(circle);
        connect(produce6,&QTimer::timeout,this,[=](){
            canMove(circle,6);
        });
    }else if(labelX==12 && labelY==2){
        vec_rect_1.push_back(circle);
        connect(produce7,&QTimer::timeout,this,[=](){
            canMove(circle,7);
        });
    }else if(labelX==13 && labelY==2){
        vec_rect_2.push_back(circle);
        connect(produce8,&QTimer::timeout,this,[=](){
            canMove(circle,8);
        });
    }else if(labelX==12 && labelY==3){
        vec_rect_3.push_back(circle);
        connect(produce9,&QTimer::timeout,this,[=](){
            canMove(circle,9);
        });
    }else if(labelX==13 && labelY==3){
        vec_rect_4.push_back(circle);
        connect(produce10,&QTimer::timeout,this,[=](){
            canMove(circle,10);
        });
    }




    update();
}

void Map::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    int gridSize = 50; // 方格的大小
    int width = size().width();
    int height = BOTTEMLINE;

    painter.setPen(Qt::black);

    // 绘制竖线
    for (int x = gridSize; x < width; x += gridSize)
    {
        painter.drawLine(x, gridSize, x, height);
    }

    // 绘制横线
    for (int y = gridSize; y <=height; y += gridSize)
    {
        painter.drawLine(0, y, width, y);
    }


}

void Map::canMove(QLabel *circle,int order){
    QVector<QLabel *> *vec;
    if(order==1){
        vec=&vec_circle_1;
    }else if(order==2){
        vec=&vec_circle_2;
    }else if(order==3){
        vec=&vec_circle_3;
    }else if(order==4){
        vec=&vec_circle_4;
    }else if(order==5){
        vec=&vec_circle_5;
    }else if(order==6){
        vec=&vec_circle_6;
    }else if(order==7){
        vec=&vec_rect_1;
    }else if(order==8){
        vec=&vec_rect_2;
    }else if(order==9){
        vec=&vec_rect_3;
    }else if(order==10){
        vec=&vec_rect_4;
    }
    auto it=std::find(vec->begin(),vec->end(),circle);
    int index=it-vec->begin();
    int gridSize = 50;
    int x = (circle->pos().x()+20) / gridSize;
    int y = (circle->pos().y()+20) / gridSize;

    //    if(labelNow[y+x*LENNUM]->toolName==channelName){
    //        circle->move(x*gridSize+5,y*gridSize+5);
    //        x = (circle->pos().x()+20) / gridSize;
    //        y = (circle->pos().y()+20) / gridSize;
    //    }




    for(auto i = vec->begin(); i != vec->end();){

        int x_ = ((*i)->pos().x()+20) / gridSize;
        int y_ = ((*i)->pos().y()+20) / gridSize;
        if(labelNow[y_+x_*LENNUM]->toolName=="Deli"){

            (*i)->close();
            vec->erase(i);

            money+=value;
            QString str=QString("金币:%1").arg(this->money);
            label->setText(str);

            if(taskNum==1){
                if(order<=6){
                    collection++;
                    QString str2=QString("收集:%1/%2").arg(this->collection).arg(taskNeed);
                    label2->setText(str2);
                }
            }else if(taskNum==2){
                if(order>6){
                    collection++;
                    QString str2=QString("收集:%1/%2").arg(this->collection).arg(taskNeed);
                    label2->setText(str2);
                }
            }

            if(collection==taskNeed){
                QEventLoop loop(this);

                QTimer::singleShot(1000, &loop, SLOT(quit()));
                loop.exec();
                emit passLevel();
            }

            return;
        }else{
            i++;
        }
    }

    if(index==1 && labelNow[y+x*LENNUM]->toolName==""){
        emit stopCreate(order);
        qDebug()<<"budongle";
    }
    if(labelNow[y+x*LENNUM]->toolName==""){
        for(int i=0;i<=1;i++){
            if(labelAbandon[y+x*LENNUM][i]==-1){
                labelAbandon[y+x*LENNUM][i]=index;
                return;
            }
        }
        return;
    }
    if(labelNow[y+x*LENNUM]->toolName!=channelName && labelNow[y+x*LENNUM]->toolName!=diggerName) return;



    //判断当前格子方向来运动
    if(labelNow[y+x*LENNUM]->dre=="up"){

        shang(index,order);
    }else if(labelNow[y+x*LENNUM]->dre=="down"){
        xia(index,order);
    }else if(labelNow[y+x*LENNUM]->dre=="left"){
        zuo(index,order);
    }else if(labelNow[y+x*LENNUM]->dre=="right"){
        you(index,order);
    }


}


void Map::mousePressEvent(QMouseEvent *event)
{
    // 计算鼠标点击的方格位置
    int gridSize = 50;
    int x = event->pos().x() / gridSize;
    int y = event->pos().y() / gridSize;
    //左键
    if (event->buttons() & Qt::LeftButton){
        //注意数组越界
        if(!(event->pos().y()>=gridSize && event->pos().y()<=BOTTEMLINE)){
            return;
        }
        if(labelNow[y+x*LENNUM]->toolName==nowName){
            return;
        }

        if(nowImg=="") return;
        else if(event->pos().x()>=DELIVERY_X && event->pos().x()<=DELIVERY_X+100
                 && event->pos().y()>=DELIVERY_Y && event->pos().y()<=DELIVERY_Y+150) return;
        else if(nowImg==diggerImg && !(x>=2 && x<=4 && y>=7 && y<=8) && !(x>=12 && x<=13 && y>=2 && y<=3)) return;
        else{
            if(event->pos().y()>=gridSize && event->pos().y()<=BOTTEMLINE){

                //现在选了什么就给图标赋予哪个属性，每个label有自己的属性
                QTransform transform;
                transform.rotate(90*(numDre-1));
                labelNow[y+x*LENNUM]->dre=nowDre;
                labelNow[y+x*LENNUM]->toolName=nowName;
                qDebug()<<labelNow[y+x*LENNUM]->toolName;
                labelNow[y+x*LENNUM]->setParent(this);
                labelNow[y+x*LENNUM]->setFixedSize(gridSize,gridSize);
                labelNow[y+x*LENNUM]->setPixmap(QPixmap(nowImg).scaled(50,50,Qt::KeepAspectRatio).transformed(transform));
                labelNow[y+x*LENNUM]->move(x*gridSize,y*gridSize);
                labelNow[y+x*LENNUM]->show();



                //如果放了挖掘机,就开始判断矿物能不能走，往哪里走
                if(nowImg==diggerImg){
                    if(x==2 && y==7){
                        fresh1->start();
                        connect(fresh1,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });
                    }
                    else if(x==3 && y==7){
                        fresh2->start();
                        connect(fresh2,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });

                    }else if(x==4 && y==7){
                        fresh3->start();
                        connect(fresh3,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });

                    }else if(x==2 && y==8){
                        fresh4->start();
                        connect(fresh4,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });

                    }else if(x==3 && y==3){
                        fresh5->start();
                        connect(fresh5,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });
                    }
                    else if(x==4 && y==8){
                        fresh6->start();
                        connect(fresh6,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });
                    }else if(x==12 && y==2){
                        fresh7->start();
                        connect(fresh7,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });
                    }else if(x==13 && y==2){
                        fresh8->start();
                        connect(fresh8,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });
                    }else if(x==12 && y==3){
                        fresh9->start();
                        connect(fresh9,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });
                    }else if(x==13 && y==3){
                        fresh10->start();
                        connect(fresh10,&QTimer::timeout,[=](){
                            emit labelNow[y+x*LENNUM]->produceMineral(x,y);
                        });
                    }


                };

                if(nowName==rubbishName){
                    emit removeAll(x,y);
                }

                //如果在有丢弃物品的格子放一个朝上的通道

                //                if(nowName==channelName && nowDre==up){
                //                    for(int i=0;i<=1;i++){
                //                        if(labelAbandon[y+x*LENNUM][i]!=-1){
                //                            labelNow[y+x*LENNUM]->lower();
                ////                            emit goUp(x,y,labelAbandon[y+x*LENNUM][i]);

                //                        }
                //                    }

                //                }

                //                if(nowName==channelName && nowDre==down){
                //                    for(int i=0;i<=1;i++){
                //                        if(labelAbandon[y+x*LENNUM][i]!=-1){
                //                            labelNow[y+x*LENNUM]->lower();
                ////                            emit goDown(x,y,labelAbandon[y+x*LENNUM][i]);

                //                        }
                //                    }
                //                }

                //                if(nowName==channelName && nowDre==left){
                //                    for(int i=0;i<=1;i++){
                //                        if(labelAbandon[y+x*LENNUM][i]!=-1){
                //                            labelNow[y+x*LENNUM]->lower();
                ////                            emit goLeft(x,y,labelAbandon[y+x*LENNUM][i]);

                //                        }
                //                    }
                //                }

                //                if(nowName==channelName && nowDre==right){
                //                    for(int i=0;i<=1;i++){
                //                        if(labelAbandon[y+x*LENNUM][i]!=-1){
                //                            labelNow[y+x*LENNUM]->lower();
                ////                            emit goRight(x,y,labelAbandon[y+x*LENNUM][i]);

                //                        }
                //                    }
                //                }



            }

        }

    }

    //右键
    if (event->button() == Qt::RightButton && event->pos().y()>=gridSize && event->pos().y()<=BOTTEMLINE) {
        if(labelNow[y+x*LENNUM]->toolName==diggerName){
            if(x==2 && y==7){
                fresh1->stop();
            }
            else if(x==3 && y==7){
                fresh2->stop();

            }else if(x==4 && y==7){
                fresh3->stop();

            }else if(x==2 && y==8){
                fresh4->stop();

            }else if(x==3 && y==3){
                fresh5->stop();
            }
            else if(x==4 && y==8){
                fresh6->stop();
            }else if(x==12 && y==2){
                fresh7->stop();
            }else if(x==13 && y==2){
                fresh8->stop();
            }else if(x==12 && y==3){
                fresh9->stop();
            }else if(x==13 && y==3){
                fresh10->stop();
            }
        }
        labelNow[y+x*LENNUM]->toolName="";

        emit labelNow[y+x*LENNUM]->clearLabel();
    }
        QMainWindow::mousePressEvent(event);

    update(); // 刷新窗口
}

void Map::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_R)
    {
        numDre++;
        numDre=numDre%4;
        switch (numDre) {
        case 1:
            nowDre=up;
            break;
        case 2:
            nowDre=right;
            break;
        case 3:
            nowDre=down;
            break;
        case 0:
            nowDre=left;
            break;
        default:
            break;
        }
        emit labelDre->clearDre();
        //labelDre->clear();
        strDre=QString("当前方向:%1").arg(nowDre);
        labelDre->setText(strDre);
        labelDre->show();
    }
    else
    {
        QMainWindow::keyPressEvent(event); // 传递给基类处理其他键
    }
    update();
}

void Map::shang(int index,int order){
    QVector<QLabel *> *vec;
    if(order==1){
        vec=&vec_circle_1;
    }else if(order==2){
        vec=&vec_circle_2;
    }else if(order==3){
        vec=&vec_circle_3;
    }else if(order==4){
        vec=&vec_circle_4;
    }else if(order==5){
        vec=&vec_circle_5;
    }else if(order==6){
        vec=&vec_circle_6;
    }else if(order==7){
        vec=&vec_rect_1;
    }else if(order==8){
        vec=&vec_rect_2;
    }else if(order==9){
        vec=&vec_rect_3;
    }else if(order==10){
        vec=&vec_rect_4;
    }
    if((*vec)[index]->pos().y()-28*speed<=GRIDSIZE) return;
    (*vec)[index]->move((*vec)[index]->pos().x(),(*vec)[index]->pos().y()-28*speed);

}
void Map::xia(int index,int order){
    QVector<QLabel *> *vec;
    if(order==1){
        vec=&vec_circle_1;
    }else if(order==2){
        vec=&vec_circle_2;
    }else if(order==3){
        vec=&vec_circle_3;
    }else if(order==4){
        vec=&vec_circle_4;
    }else if(order==5){
        vec=&vec_circle_5;
    }else if(order==6){
        vec=&vec_circle_6;
    }else if(order==7){
        vec=&vec_rect_1;
    }else if(order==8){
        vec=&vec_rect_2;
    }else if(order==9){
        vec=&vec_rect_3;
    }else if(order==10){
        vec=&vec_rect_4;
    }
    if((*vec)[index]->pos().y()+28*speed>=BOTTEMLINE) return;

    (*vec)[index]->move((*vec)[index]->pos().x(),(*vec)[index]->pos().y()+28*speed);
}
void Map::zuo(int index,int order){
    QVector<QLabel *> *vec;
    if(order==1){
        vec=&vec_circle_1;
    }else if(order==2){
        vec=&vec_circle_2;
    }else if(order==3){
        vec=&vec_circle_3;
    }else if(order==4){
        vec=&vec_circle_4;
    }else if(order==5){
        vec=&vec_circle_5;
    }else if(order==6){
        vec=&vec_circle_6;
    }else if(order==7){
        vec=&vec_rect_1;
    }else if(order==8){
        vec=&vec_rect_2;
    }else if(order==9){
        vec=&vec_rect_3;
    }else if(order==10){
        vec=&vec_rect_4;
    }
    if((*vec)[index]->pos().x()-28*speed<=0) return;
    (*vec)[index]->move((*vec)[index]->pos().x()-28*speed,(*vec)[index]->pos().y());
}
void Map::you(int index,int order){
    QVector<QLabel *> *vec;
    if(order==1){
        vec=&vec_circle_1;
    }else if(order==2){
        vec=&vec_circle_2;
    }else if(order==3){
        vec=&vec_circle_3;
    }else if(order==4){
        vec=&vec_circle_4;
    }else if(order==5){
        vec=&vec_circle_5;
    }else if(order==6){
        vec=&vec_circle_6;
    }else if(order==7){
        vec=&vec_rect_1;
    }else if(order==8){
        vec=&vec_rect_2;
    }else if(order==9){
        vec=&vec_rect_3;
    }else if(order==10){
        vec=&vec_rect_4;
    }
    if((*vec)[index]->pos().x()+28*speed>=WIDTHLINE) return;
    (*vec)[index]->move((*vec)[index]->pos().x()+28*speed,(*vec)[index]->pos().y());
}
//void Map::abandonUp(int x,int y,int index,QVector<QLabel *> vec){
//    for(int i=0;i<=1;i++){
//        if(labelAbandon[y+x*LENNUM][i]==index){
//            labelAbandon[y+x*LENNUM][i]=-1;
//        }
//    }
//    shang(index,x,y,vec);
//    canMove(vec[index],vec);
//}
//void Map::abandonDown(int x,int y,int index,QVector<QLabel *> vec){
//    for(int i=0;i<=1;i++){
//        if(labelAbandon[y+x*LENNUM][i]==index){
//            labelAbandon[y+x*LENNUM][i]=-1;
//        }
//    }
//    xia(index,x,y,vec);
//    canMove(vec[index],vec);
//}
//void Map::abandonLeft(int x,int y,int index,QVector<QLabel *> vec){
//    for(int i=0;i<=1;i++){
//        if(labelAbandon[y+x*LENNUM][i]==index){
//            labelAbandon[y+x*LENNUM][i]=-1;
//        }
//    }
//    zuo(index,x,y,vec);
//    canMove(vec[index],vec);
//}
//void Map::abandonRight(int x,int y,int index,QVector<QLabel *> vec){
//    for(int i=0;i<=1;i++){
//        if(labelAbandon[y+x*LENNUM][i]==index){
//            labelAbandon[y+x*LENNUM][i]=-1;
//        }
//    }
//    you(index,x,y,vec);
//    canMove(vec[index],vec);
//}










