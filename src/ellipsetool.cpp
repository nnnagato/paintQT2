#include "ellipsetool.h"
#include "qmessagebox.h"

ellipseTool::ellipseTool()
{

}

void ellipseTool::draw()
{
    QMessageBox msg;
    msg.setText("Ellipse");
    msg.exec();
}
