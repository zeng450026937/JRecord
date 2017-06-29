#include "task_manager.h"
#include "task_manager_p.h"

TaskManager::TaskManager(QObject *parent)
    : QObject(parent), d_ptr(new TaskManagerPrivate(this)) {}

TaskManager::TaskManager(TaskManagerPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
