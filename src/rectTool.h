#ifndef RECTTOOL_H
#define RECTTOOL_H

#include "drawtool.h"

class rectTool : public drawTool
{
public:
    rectTool();

private:
    void draw() override;
};

#endif // RECTTOOL_H
