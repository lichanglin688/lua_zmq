#include "ZmqMonitor.h"
#include "myprintf.h"
#include "ZmqContext.h"

ZmqMonitor::ZmqMonitor()
    :monitor_socket(nullptr)
{

}

ZmqMonitor::~ZmqMonitor()
{
    delete monitor_socket;
    monitor_socket = nullptr;
}

ZmqSocket *ZmqMonitor::init(ZmqSocket *socket, const char *address, int events)
{
    int rc = zmq_socket_monitor(socket->getSocket()->handle(), address, events);
    if (rc != 0)
    {
        Printf("%s", zmq_strerror(zmq_errno()));
        return nullptr;
    }

    monitor_socket = new ZmqSocket(socket->getContext(), ZMQ_PAIR);
    monitor_socket->connect(address);

    return monitor_socket;
}

void ZmqMonitor::recv(lua_State *L)
{
    zmq::socket_t* socket =  monitor_socket->getSocket();

    zmq::message_t eventMsg;
    int rc = zmq_msg_recv(eventMsg.handle(), socket->handle(), 0);
    if (rc == -1 && zmq_errno() == ETERM)
    {
        lua_pushnil(L);
        lua_pushnil(L);
        lua_pushnil(L);
        return;
    }

    const char *data = static_cast<const char *>(eventMsg.data());
    zmq_event_t msgEvent;
    memcpy(&msgEvent.event, data, sizeof(uint16_t));
    data += sizeof(uint16_t);
    memcpy(&msgEvent.value, data, sizeof(int32_t));
    zmq_event_t *event = &msgEvent;

    zmq::message_t addrMsg;
    rc = zmq_msg_recv(addrMsg.handle(), socket->handle(), 0);
    if (rc == -1 && zmq_errno() == ETERM) {
        lua_pushnil(L);
        lua_pushnil(L);
        lua_pushnil(L);
        return;
    }
    lua_pushinteger(L, event->event);
    lua_pushinteger(L, event->value);
    lua_pushlstring(L, addrMsg.data<char>(), addrMsg.size());
}
