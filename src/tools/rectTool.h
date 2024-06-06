#ifndef RECTTOOL_H
#define RECTTOOL_H

#include "drawtool.h"

class RectTool : public DrawTool
{
public:
    RectTool();

private:
    void draw(const QPoint& start, const QPoint& end, QPixmap& canvas) override;
};

#endif // RECTTOOL_H
