#-------------------------------------------------
#
# Project created by QtCreator 2011-03-04T17:34:20
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets

win32 {
    LIBS += -lopengl32
}

TARGET = Uebung01
TEMPLATE = app

SOURCES += \
    glwithwidgets.cpp \
    main.cpp \
    glwidget.cpp

HEADERS  += \
    glwithwidgets.h \
    glwidget.h

FORMS    += glwithwidgets.ui
