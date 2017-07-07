#include "task_request_p.h"

TaskRequestPrivate::TaskRequestPrivate(TaskRequest *q)
    : TextMessagePrivate(q), reply(Q_NULLPTR) {}
