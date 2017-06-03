#include "message_thread_p.h"

MessageThreadPrivate::MessageThreadPrivate(MessageThread *q) :
    q_ptr(q),
    socket(Q_NULLPTR),
    queue(Q_NULLPTR),
    active(false)
{

}
