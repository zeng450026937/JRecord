#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <QObject>

class TaskManagerPrivate;
class TaskRequest;
class TaskReply;

class TaskManager : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(TaskManager)
  Q_DECLARE_PRIVATE(TaskManager)
 public:
  explicit TaskManager(QObject *parent = nullptr);

  TaskReply *post(const TaskRequest &request);

 Q_SIGNALS:

 public Q_SLOTS:

 protected:
  TaskManager(TaskManagerPrivate *d, QObject *parent = nullptr);
  QScopedPointer<TaskManagerPrivate> d_ptr;
};

#endif  // TASK_MANAGER_H
