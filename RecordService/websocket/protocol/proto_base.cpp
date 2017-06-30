#include "proto_base.h"
#include <QSharedPointer>
#include "proto_base_p.h"
#include "service/service_base.h"
#include "websocket/textmessage.h"
#include "websocket/transport_thread.h"

const QString ProtoBase::INFO_MODE = QStringLiteral("info");
const QString ProtoBase::CONFERENCE_MODE = QStringLiteral("conference");
const QString ProtoBase::PERSONAL_MODE = QStringLiteral("personal");
const QString ProtoBase::MOBILE_MODE = QStringLiteral("mobile");
const QString ProtoBase::BINARY_MODE = QStringLiteral("binary");

ProtoBase::ProtoBase(QObject *parent)
    : QObject(parent), d_ptr(new ProtoBasePrivate(this)) {}

QString ProtoBase::mode() const { return d_func()->mode; }

void ProtoBase::process(QSharedPointer<MessagePacket> pkt) { Q_UNUSED(pkt); }

void ProtoBase::transport(QString from, QString to, QString action,
                          const QJsonObject &data) {
  Q_D(ProtoBase);
  if (d->transport) {
    QSharedPointer<MessagePacket> pkt(
        new TextMessage(from, to, d->mode, action, data));
    d->transport->pushMessage(pkt);
  }
}

ProtoBase::ProtoBase(ProtoBasePrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
