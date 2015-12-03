/********************************************************************************
** Form generated from reading UI file 'DTW_GUI.ui'
**
** Created: Wed Dec 2 18:03:40 2015
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTW_GUI_H
#define UI_DTW_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DTW_GUI
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DTW_GUI)
    {
        if (DTW_GUI->objectName().isEmpty())
            DTW_GUI->setObjectName(QString::fromUtf8("DTW_GUI"));
        DTW_GUI->resize(400, 335);
        centralWidget = new QWidget(DTW_GUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DTW_GUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DTW_GUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        DTW_GUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DTW_GUI);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DTW_GUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DTW_GUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DTW_GUI->setStatusBar(statusBar);

        retranslateUi(DTW_GUI);

        QMetaObject::connectSlotsByName(DTW_GUI);
    } // setupUi

    void retranslateUi(QMainWindow *DTW_GUI)
    {
        DTW_GUI->setWindowTitle(QApplication::translate("DTW_GUI", "DTW_GUI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DTW_GUI: public Ui_DTW_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTW_GUI_H
