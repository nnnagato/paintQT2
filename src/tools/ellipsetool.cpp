#include "ellipsetool.h"
#include "qmessagebox.h"

#include <QPainter>

EllipseTool::EllipseTool()
{

}

void EllipseTool::draw(const QPoint& start, const QPoint& end, QPixmap& canvas)
{
    QPainter painter(&canvas);
    painter.drawEllipse(start.x()-100
                        , start.y()
                        , end.x() - start.x()
                        , end.y() - start.y()
                        );
}
