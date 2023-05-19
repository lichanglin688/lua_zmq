#include "ZmqSocket.h"
#include <QDebug>
#include "zmq_addon.hpp"
#include "myprintf.h"

ZmqSocket::ZmqSocket(ZmqContext *context, int socket_type)
    :ctx(context)
{
    socket = new zmq::socket_t(*(context->getContext()), socket_type);
    item = {socket->handle(), 0, ZMQ_POLLIN, 0};
}

ZmqSocket::~ZmqSocket()
{
    delete socket;
}

bool ZmqSocket::bind(const char *addr)
{
    try
    {
        socket->bind(addr);
        return true;
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        return false;
    }
}

bool ZmqSocket::connect(const char *addr)
{
    try
    {
        socket->connect(addr);
        return true;
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        return false;
    }
}

void ZmqSocket::getSockoptString(lua_State* L, int option)
{
    try
    {
        char value[255]{};
        size_t size = 255;
        socket->getsockopt(option, value, &size);
        if(size == 0){
            lua_pushnil(L);
            return;
        }
        lua_pushlstring(L, value, size);
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        lua_pushnil(L);
    }
}

int ZmqSocket::getSockoptInt(int option)
{
    try
    {
        return socket->getsockopt<int>(option);
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        return -1;
    }
}

bool ZmqSocket::setSockoptInt(int option, int value)
{
    try
    {
        socket->setsockopt(option, value);
        return true;
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        return false;
    }
}

bool ZmqSocket::setSockoptString(int option, const char *value)
{
    try
    {
        socket->setsockopt(option, value, strlen(value));
        return true;
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        return false;
    }
}

bool ZmqSocket::send(const char *msg, int send_flags)
{
    try
    {
        socket->send(msg, strlen(msg), send_flags);
        return true;
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        return false;
    }
}

bool ZmqSocket::sendBySize(const char *msg, size_t size, int send_flags)
{
    try
    {
        socket->send(zmq::message_t(msg, size), send_flags);
        return true;
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        return false;
    }
}


void ZmqSocket::recv(lua_State *L, int recv_flags)
{
    try
    {
        zmq::message_t msg;
        socket->recv(&msg, recv_flags);
        lua_pushlstring(L, msg.data<char>(), msg.size());
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        lua_pushnil(L);
    }
}


void ZmqSocket::recvAndWait(lua_State *L, long timeout, int recv_flags)
{
    try
    {
        if(zmq::poll(&item, 1, timeout) > 0 && item.revents & ZMQ_POLLIN)
        {
            zmq::message_t msg;
            socket->recv(&msg, recv_flags);
            lua_pushlstring(L, msg.data<char>(), msg.size());
        }
        else
        {
            lua_pushnil(L);
        }
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        lua_pushnil(L);
    }
}

void ZmqSocket::recvMultiMessage(lua_State *L, int recv_flags)
{
    try
    {
        zmq::multipart_t msgs;
        msgs.recv(*socket, recv_flags);
        lua_createtable(L, msgs.size(), 0);
        for (int i = 0; i < msgs.size(); ++i)
        {
            const zmq::message_t &msg = msgs.at(i);
            lua_pushlstring(L, msg.data<char>(), msg.size());
            lua_rawseti(L, -2, i+1);
        }
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        lua_pushnil(L);
    }
}

void ZmqSocket::recvMultiMessageAndWait(lua_State *L, long timeout, int recv_flags)
{
    try
    {
        if(zmq::poll(&item, 1, timeout) > 0 && item.revents & ZMQ_POLLIN)
        {
            zmq::multipart_t msgs;
            msgs.recv(*socket, recv_flags);
            lua_createtable(L, msgs.size(), 0);
            for (int i = 0; i < msgs.size(); ++i)
            {
                const zmq::message_t &msg = msgs.at(i);
                lua_pushlstring(L, msg.data<char>(), msg.size());
                lua_rawseti(L, -2, i+1);
            }
        }
        else
        {
            lua_pushnil(L);
        }
    }
    catch(zmq::error_t &e)
    {
        Printf("%s",e.what());
        lua_pushnil(L);
    }
}

zmq::socket_t *ZmqSocket::getSocket() const
{
    return socket;
}

ZmqContext *ZmqSocket::getContext() const
{
    return ctx;
}
