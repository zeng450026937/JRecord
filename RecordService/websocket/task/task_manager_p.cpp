#include "task_manager_p.h"

TaskManagerPrivate::TaskManagerPrivate(TaskManager *q)
    : q_ptr(q), transportThread(Q_NULLPTR), processThread(Q_NULLPTR) {}
