#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include "Signal.h"
#include "DTW.h"

int main(int argc, char *argv[])
{
    std::vector<double> vectorX;
    std::vector<double> vectorY;
    std::vector<int> mainVector;


    if(argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << "<file1> " << "<file2>" << std::endl;
    }
    else
    {
        Signal Sx = new Signal(argv[1]);
        Signal Sy = new Signal(argv[2]);
        DTW main = new DTW(Sx, Sy);

        vectorX = Sx.getSignal();
        vectorY = Sy.getSignal();
        mainVector = main.getDirections();
    }

    QApplication a(argc, argv);
    MainWindow w (vectorX, vectorY, mainVector);
    w.show();

    return a.exec();
}
