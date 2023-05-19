#include <QUuid>
#include "ZmqContext.h"
#include <QMutexLocker>

ZmqContext::ZmqContext()
{
    context = new zmq::context_t();
}


ZmqContext::~ZmqContext()
{
    delete context;
}


zmq::context_t *ZmqContext::getContext() const
{
    return context;
}

void ZmqContext::setctxopt(int option, int optval)
{
    context->setctxopt(option, optval);
}

std::string ZmqContext::createUuid()
{
    QUuid uuid = QUuid::createUuid();
    return uuid.toString(QUuid::Id128).toStdString();
}
