#ifndef MESSAGE_REPLY_P_H
#define MESSAGE_REPLY_P_H

#include "message_reply.h"

class MessagePacket;

class MessageReplyPrivate {
  Q_DISABLE_COPY(MessageReplyPrivate)
  Q_DECLARE_PUBLIC(MessageReply)
 public:
  MessageReplyPrivate(MessageReply *q);

  MessageReply *q_ptr;
  QJsonValue data;
  MessageReply::Status status;
  int timer;
};

#endif  // MESSAGE_REPLY_P_H
