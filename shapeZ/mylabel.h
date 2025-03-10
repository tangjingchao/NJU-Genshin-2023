#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QString>
#include <QDebug>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(int x,int y,QString dre,QString name);
    MyLabel(MyLabel *parent);
    ~MyLabel();
    int label_x;
    int label_y;
    QString toolName;
    QString dre;
signals:
    void clearLabel();
    void clearDre();
    void produceMineral(int x,int y);
};

#endif // MYLABEL_H
