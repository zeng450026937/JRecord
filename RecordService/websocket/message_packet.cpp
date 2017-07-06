#include "message_packet.h"
#include "message_packet_p.h"

MessagePacket::MessagePacket(QObject *parent)
    : QObject(parent), d_ptr(new MessagePacketPrivate(this)) {}

MessagePacket::MessageType MessagePacket::type() const {
  return d_func()->type;
}

bool MessagePacket::notification() const { return d_func()->notification; }

void MessagePacket::setType(MessagePacket::MessageType type) {
  Q_D(MessagePacket);
  if (type != d->type) {
    d->type = type;
    Q_EMIT typeChanged(d->type);
  }
}

void MessagePacket::setNotification(bool notification) {
  Q_D(MessagePacket);
  if (notification != d->notification) {
    d->notification = notification;
    Q_EMIT notificationChanged(d->notification);
  }
}

MessagePacket::MessagePacket(MessagePacketPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
