#include "message_queue.h"
#include "message_queue_p.h"

MessageQueue::MessageQueue(QObject *parent) :
    QObject(parent),
    d_ptr(new MessageQueuePrivate(this))
{

}

MessageQueue::~MessageQueue()
{
    this->setAbort(true);
    this->flush();
}
void MessageQueue::push(QSharedPointer<MessagePacket> t)
{
    Q_D(MessageQueue);
    QMutexLocker locker(&d->mutex);

    if(d->abort)
        return;

    d->queue.push_back(t);
    d->cond.wakeAll();

    Q_EMIT sizeChanged(d->queue.size());
}
QSharedPointer<MessagePacket> MessageQueue::pop(bool block)
{
    Q_D(MessageQueue);
    QMutexLocker locker(&d->mutex);

    QSharedPointer<MessagePacket> t;

    for(;;){
        if(d->abort)
            break;

        if(!d->queue.isEmpty()){
            t = d->queue.front();
            d->queue.pop_front();
            break;
        }
        else if(!block){
            break;
        }
        else{
            d->cond.wait(&d->mutex);
        }
    }

    return t;
}
void MessageQueue::flush()
{
    Q_D(MessageQueue);
    QMutexLocker locker(&d->mutex);
    d->queue.clear();
}

bool MessageQueue::abort()
{
    QMutexLocker locker(&d_func()->mutex);
    return d_func()->abort;
}

bool MessageQueue::empty()
{
    QMutexLocker locker(&d_func()->mutex);
    return d_func()->queue.isEmpty();
}

int MessageQueue::size()
{
    QMutexLocker locker(&d_func()->mutex);
    return d_func()->queue.size();
}

void MessageQueue::setAbort(bool abort)
{
    Q_D(MessageQueue);
    QMutexLocker locker(&d_func()->mutex);

    if(abort != d->abort){
        d->abort = abort;
        Q_EMIT abortChanged(d->abort);
    }
}

MessageQueue::MessageQueue(MessageQueuePrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}
