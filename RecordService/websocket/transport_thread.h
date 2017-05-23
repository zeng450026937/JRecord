#ifndef TRANSPORT_THREAD_H
#define TRANSPORT_THREAD_H

#include "message_thread.h"

class MessagePacket;
class MessageQueue;
class TransportThreadPrivate;

class TransportThread : public MessageThread
{
    Q_OBJECT
    Q_DISABLE_COPY(TransportThread)
    Q_DECLARE_PRIVATE(TransportThread)
public:
    explicit TransportThread(QObject *parent = 0);
    ~TransportThread();

    void setQueue(MessageQueue *queue);
    MessageQueue *queue();

Q_SIGNALS:
    void transportStarted();
    void transportStopped();

    void messageTransported(const QString &message);
    void messageTransported(const QByteArray &message);

public Q_SLOTS:
    //send message to server
    void pushMessage(MessagePacket *message);

protected:
    void run() override;
};

#endif // TRANSPORT_THREAD_H
