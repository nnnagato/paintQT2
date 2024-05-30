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
                     ,start.y()+250
                     ,end.x()-100
                     ,end.y()+250);
//    pix->save("pic1.png",0,1);
}

//void LineTool::paintEvent(QPaintEvent* event)
//{
//    Q_UNUSED(event);

//    QPainter painter(pix);
//    painter.setPen(Qt::red);
//    painter.drawLine(startPosition, endPosition);
//    pix->save("pic0.png",0,1);
//}
