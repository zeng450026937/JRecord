#ifndef TASK_REQUEST_H
#define TASK_REQUEST_H

#include "websocket/textmessage.h"

class TaskRequestPrivate;
class TaskReply;

class TaskRequest : public TextMessage {
  Q_OBJECT
  Q_DISABLE_COPY(TaskRequest)
  Q_DECLARE_PRIVATE(TaskRequest)
 public:
  explicit TaskRequest(QObject *parent = 0);

  static void doDeleteLater(TaskRequest *request);

 protected:
  TaskRequest(TaskRequestPrivate *d, QObject *parent = 0);
  friend class TaskManager;
  friend class TaskManagerPrivate;
  void setReply(TaskReply *reply);
  TaskReply *reply();
  bool match(MessagePacket *pkt);
};

#endif  // TASK_REQUEST_H
