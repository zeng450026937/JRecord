#include "message_queue_p.h"

MessageQueuePrivate::MessageQueuePrivate(MessageQueue *q) :
    q_ptr(q),
    active(false)
{

}
