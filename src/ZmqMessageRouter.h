#ifndef ZMQMESSAGEROUTER_H
#define ZMQMESSAGEROUTER_H
#include "ZmqContext.h"
#include "zmq.hpp"

class ZmqMessageRouter
{
public:
    ZmqMessageRouter(ZmqContext *context);

    bool bind(const char*addr);

    void start();

private:
    zmq::socket_t *socket;
};

#endif // ZMQMESSAGEROUTER_H
