#ifndef ZMQSOCKET_H
#define ZMQSOCKET_H

#include "zmq.hpp"
#include "ZmqContext.h"
#include <string>

extern "C"{
#include "lua.h"
#include "tolua++.h"
}

class ZmqSocket
{
public:
    ZmqSocket(ZmqContext *context, int socket_type);

    ~ZmqSocket();

    bool bind(const char* addr);

    bool connect(const char* addr);

    bool setSockoptInt(int option, int value);

    bool setSockoptString(int option, const char* value);

    void getSockoptString(lua_State* L, int option);

    int getSockoptInt(int option);

    bool send(const char* msg, int send_flags = 0);

    bool sendBySize(const char* msg, size_t size, int send_flags = 0);

    //lua_xxx中返回值设为1
    void recv(lua_State* L, int recv_flags = 0);

    //lua_xxx中返回值设为1
    void recvAndWait(lua_State* L, long timeout = -1, int recv_flags = 0);

    //lua_xxx中返回值设为1
    void recvMultiMessage(lua_State* L, int recv_flags = 0);

    //lua_xxx中返回值设为1
    void recvMultiMessageAndWait(lua_State* L, long timeout = -1, int recv_flags = 0);

public:
    zmq::socket_t *getSocket() const;

    ZmqContext *getContext() const;

private:
    ZmqContext *ctx;
    zmq::socket_t *socket;
    zmq::pollitem_t item;
};

#endif // ZMQSOCKET_H
