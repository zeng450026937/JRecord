#include "service_base_p.h"
#include "service/service_base.h"
#include "websocket/transport_thread.h"
#include "websocket/process_thread.h"
#include "websocket/message_queue.h"
#include "websocket/message_socket.h"
#include <QThread>
#include <QUuid>

ServiceBasePrivate::ServiceBasePrivate(ServiceBase *q) :
    q_ptr(q),
    active(false),
    main_thread(new QThread),
    socket_thread(new QThread),
    socket(new MessageSocket),
    transport_thread(new TransportThread),
    process_thread(new ProcessThread),
    transport_queue(new MessageQueue),
    process_queue(new MessageQueue)
{   
    deviceUuid = QUuid::createUuid().toString();
    deviceUuid.replace(QStringLiteral("-"),"");
    deviceUuid.replace(QStringLiteral("{"),"");
    deviceUuid.replace(QStringLiteral("}"),"");

    transport_thread->setSocket(socket);
    process_thread->setSocket(socket);

    transport_queue->moveToThread(main_thread);
    process_queue->moveToThread(main_thread);

    transport_thread->moveToThread(main_thread);
    process_thread->moveToThread(main_thread);

    socket->moveToThread(socket_thread);

    transport_thread->setQueue(transport_queue);
    process_thread->setQueue(process_queue);

    main_thread->start();
    socket_thread->start();

    QObject::connect(socket, &MessageSocket::connected, q_ptr,
                     [this](){
        Q_Q(ServiceBase);
        status = ServiceBase::Open;
        active = true;
        Q_EMIT q->activeChanged(active);
        Q_EMIT q->statusChanged(status);
    });
    QObject::connect(socket, &MessageSocket::disconnected, q_ptr,
                     [this](){
        Q_Q(ServiceBase);
        status = ServiceBase::Closed;
        active = false;
        Q_EMIT q->activeChanged(active);
        Q_EMIT q->statusChanged(status);
    });
    QObject::connect(socket, &MessageSocket::errorChanged, q_ptr,
                     [this](const QString error){
        Q_Q(ServiceBase);
        errorString = error;
        status = ServiceBase::Error;
        active = false;
        Q_EMIT q->activeChanged(active);
        Q_EMIT q->statusChanged(status);
    });

    QObject::connect(q_ptr, &ServiceBase::activeChanged,
                     socket, &MessageSocket::setActive);

    QObject::connect(q_ptr, &ServiceBase::activeChanged,
                     process_queue, &MessageQueue::setActive);
    QObject::connect(q_ptr, &ServiceBase::activeChanged,
                     transport_queue, &MessageQueue::setActive);

    QObject::connect(transport_queue, &MessageQueue::activeChanged,
                     transport_thread, &TransportThread::setActive);
    QObject::connect(process_queue, &MessageQueue::activeChanged,
                     process_thread, &ProcessThread::setActive);
}

ServiceBasePrivate::~ServiceBasePrivate()
{
    main_thread->quit();
    main_thread->wait(3000);
    socket_thread->quit();
    socket_thread->wait(3000);

    main_thread->deleteLater();
    socket_thread->deleteLater();

    transport_queue->deleteLater();
    process_queue->deleteLater();
    transport_thread->deleteLater();
    process_thread->deleteLater();
    socket->deleteLater();
}


