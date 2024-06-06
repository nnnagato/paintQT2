#ifndef DRAWTOOL_H
#define DRAWTOOL_H


#include <QWidget>
#include <QPoint>
#include <QObject>

class DrawTool
{
public:
    DrawTool();
//    virtual ~drawTool() = default;

    virtual void draw(const QPoint& start, const QPoint& end, QPixmap& canvas);
};

#endif // DRAWTOOL_H
