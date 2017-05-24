#include "message_queue.h"

MessageQueue::MessageQueue():
    abort_(false)
{

}
MessageQueue::~MessageQueue()
{
    this->setAbort(true);
    this->flush();
}
void MessageQueue::push(QSharedPointer<MessagePacket> t)
{
    QMutexLocker locker(&mutex_);

    if(abort_)
        return;

    queue_.push_back(t);
    cond_.wakeAll();
}
QSharedPointer<MessagePacket> MessageQueue::pop(bool block)
{
    QMutexLocker locker(&mutex_);

    QSharedPointer<MessagePacket> t;

    for(;;){
        if(abort_)
            break;

        if(!queue_.isEmpty()){
            t = queue_.front();
            queue_.pop_front();
            break;
        }
        else if(!block){
            break;
        }
        else{
            cond_.wait(&mutex_);
        }
    }

    return t;
}
void MessageQueue::flush()
{
    QMutexLocker locker(&mutex_);
    queue_.clear();
}
bool MessageQueue::isEmpty()
{
    QMutexLocker locker(&mutex_);
    return queue_.isEmpty();
}

int MessageQueue::size()
{
    QMutexLocker locker(&mutex_);
    return queue_.size();
}

void MessageQueue::setAbort(bool abort)
{
    QMutexLocker locker(&mutex_);
    abort_ = abort;
    cond_.wakeAll();
}
bool MessageQueue::isAbort()
{
    QMutexLocker locker(&mutex_);
    return abort_;
}
