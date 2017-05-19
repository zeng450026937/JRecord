#include "websocket.h"
#include "websocket_p.h"
#include <QWebSocket>

WebSocket::WebSocket(QObject *parent) :
    QObject(parent),
    d_ptr(new WebSocketPrivate(this))
{

}

WebSocket::WebSocket(WebSocketPrivate* d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}

QString WebSocket::url() const
{
    return d_func()->url;
}
void WebSocket::setUrl(QString url)
{
    Q_D(WebSocket);
    if(url != d->url){
        d->url = url;
        Q_EMIT urlChanged(d->url);
    }
}
void WebSocket::setStatus(Status status)
{
    Q_D(WebSocket);
    if(status != d->status){
        d->status = status;
        Q_EMIT statusChanged(d->status);
    }
}

void WebSocket::socketConnect()
{
    Q_D(WebSocket);
    d->socket->open(d->url);
    this->setStatus(Connecting);
}
void WebSocket::socketDisconnect()
{
    Q_D(WebSocket);
    d->socket->close();
    this->setStatus(Closing);
}
