include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS +=     tst_pitch.h

SOURCES +=     main.cpp


# QuickPitch dependencies

INCLUDEPATH += ../../src

SOURCES += ../../src/pitchobj.cpp
