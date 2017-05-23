#include "message_thread.h"
#include "message_thread_p.h"

MessageThread::MessageThread(QObject *parent) :
    QThread(parent),
    d_ptr(new MessageThreadPrivate(this))
{

}

MessageThread::MessageThread(MessageThreadPrivate *d, QObject *parent) :
    QThread(parent),
    d_ptr(d)
{

}

void MessageThread::setMessageSocket(MessageSocket *socket)
{
    Q_D(MessageThread);
    d->socket = socket;
}

MessageSocket *MessageThread::messageSocket()
{
    Q_D(MessageThread);
    return d->socket;
}
