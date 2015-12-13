#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
#include <vector>

MainWindow::MainWindow(std::vector<double> pvectorX, std::vector<double> pvectorY, std::vector<int> pmainVector, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vectorX = pvectorX;
    vectorY = pvectorY;
    mainVector = pmainVector;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    double CONST_TRANS = 0.15; //This is the constant value by which we appropriately transform our data

    QPainter painter(this);

    //Update these values based on input signal vectors
    int SignalLengthX = (vectorX.size())*(CONST_TRANS);
    int SignalLengthY = (vectorY.size())*(CONST_TRANS);
    int adjSignalLengthY = SignalLengthY + 20;
    int adjSignalLengthX = SignalLengthX + 20;

    //build rectangles to form graph
    QRect rectangleX(110, (adjSignalLengthY + 55), adjSignalLengthX, 55);
    QRect rectangleY(50, 50, 55, adjSignalLengthY);
    QRect mainRect(110, 50, adjSignalLengthX, adjSignalLengthY);

    QPen framepen(Qt::black);
    framepen.setWidth(2);

    //Draw the rectangles built above on the GUI window
    painter.setPen(framepen);
    painter.drawRect(rectangleX);
    painter.drawRect(rectangleY);
    painter.drawRect(mainRect);

    //create second pen for drawing signals
    QPen signalpen(Qt::black);
    signalpen.setWidth(0);
    painter.setPen(signalpen);

    //create labels
    painter.setPen(Qt::black);
    painter.drawText(QPoint((adjSignalLengthX/1.5),(adjSignalLengthY+150)), "Query Index");
    painter.drawText(QPoint((105+(adjSignalLengthX/3)),35), "Timeseries alignment");

    double coordinateX = 115;

    //Create and initialize the points that will draw each signal
    int adjYvalue = (adjSignalLengthY + 105) - (50*(vectorX[0]));

    QPointF firstPoint;
    firstPoint.setX(coordinateX);
    firstPoint.setY(adjYvalue);

    QPointF secondPoint;

    //This loop will form the signal on the Xaxis
    for(int i = 1; i < vectorX.size(); i++)
    {
        adjYvalue = (adjSignalLengthY + 105) - (50*(vectorX[i]));
        secondPoint.setX(coordinateX);
        secondPoint.setY(adjYvalue);

        painter.drawLine(firstPoint,secondPoint);

        firstPoint = secondPoint;
        coordinateX = coordinateX + CONST_TRANS;
    }

    double coordinateY = adjSignalLengthY + 40;

    int adjXvalue = 100 - (50*(vectorY[0]));
    firstPoint.setX(adjXvalue);
    firstPoint.setY(coordinateY);

    //This loop will form the signal on the Yaxis
    for(int i = 1; i < vectorY.size(); i++)
    {
        adjXvalue = 100 - (50*(vectorY[i]));
        secondPoint.setX(adjXvalue);
        secondPoint.setY(coordinateY);

        painter.drawLine(firstPoint,secondPoint);

        firstPoint = secondPoint;
        coordinateY = coordinateY - CONST_TRANS;
    }


    QPen scalepen(Qt::black);//will be used to create the scale bars of each signal box
    scalepen.setWidth(1);

    QPointF scalePointX1;
    QPointF scalePointX2;

    painter.setPen(scalepen);

    double IncNum = 0;
    int labelNum = 0;
    QString label;

    //This while loop will create the appropriate number of scale bars for the x-axis
    //of the x-axis signal box
    while(SignalLengthX >= 0)
    {
        scalePointX1.setX(120 + IncNum);
        scalePointX1.setY(adjSignalLengthY + 110);

        scalePointX2.setX(120 + IncNum);
        scalePointX2.setY(adjSignalLengthY + 115);

        label = QString::number(labelNum);

        painter.drawText(QPoint((115+IncNum),(adjSignalLengthY+130)), label);//draws scale labels

        labelNum = 500 + labelNum;

        IncNum = IncNum + (500*(CONST_TRANS));
        SignalLengthX = SignalLengthX - (500*(CONST_TRANS));

        painter.drawLine(scalePointX1,scalePointX2);
    }

    IncNum = 2.5;

    //Since the values from the signal have been normalized this for loop will always set up the same
    //number of scale bars for the y-axis of the x-axis signal box
    for(int j = 0; j < 6; j++)
    {
        scalePointX1.setX(110);
        scalePointX1.setY(IncNum + (adjSignalLengthY + 55));

        scalePointX2.setX(105);
        scalePointX2.setY(IncNum + (adjSignalLengthY + 55));

        IncNum = IncNum + 10;
        painter.drawLine(scalePointX1,scalePointX2);
    }

    QPointF scalePointY1;
    QPointF scalePointY2;

    labelNum = 0;
    label;

    IncNum = 0;

    //This while loop will create the appropriate number of scale bars for the x-axis
    //of the y-axis signal box
    while(SignalLengthY >= 0)
    {
        scalePointY1.setX(50);
        scalePointY1.setY(IncNum + 60);

        scalePointY2.setX(45);
        scalePointY2.setY(IncNum + 60);

        label = QString::number(labelNum);

        painter.drawText(QPoint(10,(IncNum + 65)), label);//draws scale labels

        labelNum = 500 + labelNum;

        IncNum = IncNum + (500*(CONST_TRANS));
        SignalLengthY = SignalLengthY - (500*(CONST_TRANS));

        painter.drawLine(scalePointY1,scalePointY2);
    }

    IncNum = 2.5;

    //Since the values from the signal have been normalized this for loop will always set up the same
    //number of scale bars for the y-axis of the y-axis signal box
    for(int j = 0; j < 6; j++)
    {
        scalePointY1.setX(50 + IncNum);
        scalePointY1.setY(50);

        scalePointY2.setX(50 + IncNum);
        scalePointY2.setY(45);

        IncNum = IncNum + 10;
        painter.drawLine(scalePointY1,scalePointY2);
    }

    double Xposition = 120;
    double Yposition = adjSignalLengthY + 40;

    QPointF mainPoint1;
    mainPoint1.setX(Xposition);
    mainPoint1.setY(Yposition);

    QPointF mainPoint2;

    mainPoint1.setX(120);

    //This for loop will create the results of the DTW algorithm used to match the two signals
    for(int z = 0; z < mainVector.size(); z++)
    {
        if(mainVector[z] > 0)
        {
            //move vertically
            Yposition = Yposition - CONST_TRANS;

            mainPoint2.setX(Xposition);
            mainPoint2.setY(Yposition);

            painter.drawLine(mainPoint1, mainPoint2);

            mainPoint1 = mainPoint2;
        }
        else if(mainVector[z] < 0)
        {
            //move horizontally
            Xposition = Xposition + CONST_TRANS;

            mainPoint2.setX(Xposition);
            mainPoint2.setY(Yposition);

            painter.drawLine(mainPoint1, mainPoint2);

            mainPoint1 = mainPoint2;
        }
        else
        {
            //move diagonally
            Xposition = Xposition + CONST_TRANS;
            Yposition = Yposition  - CONST_TRANS;

            mainPoint2.setX(Xposition);
            mainPoint2.setY(Yposition);

            painter.drawLine(mainPoint1, mainPoint2);

            mainPoint1 = mainPoint2;
        }
    }

}
