#include "rectTool.h"
#include "qmessagebox.h"

rectTool::rectTool()
{

}

void rectTool::draw(QPoint start, QPoint end, QPixmap* canvas)
{
    QMessageBox msg;
    msg.setText("rect");
    msg.exec();
}
