#ifndef LINETOOL_H
#define LINETOOL_H

#include "drawtool.h"
#include <QPaintEvent>

class LineTool : public DrawTool
{
public:
    LineTool();

protected:

private:
    void draw(const QPoint& start, const QPoint& end, QPixmap& canvas) override;

private:
};

#endif // LINETOOL_H
