#ifndef MESSAGESOCKET_P_H
#define MESSAGESOCKET_P_H

#include "message_socket.h"
#include <QObject>
#include <QUrl>

class QThread;
class TransportThread;
class ProcessThread;
class MessageSocket;
class QWebSocket;

class MessageSocketPrivate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MessageSocketPrivate)
    Q_DECLARE_PUBLIC(MessageSocket)
public:
    MessageSocketPrivate(MessageSocket *q);
    ~MessageSocketPrivate();

    MessageSocket *q_ptr;
    QWebSocket *socket;
    QThread *event_thread;//event thread
    MessageSocket::Status status;
    TransportThread *transport;
    ProcessThread *process;

public Q_SLOTS:
    void onConnected();
    void onDisconnected();

    void sendTextMessage(const QString &message);
    void sendBinaryMessage(const QByteArray &message);
    void onTextMessageReceived(const QString &message);
    void onBinaryMessageReceived(const QByteArray &message);
};

#endif // MESSAGESOCKET_P_H
