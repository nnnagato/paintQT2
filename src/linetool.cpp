#include "linetool.h"
#include "qmessagebox.h"

LineTool::LineTool()
{

}


void LineTool::draw()
{
    QMessageBox msg;
    msg.setText("Line");
    msg.exec();
}
