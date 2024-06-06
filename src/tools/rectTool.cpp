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
    painter.drawRect(start.x()-100
                     , start.y()
                     , end.x() - start.x()
                     , end.y() - start.y()
                     );
}
