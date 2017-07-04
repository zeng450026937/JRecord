#include "task_backend.h"
#include "task_backend_p.h"

TaskBackend::TaskBackend(QObject *parent)
    : QObject(parent), d_ptr(new TaskBackendPrivate(this)) {}

TaskBackend::TaskBackend(TaskBackendPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
