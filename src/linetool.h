#ifndef LINETOOL_H
#define LINETOOL_H

#include "drawtool.h"

class LineTool : public drawTool
{
public:
    LineTool();

private:
    void draw() override;
};

#endif // LINETOOL_H
