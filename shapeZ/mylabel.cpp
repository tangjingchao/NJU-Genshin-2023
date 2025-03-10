#include "mylabel.h"

MyLabel::MyLabel(MyLabel *parent) : QLabel(parent)
{
    if(parent==this) return;
    label_x=parent->label_x;
    label_y=parent->label_y;
}

MyLabel::MyLabel(int x,int y,QString Dre,QString name)
{
    label_x=x;
    label_y=y;
    dre=Dre;
}

MyLabel::~MyLabel(){
    this->close();
}
