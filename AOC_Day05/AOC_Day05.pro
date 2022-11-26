INCLUDEPATH += ../Utils
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        vent.cpp \
        ventssolver.cpp

HEADERS += \
    vent.h \
    ventssolver.h
