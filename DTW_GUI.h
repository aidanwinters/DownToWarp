#ifndef DTW_GUI_H
#define DTW_GUI_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
    class DTW_GUI;
}

class DTW_GUI : public QMainWindow
{
    Q_OBJECT

    public:
        explicit DTW_GUI(QWidget *parent = 0);
        ~DTW_GUI();

    private:
        Ui::DTW_GUI *ui;

    protected:
        void paintEvent(QPaintEvent* e);
};

#endif // DTW_GUI_H
