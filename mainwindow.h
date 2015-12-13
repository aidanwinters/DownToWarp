#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::vector<double> pvectorX, std::vector<double> pvectorY, std::vector<int> pmainVector, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<double> vectorX;
    std::vector<double> vectorY;
    std::vector<int> mainVector;

protected:
    void paintEvent(QPaintEvent *e);
};

#endif // MAINWINDOW_H
