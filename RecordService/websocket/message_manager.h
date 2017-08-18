#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include <QObject>

class MessageManagerPrivate;
class MessageReply;
class MessagePacket;
class TransportThread;
class ProcessThread;

class MessageManager : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MessageManager)
  Q_DECLARE_PRIVATE(MessageManager)
  Q_PROPERTY(TransportThread *transportThread READ transportThread WRITE
                 setTransportThread NOTIFY transportThreadChanged)
  Q_PROPERTY(ProcessThread *processThread READ processThread WRITE
                 setProcessThread NOTIFY processThreadChanged)
 public:
  explicit MessageManager(QObject *parent = nullptr);

  MessageReply *postRequest(QSharedPointer<MessagePacket> msg);
  void postMessage(QSharedPointer<MessagePacket> msg);

  TransportThread *transportThread() const;
  ProcessThread *processThread() const;

 Q_SIGNALS:
  void transportThreadChanged(TransportThread *transportThread);
  void processThreadChanged(ProcessThread *processThread);

 public Q_SLOTS:
  void setTransportThread(TransportThread *transportThread);
  void setProcessThread(ProcessThread *processThread);

 protected:
  MessageManager(MessageManagerPrivate *d, QObject *parent = nullptr);
  QScopedPointer<MessageManagerPrivate> d_ptr;

  Q_PRIVATE_SLOT(d_func(),
                 void q_beforeTransport(QSharedPointer<MessagePacket> pkt))
  Q_PRIVATE_SLOT(d_func(),
                 void q_afterTransport(QSharedPointer<MessagePacket> pkt))
  Q_PRIVATE_SLOT(d_func(),
                 void q_beforeProcess(QSharedPointer<MessagePacket> pkt))
  Q_PRIVATE_SLOT(d_func(),
                 void q_afterProcess(QSharedPointer<MessagePacket> pkt))
};

#endif  // MESSAGE_MANAGER_H
