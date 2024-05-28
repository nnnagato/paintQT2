#include "rectTool.h"
#include "qmessagebox.h"

rectTool::rectTool()
{

}

void rectTool::draw()
{
    QMessageBox msg;
    msg.setText("rect");
    msg.exec();
}
