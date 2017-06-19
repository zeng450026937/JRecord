#include "proto_binary.h"
#include <QDebug>
#include <QMetaObject>
#include "proto_binary_p.h"
#include "websocket/binarymessage.h"

ProtoBinary::ProtoBinary(QObject *parent)
    : ProtoBase(new ProtoBinaryPrivate(this), parent) {
  Q_D(ProtoBinary);
  d->mode = QStringLiteral("binary");
}

void ProtoBinary::process(QSharedPointer<MessagePacket> pkt) {
  QSharedPointer<BinaryMessage> msg = pkt.dynamicCast<BinaryMessage>();
  if (msg) {
    Q_EMIT binaryReceived(msg->data());
  }
}
