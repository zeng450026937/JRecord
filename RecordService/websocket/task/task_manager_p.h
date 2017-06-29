#ifndef TASKMANAGER_P_H
#define TASKMANAGER_P_H

#include <QObject>
#include <QVector>

class Task;
class TaskManager;

class TaskManagerPrivate {
  Q_DISABLE_COPY(TaskManagerPrivate)
  Q_DECLARE_PUBLIC(TaskManager)

 public:
  TaskManagerPrivate(TaskManager *q);

  TaskManager *q_ptr;
  QVector<Task *> taskList;
};

#endif  // TASKMANAGER_P_H
