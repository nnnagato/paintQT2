#ifndef ELLIPSETOOL_H
#define ELLIPSETOOL_H

#include "drawtool.h"

class ellipseTool : public drawTool
{
public:
    ellipseTool();

private:
    void draw() override;
};

#endif // ELLIPSETOOL_H
