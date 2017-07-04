#ifndef TASK_BACKEND_H
#define TASK_BACKEND_H

#include <QObject>

class TaskBackendPrivate;

class TaskBackend : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(TaskBackend)
  Q_DECLARE_PRIVATE(TaskBackend)
 public:
  explicit TaskBackend(QObject *parent = nullptr);

 Q_SIGNALS:

 public Q_SLOTS:

 protected:
  TaskBackend(TaskBackendPrivate *d, QObject *parent = nullptr);
  QScopedPointer<TaskBackendPrivate> d_ptr;
  friend class TaskManager;
};

#endif  // TASK_BACKEND_H
