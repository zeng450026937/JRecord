#include "task_request_p.h"

TaskRequestPrivate::TaskRequestPrivate(TaskRequest *q)
    : q_ptr(q), type(TaskRequest::Unknown) {}
