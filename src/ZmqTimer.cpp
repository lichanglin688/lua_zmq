#include "ZmqTimer.h"
#include <QTimerEvent>
#include "myprintf.h"

ZmqTimer::ZmqTimer(ZmqContext *context, int socket_type)
{
    thread = new QThread();
    timer = new ZmqTimerImpl(context, socket_type);
    timer->moveToThread(thread);
    connect(this, &ZmqTimer::startTimer, timer, &ZmqTimerImpl::startTimerSlot);
    thread->start();
}

ZmqTimer::~ZmqTimer()
{
    thread->quit();
    thread->wait();
    delete timer;
    delete thread;
}

ZmqTimerImpl::ZmqTimerImpl(ZmqContext *context, int socket_type)
    :context(context),
    socket_type(socket_type)
{

}

void ZmqTimerImpl::startTimerSlot(int interval, const char*addr)
{
    int timerId = startTimer(interval);

    zmq::socket_t * socket = new zmq::socket_t(*(context->getContext()), socket_type);
    try
    {
        socket->bind(addr);
        sockets[timerId] = socket;
    }
    catch(zmq::error_t &e)
    {
        Printf("%s", e.what());
        delete socket;
    }
}

void ZmqTimerImpl::timerEvent(QTimerEvent *event)
{
    auto found = sockets.find(event->timerId());
    if(found != sockets.end())
    {
        try
        {
            found->second->send(zmq::message_t(""), zmq::send_flags::none);
        }
        catch(zmq::error_t &e)
        {
            Printf("%s", e.what());
        }
    }
}
