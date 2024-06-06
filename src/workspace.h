#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "drawtool.h"
#include "linetool.h"

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

protected:
    void mouseReleaseEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent *event);

private slots:
//    void toolSelector();
    void on_savingButton_clicked();
    void on_openButton_clicked();

private:
    void getposition();
    void setupMenu();
    void setCoordinates(QPoint pos);
    void updatePixmap();

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

    const int basePixmapHeight = 1080;
    const int basePixmapWidth = 1920;
};
#endif // WORKSPACE_H
