#include "linetool.h"
#include "qevent.h"
#include "qmessagebox.h"

#include <QPainter>

LineTool::LineTool()
{

}


void LineTool::draw(const QPoint& start, const QPoint& end, QPixmap& canvas)
{
    QPainter painter(&canvas);
    painter.drawLine(start.x()-100
                     ,start.y()
                     ,end.x()-100
                     ,end.y());
}

