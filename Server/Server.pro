TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += concurrent

DEFINES += ZMQ_STATIC
LIBS += -L$$PWD/../lib -lnzmqt -lzmqlib -lws2_32 -lIphlpapi
INCLUDEPATH += $$PWD/../include

SOURCES += main.cpp \
    benternet.cpp

HEADERS += \
    $$PWD/../include/nzmqt/nzmqt.hpp \
    $$PWD/../include/nzmqt/global.hpp \
    $$PWD/../include/nzmqt/impl.hpp \
    benternet.h \
    game.h
