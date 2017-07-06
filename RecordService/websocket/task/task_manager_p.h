#ifndef TASK_MANAGER_P_H
#define TASK_MANAGER_P_H

#include <QList>
#include <QMutex>
#include <QObject>
#include <QSharedPointer>

class TaskManager;
class TaskRequest;
class TransportThread;
class ProcessThread;
class MessagePacket;

class TaskManagerPrivate {
  Q_DISABLE_COPY(TaskManagerPrivate)
  Q_DECLARE_PUBLIC(TaskManager)
 public:
  TaskManagerPrivate(TaskManager *q);

  TaskManager *q_ptr;
  QMutex mutex;
  QList<QSharedPointer<TaskRequest>> requestQueue;
  TransportThread *transportThread;
  ProcessThread *processThread;

  void q_beforeTransport(QSharedPointer<MessagePacket> pkt);
  void q_afterTransport(QSharedPointer<MessagePacket> pkt);

  void q_beforeProcess(QSharedPointer<MessagePacket> pkt);
  void q_afterProcess(QSharedPointer<MessagePacket> pkt);
};

#endif  // TASK_MANAGER_P_H
