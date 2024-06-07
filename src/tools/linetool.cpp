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
    painter.setPen(QPen(Qt::black,3,Qt::SolidLine));
    painter.drawLine(start.x()
                     ,start.y()
                     ,end.x()
                     ,end.y());
}

