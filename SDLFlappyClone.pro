TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    csprite.cpp \
    xenfautils.cpp \
    cbackground.cpp \
    cflappy.cpp \
    cpipe.cpp \
    ccounter.cpp \
    cfpscounter.cpp

unix:
{
    LIBS += -lGLU -lGL -lSDL2 -lSDL2_image -lSDL2_mixer
}
win32:
{
    LIBS += -lGLU -lGL -lSDL2 -lSDL2_image -lSDL2_mixer
}

HEADERS += \
    csprite.h \
    vars.h \
    xenfautils.h \
    cbackground.h \
    cflappy.h \
    cpipe.h \
    ccounter.h \
    cfpscounter.h
