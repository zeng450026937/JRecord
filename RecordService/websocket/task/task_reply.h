#ifndef TASK_REPLY_H
#define TASK_REPLY_H

#include <QObject>

class TaskReplyPrivate;

class TaskReply : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(TaskReply)
  Q_DECLARE_PRIVATE(TaskReply)
 public:
  explicit TaskReply(QObject *parent = nullptr);

 Q_SIGNALS:

 public Q_SLOTS:

 protected:
  TaskReply(TaskReplyPrivate *d, QObject *parent = nullptr);
  QScopedPointer<TaskReplyPrivate> d_ptr;
};
#endif  // TASK_REPLY_H
