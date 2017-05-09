#include "websocket_p.h"
#include <QWebSocket>
#include "message_queue.h"
#include "message_processor.h"

WebSocketPrivate::WebSocketPrivate(WebSocket* q_p, QObject *parent):
    QObject(parent),
    q_ptr(q_p),
    socket(new QWebSocket),
    queue_(new MessageQueue)
{
    qRegisterMetaType<QByteArray>();

    connect(socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(socket,SIGNAL(textMessageReceived(QString)),this,SLOT(onTextMessageReceived(QString)));
    connect(socket,SIGNAL(binaryMessageReceived(QByteArray)),this,SLOT(onBinaryMessageReceived(QByteArray&)));

    processor_ = new MessageProcessor(queue_);
    processor_->start();
}

WebSocketPrivate::~WebSocketPrivate()
{
    if(status == WebSocket::Open)
        socket->close();

    delete socket;

    queue_->setAbort(true);
    queue_->flush();

    processor_->quit();
    processor_->wait(3000);
    processor_->terminate();

    delete processor_;

    delete queue_;
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
    QSharedPointer<MessagePacket> msg(new TextMessage(message));
    queue_->push(msg);
}
void WebSocketPrivate::onBinaryMessageReceived(QByteArray &message)
{
    QSharedPointer<MessagePacket> msg(new BinaryMessage(message));
    queue_->push(msg);
}
