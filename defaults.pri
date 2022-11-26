INCLUDEPATH += $$PWD/Utils/

SRC_DIR = $$PWD

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++20

QMAKE_CXXFLAGS += -Wpedantic -Werror
