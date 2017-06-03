#include "proto_base.h"
#include "proto_base_p.h"

ProtoBase::ProtoBase(ServiceBase *service, QObject *parent) :
    QObject(parent),
    d_ptr(new ProtoBasePrivate(service, this))
{

}

QString ProtoBase::mode() const
{
    return d_func()->mode;
}

void ProtoBase::process(QSharedPointer<MessagePacket> pkt)
{
    Q_UNUSED(pkt);
}

MessagePacket *ProtoBase::make(QString from, QString to, int action, QVariantMap data, QString mode)
{
    Q_UNUSED(from);
    Q_UNUSED(to);
    Q_UNUSED(action);
    Q_UNUSED(data);
    Q_UNUSED(mode);
    return Q_NULLPTR;
}

ProtoBase::ProtoBase(ProtoBasePrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}
