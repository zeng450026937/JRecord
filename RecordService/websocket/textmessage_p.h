#ifndef TEXTMESSAGE_P_H
#define TEXTMESSAGE_P_H

#include "message_packet_p.h"
#include "textmessage.h"

class TextMessagePrivate : public MessagePacketPrivate {
  Q_DISABLE_COPY(TextMessagePrivate)
  Q_DECLARE_PUBLIC(TextMessage)
 public:
  TextMessagePrivate(TextMessage* q);

  QString version;
  QString authorization;  // reserved
  QString from;
  QString to;
  QJsonObject command;
  QJsonValue data;
  bool result;
};

#endif  // TEXTMESSAGE_P_H
