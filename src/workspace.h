#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "drawtool.h"
#include "linetool.h"

#include <QMainWindow>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class WorkSpace; }
QT_END_NAMESPACE

class WorkSpace : public QMainWindow
{
    Q_OBJECT

public:
    WorkSpace(QWidget *parent = nullptr);
    ~WorkSpace();

signals:


protected:
//    void paintEvent(QPaintEvent *event);

private slots:
    void toolSelector();

private:
//    drawTool& tool;
    Ui::WorkSpace *ui;
    QMenu *menu;
    QAction *actLine;
    QAction *actRect;
    QAction *actEllipse;
    QAction *actPen;

//    LineTool Line;


};
#endif // WORKSPACE_H
