#include <QApplication>
#include <iostream>
#include "DTW_GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DTW_GUI w;
    w.show();

    return a.exec();
}
