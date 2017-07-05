#include "message_packet.h"
#include "message_packet_p.h"

MessagePacket::MessagePacket(QObject *parent)
    : QObject(parent), d_ptr(new MessagePacketPrivate(this)) {}

int MessagePacket::id() const { return d_func()->id; }

MessagePacket::MessageType MessagePacket::type() const {
  return d_func()->type;
}

bool MessagePacket::match(MessagePacket *pkt) {
  Q_UNUSED(pkt);
  return false;
}

bool MessagePacket::hasNotification() { return false; }

bool MessagePacket::notify() { return false; }

void MessagePacket::setId(int id) {
  Q_D(MessagePacket);
  if (id != d->id) {
    d->id = id;
    Q_EMIT idChanged(d->id);
  }
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
