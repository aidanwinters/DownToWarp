#-------------------------------------------------
#
# Project created by QtCreator 2015-12-07T12:50:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proj3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
	Signal.cpp\
	DTW.cpp\
	moc_mainwindow.cpp
	
HEADERS  += mainwindow.h\
	DTW.h\
	Signal.h\
	ui_mainwindow.h

FORMS    += mainwindow.ui
