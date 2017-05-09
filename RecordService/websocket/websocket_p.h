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
    explicit WebSocketPrivate(WebSocket* q_p, QObject *parent = Q_NULLPTR);
    ~WebSocketPrivate();

    QString url;
    WebSocket::Status status;
    QWebSocket* socket;

private Q_SLOTS:
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(QString message);
    void onBinaryMessageReceived(QByteArray &message);

private:
    WebSocket* const q_ptr;
    MessageQueue* queue_;
    MessageProcessor* processor_;
};

#endif // WEBSOCKET_P_H
