#ifndef DRAWTOOL_H
#define DRAWTOOL_H


#include <QWidget>
#include <QPoint>
#include <QObject>

class drawTool : public QWidget
{
public:
    drawTool();
    QPoint startPosition;
    QPoint endPosition;
    QPainter painter();
    virtual void draw(QPoint start, QPoint end, QPixmap* canvas);
};

#endif // DRAWTOOL_H
