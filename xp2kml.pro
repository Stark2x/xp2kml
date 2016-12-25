TARGET = xp2kml
TEMPLATE = lib
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += \
    console \
    c++11

QT -= \
    gui

DEFINES += \
    XPLM200 \
    XPLM210 \
    XP2KML_LIBRARY

win32 {
    contains(QMAKE_HOST.arch, x86_64) {
        LIBS += \
            -L../code/inc/XPlane-SDK/Libraries/Win \
            -lXPLM_64 \
            -lXPWidgets_64
    } else {
        LIBS += \
            -lXPLM \
            -lXPWidgets
    }
    DEFINES += \
        APL=0 \
        IBM=1 \
        LIN=0
    QMAKE_CXXFLAGS = -shared -std=c++11
    QMAKE_LFLAGS = -static -static-libgcc -static-libstdc++
}


unix:!macx {
    DEFINES += \
        APL=0 \
        IBM=0 \
        LIN=1
    QMAKE_CXXFLAGS = -shared -std=c++11
    QMAKE_LFLAGS = -static -static-libgcc -static-libstdc++
}


INCLUDEPATH += \
    inc/XPlane-SDK/CHeaders/XPLM

SOURCES += \
    main.cpp \
    kmlclient.cpp

HEADERS += \
    kmlclient.h
