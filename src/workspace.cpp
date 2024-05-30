#include "workspace.h"
#include "ellipsetool.h"
#include "qmenu.h"
#include "rectTool.h"
#include "ui_workspace.h"
#include "linetool.h"

#include <QPainter>
#include <QDebug>
#include <math.h>
#include <QFileDialog>

WorkSpace::WorkSpace(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkSpace)
{
    ui->setupUi(this);
    setupMenu();
    showMaximized();
    canvas = new QPixmap(1920,1080);
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
    tempCoords.append(QString::number(pos.x()-100));
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
    upperPosition.setX((std::min(startPosition.x(), endPosition.x())));
    upperPosition.setY((std::min(startPosition.y(), endPosition.y())));
    lowerPosition.setX((std::max(startPosition.x(), endPosition.x())));
    lowerPosition.setY((std::max(startPosition.y(), endPosition.y())));
}

void WorkSpace::mouseReleaseEvent(QMouseEvent* event)
{
    endPosition = event->pos();
    getposition();
    currentTool->draw(upperPosition, lowerPosition, &canvas);
    update();
}

void WorkSpace::mousePressEvent(QMouseEvent* event)
{
    startPosition = event->pos();
}

void WorkSpace::mouseMoveEvent(QMouseEvent* event)
{
    if(event->pos().x()>100)
    {
    setCoordinates(event->pos());

    }
}

void WorkSpace::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    ui->testLabel->setPixmap(*canvas);

}

void WorkSpace::on_savinButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as");

    if(filename.isEmpty())
        return;

    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

    canvas->save(filename,0,1);
    file.close();
}

WorkSpace::~WorkSpace()
{
    delete ui;
}
