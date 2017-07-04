#include "task_backend_p.h"

TaskBackendPrivate::TaskBackendPrivate(TaskBackend *q)
    : q_ptr(q), reply(Q_NULLPTR) {}
