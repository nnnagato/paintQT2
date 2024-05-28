#ifndef LINETOOL_H
#define LINETOOL_H

#include "drawtool.h"
#include <QPaintEvent>

class LineTool : public drawTool
{
public:
    LineTool();

protected:
    void paintEvent(QPaintEvent *event);

private:
    void draw(QPoint start, QPoint end, QPixmap* canvas) override;

private:
    QPixmap* pix;
//    void paintEvent(QPaintEvent* event);
};

#endif // LINETOOL_H
