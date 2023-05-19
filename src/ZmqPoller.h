#ifndef ZMQPOLLER_H
#define ZMQPOLLER_H

#include "ZmqSocket.h"
#include <map>

class ZmqPoller
{
public:
    ZmqPoller();
    ~ZmqPoller();

    void add(ZmqSocket* socket, short event = ZMQ_POLLIN);

    int poll(long timeout = -1);

    bool has_in(ZmqSocket* socket);

    bool has_out(ZmqSocket* socket);

    bool has_error(ZmqSocket* socket);

private:
    std::vector<zmq_pollitem_t> items;
    std::map<ZmqSocket*, std::size_t> indexs;
};

#endif // ZMQPOLLER_H
