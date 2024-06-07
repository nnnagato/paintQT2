#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "drawtool.h"
#include "fibonachi.h"

#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>

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
    void startCalc();

protected:
    void mouseReleaseEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent *event);

private slots:
    void on_savingButton_clicked();
    void on_openButton_clicked();
    void on_execButton_clicked();

private:
    void getposition();
    void setupMenu();
    void setCoordinates(QPoint pos);
    void updatePixmap();
    void on_calcFinished(quint64 result);

private:
    Ui::WorkSpace *ui;

    QMenu *menu;
    QAction *actLine;
    QAction *actRect;
    QAction *actEllipse;

    QPoint startPosition;
    QPoint endPosition;
    QPoint upperPosition;
    QPoint lowerPosition;
    QPixmap* pixmap;
    qreal scaleSize;

    DrawTool* currentTool = nullptr;
    DrawTool* lineTool = nullptr;
    DrawTool* rectTool = nullptr;
    DrawTool* ellipseTool = nullptr;

    Fibonachi* fib = nullptr;
    QThread* fibThread = nullptr;


    int order;
    const int basePixmapHeight = 1080;
    const int basePixmapWidth = 2120;
};
#endif // WORKSPACE_H
