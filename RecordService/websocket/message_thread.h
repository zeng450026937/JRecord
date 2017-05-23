#ifndef MESSAGE_THREAD_H
#define MESSAGE_THREAD_H

#include <QThread>

class MessageSocket;
class MessageThreadPrivate;

class MessageThread : public QThread
{
    Q_OBJECT
    Q_DISABLE_COPY(MessageThread)
    Q_DECLARE_PRIVATE(MessageThread)
public:
    explicit MessageThread(QObject *parent = 0);

    void setMessageSocket(MessageSocket *socket);
    MessageSocket *messageSocket();

protected:
    MessageThread(MessageThreadPrivate *d, QObject *parent = 0);
    QScopedPointer<MessageThreadPrivate> d_ptr;
};

#endif // MESSAGE_THREAD_H
