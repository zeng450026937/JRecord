#ifndef TASK_MANAGER_P_H
#define TASK_MANAGER_P_H

#include <QObject>

class TaskManager;

class TaskManagerPrivate {
  Q_DISABLE_COPY(TaskManagerPrivate)
  Q_DECLARE_PUBLIC(TaskManager)
 public:
  TaskManagerPrivate(TaskManager *q);

  TaskManager *q_ptr;
};

#endif  // TASK_MANAGER_P_H
