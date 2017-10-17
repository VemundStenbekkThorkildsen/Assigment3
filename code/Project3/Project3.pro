TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -LC:\Armadillo\newblas -llibblas
LIBS += -LC:\Armadillo\newblas -lliblapack


INCLUDEPATH += C:\Qt\armadillo-8.100.1\include
DEPENDPATH += C:\Qt\armadillo-8.100.1\include


SOURCES += main.cpp \
    planets.cpp

HEADERS += \
    planets.h


