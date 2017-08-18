#ifndef TASK_REQUEST_P_H
#define TASK_REQUEST_P_H

#include <QObject>

class TaskRequest;
class TaskReply;
class MessagePacket;

class TaskRequestPrivate {
  Q_DISABLE_COPY(TaskRequestPrivate)
  Q_DECLARE_PUBLIC(TaskRequest)
 public:
  TaskRequestPrivate(TaskRequest *q);

  TaskRequest *q_ptr;
  TaskReply *reply;
  MessagePacket *message;
};

#endif  // TASK_REQUEST_P_H
