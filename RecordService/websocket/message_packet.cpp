#include "message_packet.h"
#include "message_packet_p.h"

MessagePacket::MessagePacket(QObject *parent)
    : QObject(parent), d_ptr(new MessagePacketPrivate(this)) {}

bool MessagePacket::equals(MessagePacket *msg) {
  if (!msg) return false;
  Q_D(MessagePacket);
  if (d->uuid == msg->uuid()) return true;
  return false;
}

MessagePacket::MessageType MessagePacket::type() const {
  return d_func()->type;
}

QUuid MessagePacket::uuid() const { return d_func()->uuid; }

MessageReply *MessagePacket::reply() const { return d_func()->reply; }

void MessagePacket::setType(MessagePacket::MessageType type) {
  Q_D(MessagePacket);
  if (type != d->type) {
    d->type = type;
    Q_EMIT typeChanged(d->type);
  }
}

void MessagePacket::setUuid(const QUuid &uuid) {
  Q_D(MessagePacket);
  if (uuid != d->uuid) {
    d->uuid = uuid;
    Q_EMIT uuidChanged(d->uuid);
  }
}

void MessagePacket::setReply(MessageReply *reply) {
  Q_D(MessagePacket);
  if (reply != d->reply) {
    d->reply = reply;
    Q_EMIT replyChanged(d->reply);
  }
}

MessagePacket::MessagePacket(MessagePacketPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
