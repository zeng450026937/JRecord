#include "proto_base.h"
#include "proto_base_p.h"

const QString ProtoBase::INFO_MODE = QStringLiteral("info");
const QString ProtoBase::CONFERENCE_MODE = QStringLiteral("conference");
const QString ProtoBase::PERSONAL_MODE = QStringLiteral("personal");
const QString ProtoBase::MOBILE_MODE = QStringLiteral("mobile");
const QString ProtoBase::BINARY_MODE = QStringLiteral("binary");

ProtoBase::ProtoBase(QObject *parent)
    : QObject(parent), d_ptr(new ProtoBasePrivate(this)) {}

QString ProtoBase::mode() const { return d_func()->mode; }

void ProtoBase::process(QSharedPointer<MessagePacket> pkt) { Q_UNUSED(pkt); }

ProtoBase::ProtoBase(ProtoBasePrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
