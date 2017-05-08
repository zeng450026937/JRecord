#include "websocket_p.h"
#include <QWebSocket>
#include "message_parser.h"

WebSocketPrivate::WebSocketPrivate(WebSocket* q_p, QObject *parent):
    QObject(parent),
    q_ptr(q_p),
    socket_(new QWebSocket),
    message_parser_(new MessageParser)
{
    //Q_Q(WebSocket);
    qRegisterMetaType<QByteArray>();
    connect(socket_,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(socket_,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(socket_,SIGNAL(textMessageReceived(QString)),this,SLOT(onTextMessageReceived(QString)));
    connect(socket_,SIGNAL(binaryMessageReceived(QByteArray)),this,SLOT(onBinaryMessageReceived(QByteArray&)));
}

WebSocketPrivate::~WebSocketPrivate()
{
    delete socket_;
    delete message_parser_;
}

void WebSocketPrivate::onConnected()
{
    Q_Q(WebSocket);
    q->setStatus(WebSocket::Open);
}
void WebSocketPrivate::onDisconnected()
{
    Q_Q(WebSocket);
    q->setStatus(WebSocket::Closed);
}
void WebSocketPrivate::onTextMessageReceived(QString message)
{
    message_parser_->parseMessage(message);
}
void WebSocketPrivate::onBinaryMessageReceived(QByteArray &message)
{
    message_parser_->parseBinary(message);
}
