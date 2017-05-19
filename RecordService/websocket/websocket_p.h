#ifndef WEBSOCKET_P_H
#define WEBSOCKET_P_H

#include <QObject>
#include "websocket.h"

class QWebSocket;
class MessageQueue;
class MessageProcessor;

class WebSocketPrivate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(WebSocketPrivate)
    Q_DECLARE_PUBLIC(WebSocket)

public:
    explicit WebSocketPrivate(WebSocket* q, QObject *parent = Q_NULLPTR);
    ~WebSocketPrivate();

    WebSocket* const q_ptr;

    QString url;
    WebSocket::Status status;
    QWebSocket* socket;
    MessageQueue* queue_;
    MessageProcessor* processor_;

private Q_SLOTS:
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(QString message);
    void onBinaryMessageReceived(QByteArray &message);

};

#endif // WEBSOCKET_P_H
