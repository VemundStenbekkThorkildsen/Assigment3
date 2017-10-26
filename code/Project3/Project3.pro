TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    solarsystem.cpp \
    body.cpp \
    verlet.cpp \
    components.cpp

HEADERS += \
    solarsystem.h \
    body.h \
    verlet.h \
    components.h

QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
