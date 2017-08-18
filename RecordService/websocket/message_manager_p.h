#ifndef MESSAGE_MANAGER_P_H
#define MESSAGE_MANAGER_P_H

#include <QList>
#include <QObject>
#include <QSharedPointer>

class MessageManager;
class TransportThread;
class ProcessThread;
class MessagePacket;

class MessageManagerPrivate {
  Q_DISABLE_COPY(MessageManagerPrivate)
  Q_DECLARE_PUBLIC(MessageManager)
 public:
  MessageManagerPrivate(MessageManager *q);

  MessageManager *q_ptr;
  QList<QSharedPointer<MessagePacket>> requestQueue;

  TransportThread *transportThread;
  ProcessThread *processThread;

  void q_beforeTransport(QSharedPointer<MessagePacket> pkt);
  void q_afterTransport(QSharedPointer<MessagePacket> pkt);

  void q_beforeProcess(QSharedPointer<MessagePacket> pkt);
  void q_afterProcess(QSharedPointer<MessagePacket> pkt);
};

#endif  // MESSAGE_MANAGER_P_H
