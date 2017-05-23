#include "process_thread_p.h"

ProcessThreadPrivate::ProcessThreadPrivate(ProcessThread *q) :
    MessageThreadPrivate(q),
    queue(Q_NULLPTR)
{

}
