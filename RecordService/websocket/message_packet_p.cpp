#include "message_packet_p.h"

MessagePacketPrivate::MessagePacketPrivate(MessagePacket *q)
    : q_ptr(q),
      type(MessagePacket::Unknow),
      uuid(QUuid::createUuid()),
      reply(Q_NULLPTR) {}
