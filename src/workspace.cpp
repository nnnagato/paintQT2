#include "workspace.h"
#include "Ellipsetool.h"
#include "qmenu.h"
#include "qmessagebox.h"
#include "rectTool.h"
#include "ui_workspace.h"
#include "linetool.h"
#include "fibonachi.h"

#include <QPainter>
#include <QDebug>
#include <math.h>
#include <QFileDialog>
#include <QThread>

WorkSpace::WorkSpace(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkSpace)
{
    ui->setupUi(this);

    setupMenu();
    showMaximized();
    pixmap = new QPixmap(basePixmapWidth,basePixmapHeight);
    pixmap->fill(Qt::white);

    updatePixmap();
    scaleSize = 1;

    lineTool = new LineTool();
    rectTool = new RectTool();
    ellipseTool = new EllipseTool();
    currentTool = rectTool;

    fibThread = new QThread(nullptr);
    fib = new Fibonachi();
    fib->moveToThread(fibThread);
    fibThread->start();

    connect(fib, &Fibonachi::calced, this, [this]()
    {
        QString curFibs = QString("X1: %1\nX2: %2\nf: %3")
                .arg(fib->getFirstNumber())
                .arg(fib->getSecondnumber())
                .arg(fib->getCurrent());
        ui->fibonLabel->setText(curFibs);
    });

    connect(this, &WorkSpace::startCalc, fib, [this](){
        fib->calc(order);
        ui->counterLabel->setText("Расчёт...");
    });

    connect(fib, &Fibonachi::finished, this, [this](){
        on_calcFinished(fib->getResult());
    });
}

WorkSpace::~WorkSpace()
{
    delete ui;
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

    connect(actLine, &QAction::triggered, this, [this]()
    {
        currentTool = lineTool;
    });
    connect(actRect, &QAction::triggered, this, [this]()
    {
        currentTool = rectTool;
    });
    connect(actEllipse, &QAction::triggered, this, [this]()
    {
        currentTool = ellipseTool;
    });
}

void WorkSpace::setCoordinates(QPoint pos)
{
    QString tempCoords = QString("X: %1\nY: %2")
            .arg(pos.x())
            .arg(pos.y());
    ui->coordinatesLabel->setText(tempCoords);
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
    currentTool->draw(upperPosition, lowerPosition, *pixmap);
    updatePixmap();
}

void WorkSpace::mousePressEvent(QMouseEvent* event)
{
    startPosition = event->pos();
}

void WorkSpace::mouseMoveEvent(QMouseEvent* event)
{
    int delta = 300;
    setCoordinates(event->pos());
    if (event->pos().x()<delta)
    {
        ui->splitter->move(0,0);
    }
    else
    {
        ui->splitter->move(-delta, 0);
    }
}

void WorkSpace::updatePixmap()
{
    ui->canvasLabel->setPixmap(*pixmap);
}

void WorkSpace::on_savingButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as", QString(), "Images (*.png)");

    if (filename.isEmpty())
    {
        return;
    }

    pixmap->save(filename, nullptr, 1);
}

void WorkSpace::wheelEvent(QWheelEvent *event)
{
    const double scaleCoef = 1.01;
    scaleSize = event->angleDelta().y() > 0
            ? scaleSize * scaleCoef
            : scaleSize / scaleCoef;

    QSize canvasSize;
    canvasSize.setWidth((int)basePixmapWidth*scaleSize);
    canvasSize.setHeight((int)basePixmapWidth*scaleSize);

    *pixmap = pixmap->scaled(canvasSize, Qt::KeepAspectRatio);

    updatePixmap();
}


//qcustomplot на новый проект
//qjsonobject и это туда же
//qmutex на почитать

//мультипоточность
//в мультипотоке сунуть рассчёт числа фибоначи до выбранного порядка, плашку расчёт и вывод в неё же результата по завершению
//спинбокс с порядком кнопка с запуском



//графики пусть будет синуса


void WorkSpace::on_openButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open", QString(), "Images (*.png)");

    pixmap->load(filename, nullptr);
    updatePixmap();
}


void WorkSpace::on_execButton_clicked()
{
    order = ui->fibEdit->text().toInt();
    emit startCalc();
}

void WorkSpace::on_calcFinished(quint64 result)
{
    ui->counterLabel->setText(QString("Результат вычислений: %1")
            .arg(result));
}
