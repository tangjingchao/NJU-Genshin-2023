#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QPushButton>
#include "map.h"
#include "ui_map.h"
#include <QMediaPlayer>
#include <QMediaPlayList>
#include <QSoundEffect>
#include "gradescene.h"
#include "ui_gradescene.h"
#include "store.h"
#include "ui_store.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //重写绘图事件
    void paintEvent(QPaintEvent *);
    void changeAll(int value);
    Map *mapscene1=new Map(this,1);
    Map *mapscene2=new Map(this,2);
    Map *mapscene3=new Map(this,2);
    GradeScene *gradescene1=new GradeScene(this);
    GradeScene *gradescene2=new GradeScene(this);

    Store *store=new Store(this);
    int level=1;


private slots:

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
