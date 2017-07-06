#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <QObject>

class TaskManagerPrivate;
class TaskRequest;
class TaskReply;
class MessagePacket;
class TransportThread;
class ProcessThread;

class TaskManager : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(TaskManager)
  Q_DECLARE_PRIVATE(TaskManager)
  Q_PROPERTY(TransportThread *transportThread READ transportThread WRITE
                 setTransportThread NOTIFY transportThreadChanged)
  Q_PROPERTY(ProcessThread *processThread READ processThread WRITE
                 setProcessThread NOTIFY processThreadChanged)
 public:
  explicit TaskManager(QObject *parent = nullptr);

  TaskReply *post(QSharedPointer<TaskRequest> request);

  TransportThread *transportThread() const;
  ProcessThread *processThread() const;

 Q_SIGNALS:
  void transportThreadChanged(TransportThread *transportThread);
  void processThreadChanged(ProcessThread *processThread);

 public Q_SLOTS:
  void setTransportThread(TransportThread *transportThread);
  void setProcessThread(ProcessThread *processThread);

 protected:
  TaskManager(TaskManagerPrivate *d, QObject *parent = nullptr);
  QScopedPointer<TaskManagerPrivate> d_ptr;

  Q_PRIVATE_SLOT(d_func(),
                 void q_beforeTransport(QSharedPointer<MessagePacket> pkt))
  Q_PRIVATE_SLOT(d_func(),
                 void q_afterTransport(QSharedPointer<MessagePacket> pkt))
  Q_PRIVATE_SLOT(d_func(),
                 void q_beforeProcess(QSharedPointer<MessagePacket> pkt))
  Q_PRIVATE_SLOT(d_func(),
                 void q_afterProcess(QSharedPointer<MessagePacket> pkt))
};

#endif  // TASK_MANAGER_H
