#include "ZmqMessageRouter.h"
#include "zmq_addon.hpp"
#include "myprintf.h"

ZmqMessageRouter::ZmqMessageRouter(ZmqContext *context)
{
    socket = new zmq::socket_t(*(context->getContext()), zmq::socket_type::router);
    socket->setsockopt(ZMQ_SNDHWM, 5000);
    socket->setsockopt(ZMQ_RCVHWM, 5000);
}

bool ZmqMessageRouter::bind(const char *addr)
{
    try{
        socket->bind(addr);
        return true;
    }
    catch(zmq::error_t &e)
    {
        Printf("%s", e.what());
        return false;
    }
}

void ZmqMessageRouter::start()
{
    while(true)
    {
        zmq::multipart_t msgs;
        msgs.recv(*socket);
        if(msgs.size() < 3)
        {
            Printf("%s", "消息至少是三帧！！！");
            Printf("%s", msgs.str().data());
            continue;
        }

        zmq::multipart_t router_msg;
        //目标方router_id,如果该目标还未连接上，则消息会被丢弃
        router_msg.add(std::move(msgs.at(1)));
        //请求方router_id
        router_msg.add(std::move(msgs.at(0)));

        //消息内容
        for (int i = 2; i < msgs.size(); ++i)
        {
            router_msg.add(std::move(msgs.at(i)));
        }
        //当达到最大消息队列数量时，丢弃掉该消息
        router_msg.send(*socket);

    }
}
