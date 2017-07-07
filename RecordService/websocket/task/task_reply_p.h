#ifndef TASK_REPLY_P_H
#define TASK_REPLY_P_H

#include "task_reply.h"

class MessagePacket;

class TaskReplyPrivate {
  Q_DISABLE_COPY(TaskReplyPrivate)
  Q_DECLARE_PUBLIC(TaskReply)
 public:
  TaskReplyPrivate(TaskReply *q);

  TaskReply *q_ptr;
  QJsonValue data;
  TaskReply::Status status;
  int timer;
};

#endif  // TASK_REPLY_P_H
