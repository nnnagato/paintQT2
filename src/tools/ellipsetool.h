#ifndef ELLIPSETOOL_H
#define ELLIPSETOOL_H

#include "workspace.h"
#include "drawtool.h"

class ellipseTool : public drawTool
{
public:
    ellipseTool();

private:
    void draw(QPoint start, QPoint end, QPixmap** canvas) override;
};

#endif // ELLIPSETOOL_H
