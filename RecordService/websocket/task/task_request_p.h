#ifndef TASK_REQUEST_P_H
#define TASK_REQUEST_P_H

#include <QObject>
#include "task_request.h"

class TaskRequestPrivate {
  Q_DISABLE_COPY(TaskRequestPrivate)
  Q_DECLARE_PUBLIC(TaskRequest)
 public:
  TaskRequestPrivate(TaskRequest *q);

  TaskRequest *q_ptr;
  TaskRequest::Type type;
  QJsonValue data;
};

#endif  // TASK_REQUEST_P_H
