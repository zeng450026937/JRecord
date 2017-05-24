#include "message_socket.h"
#include "message_socket_p.h"
#include "process_thread.h"
#include "transport_thread.h"
#include <QWebSocket>
#include <QDebug>

MessageSocket::MessageSocket(bool multithread, QObject *parent) :
    QObject(parent),
    d_ptr(new MessageSocketPrivate(this))
{
    Q_D(MessageSocket);
    if(multithread){
        d->event_thread = new QThread(this);
        this->moveToThread(d->event_thread);
        d->event_thread->start();
    }
}

MessageSocket::~MessageSocket()
{
    Q_D(MessageSocket);
    if(d->event_thread && d->event_thread->isRunning()){
        d->event_thread->quit();
        d->event_thread->wait(3000);
    }
}

MessageSocket::MessageSocket(MessageSocketPrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}

void MessageSocket::open(const QUrl &url)
{
    Q_D(MessageSocket);
    d->socket->open(url);
    d->status = Connecting;
    Q_EMIT statusChanged(d->status);
}

void MessageSocket::open(const QNetworkRequest &authorization)
{
    Q_D(MessageSocket);
    d->socket->open(authorization);
    d->status = Connecting;
    Q_EMIT statusChanged(d->status);
}

void MessageSocket::close()
{
    Q_D(MessageSocket);
    if(d->socket->isValid()){
        d->socket->close(QWebSocketProtocol::CloseCodeNormal, QStringLiteral("client closed"));
        d->status = Closing;
        Q_EMIT statusChanged(d->status);
    }
}

void MessageSocket::setTransportThread(TransportThread *transport)
{
    Q_D(MessageSocket);
    if(d->transport)
        d->transport->disconnect(d);
    d->transport = transport;
    connect(d->transport, SIGNAL(messageTransported(QString)),
            d, SLOT(sendTextMessage(QString)));
    connect(d->transport, SIGNAL(messageTransported(QByteArray)),
            d, SLOT(sendBinaryMessage(QByteArray)));
}

TransportThread *MessageSocket::transportThread() const
{
    return d_func()->transport;
}

void MessageSocket::setProcessThread(ProcessThread *process)
{
    Q_D(MessageSocket);
    d->process = process;
}

ProcessThread *MessageSocket::processThread() const
{
    return d_func()->process;
}

