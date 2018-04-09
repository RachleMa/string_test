TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mysrting.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    mysrting.h

