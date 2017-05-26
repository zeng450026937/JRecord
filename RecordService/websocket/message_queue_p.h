#ifndef MESSAGE_QUEUE_P_H
#define MESSAGE_QUEUE_P_H

#include <QObject>
#include <QList>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include "message_packet.h"

class MessageQueue;

class MessageQueuePrivate
{
    Q_DISABLE_COPY(MessageQueuePrivate)
    Q_DECLARE_PUBLIC(MessageQueue)
public:
    MessageQueuePrivate(MessageQueue *q);

    MessageQueue *q_ptr;

    bool abort;
    QList<QSharedPointer<MessagePacket>> queue;
    QMutex mutex;
    QWaitCondition cond;
};

#endif // MESSAGE_QUEUE_P_H
