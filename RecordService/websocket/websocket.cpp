#include "websocket.h"
#include "websocket_p.h"
#include <QWebSocket>

WebSocket::WebSocket(QObject *parent) :
    QObject(parent),
    d_ptr(new WebSocketPrivate(this))
{

}

QString WebSocket::url() const
{
    return d_func()->url_;
}
void WebSocket::setUrl(QString url)
{
    Q_D(WebSocket);
    if(url != d->url_){
        d->url_ = url;
        Q_EMIT urlChanged(d->url_);
    }
}
void WebSocket::setStatus(Status status)
{
    Q_D(WebSocket);
    if(status != d->status_){
        d->status_ = status;
        Q_EMIT statusChanged(d->status_);
    }
}

void WebSocket::socketConnect()
{
    Q_D(WebSocket);
    d->socket_->open(d->url_);
    this->setStatus(Connecting);
}
void WebSocket::socketDisconnect()
{
    Q_D(WebSocket);
    d->socket_->close();
    this->setStatus(Closing);
}
