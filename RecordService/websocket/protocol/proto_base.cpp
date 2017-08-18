#include "proto_base.h"
#include "proto_base_p.h"
#include "websocket/textmessage.h"

const QString ProtoBase::INFO_MODE = QStringLiteral("info");
const QString ProtoBase::CONFERENCE_MODE = QStringLiteral("conference");
const QString ProtoBase::PERSONAL_MODE = QStringLiteral("personal");
const QString ProtoBase::MOBILE_MODE = QStringLiteral("mobile");
const QString ProtoBase::BINARY_MODE = QStringLiteral("binary");

ProtoBase::ProtoBase(QObject *parent)
    : QObject(parent), d_ptr(new ProtoBasePrivate(this)) {}

QString ProtoBase::mode() const { return d_func()->mode; }

QSharedPointer<MessagePacket> ProtoBase::makeMessage(int action,
                                                     const QJsonValue &data) {
  Q_D(ProtoBase);
  QSharedPointer<TextMessage> message(new TextMessage);

  message->setMode(d->mode);
  message->setAction(d->metaEnum.valueToKey(action));
  message->setData(data);

  return message;
}

void ProtoBase::process(QSharedPointer<MessagePacket> pkt) { Q_UNUSED(pkt); }

ProtoBase::ProtoBase(ProtoBasePrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
