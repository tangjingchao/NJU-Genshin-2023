#ifndef STORE_H
#define STORE_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class Store;
}

class Store : public QMainWindow
{
    Q_OBJECT

public:
    explicit Store(QMainWindow *parent = nullptr);
    ~Store();
    int value=1;
    QLabel *num=new QLabel(this);

signals:
    void returnMap();
    void addValue(int value);
private:
    Ui::Store *ui;
};

#endif // STORE_H
