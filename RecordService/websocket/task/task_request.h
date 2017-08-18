#ifndef TASK_REQUEST_H
#define TASK_REQUEST_H

#include <QObject>

class TaskRequestPrivate;
class TaskReply;
class MessagePacket;

class TaskRequest : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(TaskRequest)
  Q_DECLARE_PRIVATE(TaskRequest)
  Q_PROPERTY(TaskReply *reply READ reply WRITE setReply NOTIFY replyChanged)
  Q_PROPERTY(MessagePacket *message READ message WRITE setMessage NOTIFY
                 messageChanged)
 public:
  explicit TaskRequest(QObject *parent = 0);

  static void doDeleteLater(TaskRequest *request);

  TaskReply *reply() const;
  MessagePacket *message() const;

 public Q_SLOTS:
  void setReply(TaskReply *reply);
  void setMessage(MessagePacket *msg);

 Q_SIGNALS:
  void replyChanged(TaskReply *reply);
  void messageChanged(MessagePacket *msg);

 protected:
  TaskRequest(TaskRequestPrivate *d, QObject *parent = 0);
  QScopedPointer<TaskRequestPrivate> d_ptr;
};

#endif  // TASK_REQUEST_H
