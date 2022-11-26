INCLUDEPATH += ../Utils
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bingo.cpp \
        bingosolver.cpp \
        main.cpp

HEADERS += \
    bingo.h \
    bingosolver.h
