#include "message_packet.h"
#include "message_packet_p.h"

MessagePacket::MessagePacket(QObject *parent)
    : QObject(parent), d_ptr(new MessagePacketPrivate(this)) {}

MessagePacket::MessageType MessagePacket::type() const {
  return d_func()->type;
}

void MessagePacket::setType(MessagePacket::MessageType type) {
  Q_D(MessagePacket);
  if (type != d->type) {
    d->type = type;
    Q_EMIT typeChanged(d->type);
  }
}

MessagePacket::MessagePacket(MessagePacketPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
