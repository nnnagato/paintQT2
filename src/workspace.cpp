#include "workspace.h"
#include "qmenu.h"
#include "ui_workspace.h"

#include <QDebug>

WorkSpace::WorkSpace(QWidget *parent)
    : QMainWindow(parent)
//    , tool(new *drawTool)
    , ui(new Ui::WorkSpace)
{
    ui->setupUi(this);
    menu = new QMenu(this);
    actLine = new QAction("line",this);
    actRect = new QAction("rect",this);
    actEllipse = new QAction("Ellipse",this);
    actPen = new QAction("Pen",this);
    actLine->setObjectName("Line");
    actRect->setObjectName("Rect");
    actEllipse->setObjectName("Ellipse");
    actPen->setObjectName("Pen");
    menu->addAction(actLine);
    menu->addAction(actRect);
    menu->addAction(actEllipse);
    menu->addAction(actPen);
    ui->toolsButton->setMenu(menu);
    connect(actLine,SIGNAL(triggered()),this,SLOT(toolSelector()));
    connect(actRect,SIGNAL(triggered()),this,SLOT(toolSelector()));
    connect(actEllipse,SIGNAL(triggered()),this,SLOT(toolSelector()));
    connect(actPen,SIGNAL(triggered()),this,SLOT(toolSelector()));
    showMaximized();

//    LineTool* Line = new LineTool();
//    tool = *new drawTool;
}

void WorkSpace::toolSelector()
{
    QAction *act = qobject_cast<QAction*>(sender());
    if(act == actLine)
    {

    };
    if(act==actRect)
    {

    }
}

WorkSpace::~WorkSpace()
{
    delete ui;
}

