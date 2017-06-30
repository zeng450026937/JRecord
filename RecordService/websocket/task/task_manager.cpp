#include "task_manager.h"
#include "task_manager_p.h"

TaskManager::TaskManager(QObject *parent)
    : QObject(parent), d_ptr(new TaskManagerPrivate(this)) {}

void TaskManager::pushTask(Task *task) {
  Q_D(TaskManager);
  if (task) d->taskList.append(task);
}

TaskManager::TaskManager(TaskManagerPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
