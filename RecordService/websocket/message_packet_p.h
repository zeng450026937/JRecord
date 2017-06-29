#ifndef MESSAGE_PACKET_P_H
#define MESSAGE_PACKET_P_H

#include "message_packet.h"

class MessagePacketPrivate {
 public:
  Q_DISABLE_COPY(MessagePacketPrivate)
  Q_DECLARE_PUBLIC(MessagePacket)
  MessagePacketPrivate(MessagePacket *q);

  MessagePacket *q_ptr;
  MessagePacket::MessageType type;
};

#endif  // MESSAGE_PACKET_P_H
