#include "textmessage_p.h"

TextMessagePrivate::TextMessagePrivate(TextMessage *q)
    : MessagePacketPrivate(q),
      version(QStringLiteral("1.0")),
      authorization(QStringLiteral("authorization")),
      result(false) {
  type = MessagePacket::Text;
}
