#ifndef PROTO_BINARY_H
#define PROTO_BINARY_H

#include "proto_base.h"

class ProtoBinaryPrivate;

class ProtoBinary : public ProtoBase {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoBinary)
  Q_DECLARE_PRIVATE(ProtoBinary)
 public:
  explicit ProtoBinary(QObject* parent = nullptr);

 Q_SIGNALS:
  void binaryReceived(const QByteArray& data);

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_BINARY_H
