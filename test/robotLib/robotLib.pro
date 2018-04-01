TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bouncingMode.cpp \
    CircleMode.cpp \
    robotinoDUE.cpp

HEADERS += \
    bouncingMode.h \
    CircleMode.h \
    robotinoDUE.h
