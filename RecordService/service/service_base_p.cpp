#include "service_base_p.h"
#include "service/service_base.h"
#include "websocket/transport_thread.h"
#include "websocket/process_thread.h"
#include "websocket/message_queue.h"
#include <QThread>
#include <QWebSocket>

ServiceBasePrivate::ServiceBasePrivate(ServiceBase *q) :
    q_ptr(q),
    active(false),
    main_thread(new QThread),
    socket_thread(new QThread),
    socket(new QWebSocket),
    transport_thread(new TransportThread),
    process_thread(new ProcessThread),
    transport_queue(new MessageQueue),
    process_queue(new MessageQueue)
{
    //connect signal/slot
    qRegisterMetaType<QByteArray>();
    qRegisterMetaType<QNetworkRequest>();

    QObject::connect(socket, &QWebSocket::connected,
                     [this](){
        Q_Q(ServiceBase);
        status = ServiceBase::Open;
        active = true;
        Q_EMIT q->activeChanged(active);
        Q_EMIT q->statusChanged(status);
    });
    QObject::connect(socket, &QWebSocket::disconnected,
                     [this](){
        Q_Q(ServiceBase);
        status = ServiceBase::Closed;
        active = false;
        Q_EMIT q->activeChanged(active);
        Q_EMIT q->statusChanged(status);
    });
    QObject::connect(socket, static_cast<void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error),
                     [this](QAbstractSocket::SocketError error){
        Q_UNUSED(error);
        errorString = socket->errorString();
    });

    QObject::connect(q, SIGNAL(open(QUrl)),
                     socket, SLOT(open(QUrl)));
    QObject::connect(q, SIGNAL(open(QNetworkRequest)),
                     socket, SLOT(open(QNetworkRequest)));
    QObject::connect(q, SIGNAL(close()),
                     socket, SLOT(close(QWebSocketProtocol::CloseCode,QString)));

    QObject::connect(q, static_cast<void (ServiceBase::*)(const QUrl &url)>(&ServiceBase::open),
                     [this](const QUrl &url){
        Q_UNUSED(url);
        Q_Q(ServiceBase);
        status = ServiceBase::Connecting;
        Q_EMIT q->statusChanged(status);
    });
    QObject::connect(q, static_cast<void (ServiceBase::*)(const QNetworkRequest &request)>(&ServiceBase::open),
                     [=](const QNetworkRequest &request){
        Q_UNUSED(request);
        Q_Q(ServiceBase);
        status = ServiceBase::Connecting;
        Q_EMIT q->statusChanged(status);
    });

    QObject::connect(q, &ServiceBase::close,
                     [=](){
        Q_Q(ServiceBase);
        status = ServiceBase::Closing;
        Q_EMIT q->statusChanged(status);
    });


    transport_thread->setSocket(socket);
    process_thread->setSocket(socket);

    socket->moveToThread(socket_thread);

    transport_queue->moveToThread(main_thread);
    process_queue->moveToThread(main_thread);

    transport_thread->moveToThread(main_thread);
    process_thread->moveToThread(main_thread);
}

ServiceBasePrivate::~ServiceBasePrivate()
{
    Q_Q(ServiceBase);
    q->setActive(false);

    delete transport_queue;
    delete process_queue;
    delete transport_thread;
    delete process_thread;
    delete socket_thread;
    delete main_thread;
    delete socket;
}


