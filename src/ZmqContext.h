#ifndef ZMQCONTEXT_H
#define ZMQCONTEXT_H
#include "zmq.hpp"
#include "Singleton.h"
#include <string>

class ZmqContext : public Singleton<ZmqContext>
{
public:
    ZmqContext();

    ~ZmqContext();

    zmq::context_t *getContext() const;

    void setctxopt(int option, int optval);

    static std::string createUuid();

private:
    zmq::context_t *context;
};

#endif // ZMQCONTEXT_H
