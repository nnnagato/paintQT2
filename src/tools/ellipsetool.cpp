#include "Ellipsetool.h"
#include "qmessagebox.h"

#include <QPainter>

EllipseTool::EllipseTool()
{

}

void EllipseTool::draw(const QPoint& start, const QPoint& end, QPixmap& canvas)
{
    QPainter painter(&canvas);
    painter.setPen(QPen(Qt::black,3,Qt::SolidLine));
    painter.drawEllipse(start.x()
                        , start.y()
                        , end.x() - start.x()
                        , end.y() - start.y()
                        );
}
