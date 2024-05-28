#include "workspace.h"
#include "ellipsetool.h"
#include "qmenu.h"
#include "rectTool.h"
#include "ui_workspace.h"
#include "linetool.h"

#include <QPainter>
#include <QDebug>
#include <math.h>

WorkSpace::WorkSpace(QWidget *parent)
    : QMainWindow(parent)
//    , tool(new *drawTool)
    , ui(new Ui::WorkSpace)
{
    ui->setupUi(this);
    setupMenu();
    showMaximized();
    canvas = new QPixmap(2000,2000);
    canvas->fill(Qt::white);
    setStyleSheet("background : white");
    currentTool = new LineTool();//защита от дурака

}

void WorkSpace::setupMenu()
{
    menu = new QMenu(this);
    actLine = new QAction("line",this);
    actRect = new QAction("rect",this);
    actEllipse = new QAction("Ellipse",this);
    actLine->setObjectName("Line");
    actRect->setObjectName("Rect");
    actEllipse->setObjectName("Ellipse");
    menu->addAction(actLine);
    menu->addAction(actRect);
    menu->addAction(actEllipse);
    ui->toolsButton->setMenu(menu);
    connect(actLine,SIGNAL(triggered()),this,SLOT(toolSelector()));
    connect(actRect,SIGNAL(triggered()),this,SLOT(toolSelector()));
    connect(actEllipse,SIGNAL(triggered()),this,SLOT(toolSelector()));
}

void WorkSpace::setCoordinates(QPoint pos)
{
    QString tempCoords;
    tempCoords.append("X: ");
    tempCoords.append(QString::number(pos.x()));
    tempCoords.append("\nY: ");
    tempCoords.append(QString::number(pos.y()));
    ui->coordinatesLabel->setText(tempCoords);
}

void WorkSpace::toolSelector()
{
    QAction *act = qobject_cast<QAction*>(sender());
    if(act == actLine)
    {
        currentTool = new LineTool();
    };
    if(act==actRect)
    {
        currentTool = new rectTool();
    }
    if(act==actEllipse)
    {
        currentTool = new ellipseTool();
    }
}

void WorkSpace::getposition()
{
    startPosition.setX(std::min(startPosition.x(),endPosition.x()));
    startPosition.setY(std::min(startPosition.y(),endPosition.y()));
    endPosition.setX(std::max(startPosition.x(),endPosition.x()));
    endPosition.setY(std::max(startPosition.y(),endPosition.y()));
}

void WorkSpace::mouseReleaseEvent(QMouseEvent* event)
{
    endPosition = event->pos();
    getposition();
    currentTool->draw(startPosition, endPosition, canvas);
    update();
}

void WorkSpace::mousePressEvent(QMouseEvent* event)
{
    startPosition = event->pos();
}

void WorkSpace::mouseMoveEvent(QMouseEvent* event)
{
    setCoordinates(event->pos());
}

void WorkSpace::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter;
    painter.drawPixmap(0,0,*canvas);
}

WorkSpace::~WorkSpace()
{
    delete ui;
}

