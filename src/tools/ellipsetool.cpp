#include "ellipsetool.h"
#include "qmessagebox.h"

#include <QPainter>

ellipseTool::ellipseTool()
{

}

void ellipseTool::draw(QPoint start, QPoint end, QPixmap** canvas)
{
    QPainter painter(*canvas);
    painter.drawEllipse(start.x()-100
                        , start.y()
                        , end.x() - start.x()
                        , end.y() - start.y()
                        );
}
