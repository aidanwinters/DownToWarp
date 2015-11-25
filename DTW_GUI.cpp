#include "DTW_GUI.h"
#include "ui_DTW_GUI.h"

DTW_GUI::DTW_GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DTW_GUI)
{
    ui->setupUi(this);
}

DTW_GUI::~DTW_GUI()
{
    delete ui;
}

void DTW_GUI::paintEvent(QPaintEvent *e)
{
    // This is an example paintEvent method only.  You should
    // modify appropriately, consulting Qt references for 
    //alternate components to do the job you need....
    
     QPainter painter(this);
    
     QPen pointPen(Qt::black);
     pointPen.setWidth(6);
    
     QPen linePen(Qt::red);
     linePen.setWidth(2);
    
     QPoint p1,p2;
     p1.setX(10); p1.setY(10);
     p2.setX(100); p2.setY(100);
    
     painter.setPen(linePen);
     painter.drawLine(p1,p2);
    
     painter.setPen(pointPen);
     painter.drawRect(QRect(10,10,40,40));
}
