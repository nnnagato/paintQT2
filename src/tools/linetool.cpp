#include "linetool.h"
#include "qevent.h"
#include "qmessagebox.h"

#include <QPainter>

LineTool::LineTool()
{

}


void LineTool::draw(QPoint start, QPoint end, QPixmap** canvas)
{
    pix = *canvas;
    QPainter painter(pix);
    painter.drawLine(start.x()-100
                     ,start.y()
                     ,end.x()-100
                     ,end.y());
}

