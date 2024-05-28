#include "ellipsetool.h"
#include "qmessagebox.h"

ellipseTool::ellipseTool()
{

}

void ellipseTool::draw(QPoint start, QPoint end, QPixmap* canvas)
{
    QMessageBox msg;
    msg.setText("Ellipse");
    msg.exec();
}
