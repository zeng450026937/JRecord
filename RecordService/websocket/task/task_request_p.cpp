#include "task_request_p.h"

TaskRequestPrivate::TaskRequestPrivate(TaskRequest *q)
    : q_ptr(q), reply(Q_NULLPTR), message(Q_NULLPTR) {}
