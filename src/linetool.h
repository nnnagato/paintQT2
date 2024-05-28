#ifndef LINETOOL_H
#define LINETOOL_H
#include "drawtool.h"

#include <QObject>

class LineTool : public drawTool
{
public:
    LineTool();
    void draw() override;
};

#endif // LINETOOL_H
