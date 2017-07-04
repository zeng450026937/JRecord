#ifndef TASK_BACKEND_P_H
#define TASK_BACKEND_P_H

#include <QObject>

class TaskBackend;
class TaskReply;

class TaskBackendPrivate {
  Q_DISABLE_COPY(TaskBackendPrivate)
  Q_DECLARE_PUBLIC(TaskBackend)
 public:
  TaskBackendPrivate(TaskBackend *q);

  TaskBackend *q_ptr;
  TaskReply *reply;
};

#endif  // TASK_BACKEND_P_H
