#include "ZmqPoller.h"
#include <QDebug>
#include "myprintf.h"

ZmqPoller::ZmqPoller()
{

}

ZmqPoller::~ZmqPoller()
{
    items.clear();
    indexs.clear();
}

void ZmqPoller::add(ZmqSocket *socket, short event)
{
    indexs[socket] = items.size();
    zmq_pollitem_t item{socket->getSocket()->handle(), 0, event, 0};
    items.emplace_back(item);
}

int ZmqPoller::poll(long timeout)
{
    try
    {
        return zmq::poll(items, timeout);
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        return 0;
    }
}

bool ZmqPoller::has_in(ZmqSocket *socket)
{
    auto found = indexs.find(socket);
    if(found == indexs.end())
    {
        return false;
    }
    return items[found->second].revents & ZMQ_POLLIN;
}

bool ZmqPoller::has_out(ZmqSocket *socket)
{
    auto found = indexs.find(socket);
    if(found == indexs.end())
    {
        return false;
    }
    return items[found->second].revents & ZMQ_POLLOUT;
}

bool ZmqPoller::has_error(ZmqSocket *socket)
{
    auto found = indexs.find(socket);
    if(found == indexs.end())
    {
        return false;
    }
    return items[found->second].revents & ZMQ_POLLERR;
}
