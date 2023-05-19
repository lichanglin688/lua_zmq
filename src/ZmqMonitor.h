#ifndef ZMQMONITOR_H
#define ZMQMONITOR_H
#include "ZmqSocket.h"
#include "zmq.h"

class ZmqMonitor
{
public:
    ZmqMonitor();

    ~ZmqMonitor();

    ZmqSocket* init(ZmqSocket* socket, const char *address, int events = ZMQ_EVENT_ALL);

    void recv(lua_State *L);

private:
    ZmqSocket *monitor_socket;
};

#endif // ZMQMONITOR_H
