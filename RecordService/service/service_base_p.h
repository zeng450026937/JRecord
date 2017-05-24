#ifndef SERVICE_BASE_P_H
#define SERVICE_BASE_P_H

#include <QObject>

class ServiceBase;
class MessageSocket;
class TransportThread;
class ProcessThread;
class MessageQueue;

class ServiceBasePrivate
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(ServiceBase)
public:
    ServiceBasePrivate(ServiceBase *q);
    ~ServiceBasePrivate();

    ServiceBase *q_ptr;

    qint32 ref;
    MessageSocket *socket;
    TransportThread *transport_thread;
    ProcessThread *process_thread;
    MessageQueue *transport_queue;
    MessageQueue *process_queue;
};

#endif // SERVICE_BASE_P_H
