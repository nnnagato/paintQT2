#ifndef ELLIPSETOOL_H
#define ELLIPSETOOL_H

//#include "workspace.h"
#include "drawtool.h"

class EllipseTool : public DrawTool
{
public:
    EllipseTool();

private:
    void draw(const QPoint& start, const QPoint& end, QPixmap& canvas) override;
};

#endif // ELLIPSETOOL_H
