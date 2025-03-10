//#include "mymineral.h"

//MyMineral::MyMineral(bool isNeed)
//{



////    timer.setParent(this);
////    connect(&timer, &QTimer::timeout,this, [&](){
////        moveOn();
////        count++;
////        qDebug()<<count;
////        if(count==2){
////            timer.blockSignals(true);
////        }
////    });
//    // 启动计时器，设置为 5 秒后触发 timeout 信号
////    timer.start(50);

//    //设置速度
//    speed = 50;

//    //是不是需要的矿物
//    is_need=isNeed;
//}

//MyMineral::MyMineral(MyMineral *parent){
//    speed=parent->speed;
//}

//void MyMineral::stopMove(){
//    speed=0;
//}

//void MyMineral::moveOn()
//{
//     //如果对象移出场景

////    if (pos().y() > BOTTEMLINE-225 || pos().y() < GRIDSIZE-225 || pos().x() > SCENEWIDTH || pos().x() <0) {
////        timer.stop();
////        emit closeMineral();
////    }
////    //如果对象交付
////    if (pos().x()>=DELIVERY_X && pos().x()<=DELIVERY_X+100
////        && pos().y()>=DELIVERY_Y-225 && pos().y()<=DELIVERY_Y-75) {
////        timer.stop();

////        obtainMoney+=REWARD;
////        counter++;

////        emit closeMineral();
////    }
//    // 根据当前指向移动

//    if(numDre=="up"){//上
//        move(x(), y() - speed);
//        qDebug()<<"up";
//    }else if(numDre=="right"){
//        move(x()+speed, y());
//    }else if(numDre=="down"){
//        move(x(), y()+speed);
//    }else if(numDre=="left"){
//        move(x()-speed, y());
//    }else{
//        return;
//    }
//}











