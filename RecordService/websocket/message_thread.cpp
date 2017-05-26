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
void MessageThread::setQueue(MessageQueue *queue)
{
    Q_D(MessageThread);
    d->queue = queue;
}

MessageQueue *MessageThread::queue()
{
    Q_D(MessageThread);
    return d->queue;
}
void MessageThread::setSocket(QWebSocket *socket)
{
    Q_D(MessageThread);
    d->socket = socket;
}

QWebSocket *MessageThread::socket()
{
    Q_D(MessageThread);
    return d->socket;
}
