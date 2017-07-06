#ifndef TASK_REQUEST_P_H
#define TASK_REQUEST_P_H

#include "task_request.h"
#include "websocket/textmessage_p.h"

class TaskRequestPrivate : TextMessagePrivate {
  Q_DISABLE_COPY(TaskRequestPrivate)
  Q_DECLARE_PUBLIC(TaskRequest)
 public:
  TaskRequestPrivate(TaskRequest *q);
  TaskReply *reply;
};

#endif  // TASK_REQUEST_P_H
