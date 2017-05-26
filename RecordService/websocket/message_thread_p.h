#ifndef MESSAGE_THREAD_P_H
#define MESSAGE_THREAD_P_H

#include <QObject>

class MessageThread;
class MessageQueue;
class QWebSocket;

class MessageThreadPrivate
{
    Q_DISABLE_COPY(MessageThreadPrivate)
    Q_DECLARE_PUBLIC(MessageThread)
public:
    MessageThreadPrivate(MessageThread *q);

    MessageThread *q_ptr;
    MessageQueue *queue;
    QWebSocket *socket;
};

#endif // MESSAGE_THREAD_P_H
