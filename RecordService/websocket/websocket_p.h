#ifndef WEBSOCKET_P_H
#define WEBSOCKET_P_H

#include <QObject>
#include "websocket.h"

class QWebSocket;
class MessageParser;

class WebSocketPrivate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(WebSocketPrivate)
    Q_DECLARE_PUBLIC(WebSocket)

public:
    explicit WebSocketPrivate(WebSocket* q_p, QObject *parent = Q_NULLPTR);
    ~WebSocketPrivate();

    QString url_;
    WebSocket::Status status_;
    QWebSocket* socket_;

private Q_SLOTS:
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(QString message);
    void onBinaryMessageReceived(QByteArray &message);

private:
    WebSocket* const q_ptr;
    MessageParser* message_parser_;
};

#endif // WEBSOCKET_P_H
