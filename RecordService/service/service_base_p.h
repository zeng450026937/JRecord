#ifndef SERVICE_BASE_P_H
#define SERVICE_BASE_P_H

#include "service/service_base.h"

class ServiceBase;
class TransportThread;
class ProcessThread;
class MessageQueue;
class QThread;
class QWebSocket;

class ServiceBasePrivate
{
    Q_DISABLE_COPY(ServiceBasePrivate)
    Q_DECLARE_PUBLIC(ServiceBase)
public:
    ServiceBasePrivate(ServiceBase *q);
    ~ServiceBasePrivate();

    ServiceBase *q_ptr;

    QThread *main_thread;
    QThread *socket_thread;
    QWebSocket *socket;
    TransportThread *transport_thread;
    ProcessThread *process_thread;
    MessageQueue *transport_queue;
    MessageQueue *process_queue;

    bool active;
    ServiceBase::Status status;
    QString errorString;
    QUrl url;
    QString userId;
    QString userGroup;
    QString userName;
    QString deviceType;
};

#endif // SERVICE_BASE_P_H
