#include "proto_base.h"
#include "proto_base_p.h"
#include "websocket/transport_thread.h"
#include "websocket/textmessage.h"

ProtoBase::ProtoBase(QObject *parent) :
    QObject(parent),
    d_ptr(new ProtoBasePrivate(this))
{

}

QString ProtoBase::mode() const
{
    return d_func()->mode;
}

QString ProtoBase::owner() const
{
    return d_func()->owner;
}

void ProtoBase::setOwner(const QString &owner)
{
    Q_D(ProtoBase);
    if(owner != d->owner){
        d->owner = owner;
        Q_EMIT ownerChanged(d->owner);
    }
}

void ProtoBase::process(QSharedPointer<MessagePacket> pkt)
{
    Q_UNUSED(pkt);
}

void ProtoBase::transport(QString to, QString action, QVariantMap data)
{
    Q_D(ProtoBase);
    if(d->transport){
        d->transport->pushMessage(new TextMessage(d->owner,to,d->mode,action,data));
    }
}

ProtoBase::ProtoBase(ProtoBasePrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}
