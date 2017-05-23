#include "message_socket.h"
#include "message_socket_p.h"
#include "process_thread.h"
#include "transport_thread.h"
#include <QWebSocket>
#include <QDebug>

static MessageSocket* gMessageSocket = Q_NULLPTR;

MessageSocket::MessageSocket(QObject *parent) :
    QObject(parent),
    d_ptr(new MessageSocketPrivate(this))
{

}

MessageSocket::MessageSocket(MessageSocketPrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

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

MessageSocket *MessageSocket::CreateInstance()
{
    if(gMessageSocket == Q_NULLPTR){
        gMessageSocket = new MessageSocket();
        if(gMessageSocket)
            gMessageSocket->AddRef();
        else
            qDebug()<<QStringLiteral("create message socket failed.");
    }
    else{
        gMessageSocket->AddRef();
    }
    return gMessageSocket;
}

bool MessageSocket::DeleteInstance(MessageSocket *instance)
{
    if(instance == NULL)
        return false;

    int ref = instance->Release();
    instance = NULL;

    if(ref != 0) {
        qDebug()<<QStringLiteral("Delete did not release the very last reference.");
    }

    return true;
}

int MessageSocket::AddRef()
{
    Q_D(MessageSocket);
    return ++d->ref;
}

int MessageSocket::Release()
{
    Q_D(MessageSocket);
    int new_ref = --d->ref;

    if (new_ref == 0) {
        delete this;
    }

    return new_ref;
}

QUrl MessageSocket::url() const
{
    return d_func()->url;
}

void MessageSocket::setUrl(const QUrl &url)
{
    Q_D(MessageSocket);
    if(url != d->url){
        d->url = url;
        Q_EMIT urlChanged(d->url);
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

