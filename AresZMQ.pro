CONFIG += c++17

include($$PWD/lua533/lua.pri)

include($$PWD/ZeroMQ/ZeroMQ.pri)

QT = core 

TEMPLATE = lib

DESTDIR=$$PWD/bin

INCLUDEPATH += \
    $$PWD/src


HEADERS += \
    src/Singleton.h \
    src/ZmqContext.h \
    src/ZmqMessageRouter.h \
    src/ZmqMonitor.h \
    src/ZmqPoller.h \
    src/ZmqSocket.h \
    src/ZmqTimer.h \
    src/myprintf.h
    
SOURCES += \
    src/ZmqContext.cpp \
    src/ZmqMessageRouter.cpp \
    src/ZmqMonitor.cpp \
    src/ZmqPoller.cpp \
    src/ZmqSocket.cpp \
    src/ZmqTimer.cpp \
    src/lua_AresZMQ.cpp



