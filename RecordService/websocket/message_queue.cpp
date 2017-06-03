#include "message_queue.h"
#include "message_queue_p.h"

MessageQueue::MessageQueue(QObject *parent) :
    QObject(parent),
    d_ptr(new MessageQueuePrivate(this))
{

}

MessageQueue::~MessageQueue()
{
    this->setActive(false);
    this->flush();
}
void MessageQueue::push(QSharedPointer<MessagePacket> t)
{
    Q_D(MessageQueue);
    QMutexLocker locker(&d->mutex);

    if(!d->active)
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
        if(!d->active)
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

bool MessageQueue::active()
{
    QMutexLocker locker(&d_func()->mutex);
    return d_func()->active;
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

void MessageQueue::setActive(bool active)
{
    Q_D(MessageQueue);
    QMutexLocker locker(&d_func()->mutex);

    if(active != d->active){
        d->active = active;
        d->cond.wakeAll();
        Q_EMIT activeChanged(d->active);
    }
}

MessageQueue::MessageQueue(MessageQueuePrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}
