#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <QList>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QSharedPointer>

#include "message_packet.h"

class MessageQueue {
public:
    MessageQueue();
    ~MessageQueue();

    void push(QSharedPointer<MessagePacket> t);

    QSharedPointer<MessagePacket> pop(bool block = true);

    void flush();

    bool isEmpty();

    int size();

    void setAbort(bool abort = true);
    bool isAbort();

private:
    bool abort_;
    QList<QSharedPointer<MessagePacket>> queue_;
    QMutex mutex_;
    QWaitCondition cond_;
};

#endif // MESSAGE_QUEUE_H
