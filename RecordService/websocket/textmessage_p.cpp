#include "textmessage_p.h"

TextMessagePrivate::TextMessagePrivate(TextMessage *q)
    : q_ptr(q),
      version(QStringLiteral("1.0")),
      authorization(QStringLiteral("authorization")),
      result(true) {}
