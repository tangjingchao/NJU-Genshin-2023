#ifndef GRADE_H
#define GRADE_H

#include <QMainWindow>

namespace Ui {
class GradeScene;
}

class GradeScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit GradeScene(QMainWindow *parent = nullptr);

    ~GradeScene();
signals:
    void gradeChannel();
    void gradeDigger();

private:
    Ui::GradeScene *ui;
};

#endif // GRADE_H
