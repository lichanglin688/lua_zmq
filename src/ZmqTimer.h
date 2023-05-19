#ifndef ZMQTIMER_H
#define ZMQTIMER_H

#include <QObject>
#include <QThread>
#include "zmq.hpp"
#include "ZmqContext.h"

class ZmqTimerImpl;

class ZmqTimer : public QObject
{
    Q_OBJECT
public:
    ZmqTimer(ZmqContext *context, int socket_type);

    ~ZmqTimer();

signals:
    void startTimer(int interval, const char*addr);

private:
    QThread* thread;
    ZmqTimerImpl *timer;
};

class ZmqTimerImpl : public QObject
{
    Q_OBJECT
public:
    ZmqTimerImpl(ZmqContext *context, int socket_type);

public slots:
    void startTimerSlot(int interval, const char*addr);

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    std::map<int, zmq::socket_t *> sockets;
    ZmqContext *context;
    int socket_type;

};


#endif // ZMQTIMER_H
