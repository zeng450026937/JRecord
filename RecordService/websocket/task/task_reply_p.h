#ifndef TASK_REPLY_P_H
#define TASK_REPLY_P_H

#include <QObject>

class TaskReply;

class TaskReplyPrivate {
  Q_DISABLE_COPY(TaskReplyPrivate)
  Q_DECLARE_PUBLIC(TaskReply)
 public:
  TaskReplyPrivate(TaskReply *q);

  TaskReply *q_ptr;
};

#endif  // TASK_REPLY_P_H
