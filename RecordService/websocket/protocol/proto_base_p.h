#ifndef PROTO_BASE_P_H
#define PROTO_BASE_P_H

#include <QList>
#include <QMetaEnum>
#include <QMutex>
#include <QObject>
#include <QSharedPointer>

class ProtoBase;
class MessagePacket;
class TransportThread;

class ProtoBasePrivate {
 public:
  Q_DISABLE_COPY(ProtoBasePrivate)
  Q_DECLARE_PUBLIC(ProtoBase)

  ProtoBasePrivate(ProtoBase *q);

  ProtoBase *q_ptr;
  QString mode;
  TransportThread *transport;
  QMetaEnum metaEnum;
  QMutex mutex;
  QList<QSharedPointer<MessagePacket>> taskQueue;
};

#endif  // PROTO_BASE_P_H
