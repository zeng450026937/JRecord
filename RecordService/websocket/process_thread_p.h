#ifndef PROCESS_THREAD_P_H
#define PROCESS_THREAD_P_H

#include "message_thread_p.h"
#include "process_thread.h"
#include <QHash>

class ProcessThread;

class ProcessThreadPrivate : public MessageThreadPrivate
{
    Q_DISABLE_COPY(ProcessThreadPrivate)
    Q_DECLARE_PUBLIC(ProcessThread)
public:
    ProcessThreadPrivate(ProcessThread* q);

    QMetaObject::Connection textConnection;
    QMetaObject::Connection binaryConnection;
};

#endif // PROCESS_THREAD_P_H
