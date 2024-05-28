#ifndef DRAWTOOL_H
#define DRAWTOOL_H

#include <Qwidget>
#include <QPoint>
#include <QObject>

class drawTool : public QWidget
{
public:
    drawTool();
    QPoint startPosition;
    QPoint endPosition;
    virtual void draw();
};

#endif // DRAWTOOL_H
