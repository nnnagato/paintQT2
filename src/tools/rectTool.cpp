#include "rectTool.h"
#include "qmessagebox.h"

#include <QPainter>

RectTool::RectTool()
{

}

void RectTool::draw(const QPoint& start, const QPoint& end, QPixmap& canvas)
{
//    pix = *canvas;
    QPainter painter(&canvas);
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine));
    painter.drawRect(start.x()
                     , start.y()
                     , end.x() - start.x()
                     , end.y() - start.y()
                     );
}
