#include "service_base_p.h"

ServiceBasePrivate::ServiceBasePrivate(ServiceBase *q) :
    q_ptr(q),
    ref(0),
    socket(Q_NULLPTR),
    transport_thread(Q_NULLPTR),
    process_thread(Q_NULLPTR),
    transport_queue(Q_NULLPTR),
    process_queue(Q_NULLPTR)
{

}

ServiceBasePrivate::~ServiceBasePrivate()
{

}
