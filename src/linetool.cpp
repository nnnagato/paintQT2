#include "linetool.h"
#include "qevent.h"
#include "qmessagebox.h"

#include <QPainter>

LineTool::LineTool()
{

}


void LineTool::draw(QPoint start, QPoint end, QPixmap* canvas)
{
    startPosition = start;
    endPosition = end;
    pix = canvas;
    update();
}

void LineTool::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(pix);
    painter.setPen(Qt::red);
    painter.drawLine(startPosition, endPosition);
}
