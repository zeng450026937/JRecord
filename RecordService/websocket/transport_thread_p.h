#ifndef TRANSPORT_THREAD_P_H
#define TRANSPORT_THREAD_P_H

#include "message_thread_p.h"
#include "transport_thread.h"

class MessageQueue;
class TransportThread;

class TransportThreadPrivate : public MessageThreadPrivate
{
    Q_DISABLE_COPY(TransportThreadPrivate)
    Q_DECLARE_PUBLIC(TransportThread)
public:
    TransportThreadPrivate(TransportThread* q);

    QMetaObject::Connection textConnection;
    QMetaObject::Connection binaryConnection;
};

#endif // TRANSPORT_THREAD_P_H
