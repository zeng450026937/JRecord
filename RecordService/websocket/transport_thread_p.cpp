#include "transport_thread_p.h"

TransportThreadPrivate::TransportThreadPrivate(TransportThread *q) :
    MessageThreadPrivate(q),
    queue(Q_NULLPTR)
{

}
