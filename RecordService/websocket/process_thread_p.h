#ifndef PROCESS_THREAD_P_H
#define PROCESS_THREAD_P_H

#include "message_thread_p.h"
#include "process_thread.h"

class MessageQueue;
class ProcessThread;

class ProcessThreadPrivate : public MessageThreadPrivate
{
    Q_DECLARE_PUBLIC(ProcessThread)
public:
    ProcessThreadPrivate(ProcessThread* q);

    MessageQueue* queue;
};

#endif // PROCESS_THREAD_P_H
