#ifndef RECTTOOL_H
#define RECTTOOL_H

#include "drawtool.h"

class rectTool : public drawTool
{
public:
    rectTool();

private:
    void draw(QPoint start, QPoint end, QPixmap* canvas) override;
};

#endif // RECTTOOL_H
