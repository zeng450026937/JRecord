#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <QJsonObject>
#include <QObject>

class Task;
class TaskManagerPrivate;

class TaskManager : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(TaskManager)
  Q_DECLARE_PRIVATE(TaskManager)
 public:
  explicit TaskManager(QObject *parent = nullptr);

  Q_INVOKABLE void pushTask(Task *task);

 Q_SIGNALS:
  void broadcast(const QString &mode, const int action,
                 const QJsonObject &data);

 protected:
  TaskManager(TaskManagerPrivate *d, QObject *parent = nullptr);
  QScopedPointer<TaskManagerPrivate> d_ptr;
};

#endif  // TASK_MANAGER_H
