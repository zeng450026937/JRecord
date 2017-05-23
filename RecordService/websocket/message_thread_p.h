#ifndef MESSAGE_THREAD_P_H
#define MESSAGE_THREAD_P_H

#include <QObject>

class MessageThread;
class MessageSocket;

class MessageThreadPrivate
{
    Q_DECLARE_PUBLIC(MessageThread)
public:
    MessageThreadPrivate(MessageThread *q);

    MessageThread *q_ptr;
    MessageSocket *socket;
};

#endif // MESSAGE_THREAD_P_H
