#include "rectTool.h"
#include "qmessagebox.h"

#include <QPainter>

rectTool::rectTool()
{

}

void rectTool::draw(QPoint start, QPoint end, QPixmap** canvas)
{
//    pix = *canvas;
    QPainter painter(*canvas);
    painter.drawRect(start.x()-100
                     , start.y()
                     , end.x() - start.x()
                     , end.y() - start.y()
                     );
}
