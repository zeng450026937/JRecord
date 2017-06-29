#ifndef TASK_P_H
#define TASK_P_H

#include "task.h"

class TaskPrivate {
 public:
  Q_DISABLE_COPY(TaskPrivate)
  Q_DECLARE_PUBLIC(Task)

  TaskPrivate(Task *q);

  Task *q_ptr;
  int action;
  QJsonObject data;
  QJsonObject result;
  Task::Status status;
};

#endif  // TASK_P_H
