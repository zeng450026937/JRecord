#include "proto_base.h"
#include "proto_base_p.h"
#include "service/service_base.h"
#include "websocket/textmessage.h"
#include "websocket/transport_thread.h"

ProtoBase::ProtoBase(QObject *parent)
    : QObject(parent), d_ptr(new ProtoBasePrivate(this)) {}

QString ProtoBase::mode() const { return d_func()->mode; }

void ProtoBase::process(QSharedPointer<MessagePacket> pkt) { Q_UNUSED(pkt); }

void ProtoBase::transport(QString from, QString to, QString action,
                          const QVariantMap &data) {
  Q_D(ProtoBase);
  if (d->transport) {
    d->transport->pushMessage(new TextMessage(from, to, d->mode, action, data));
  }
}

ProtoBase::ProtoBase(ProtoBasePrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
