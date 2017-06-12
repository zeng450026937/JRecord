#ifndef PROTO_BASE_P_H
#define PROTO_BASE_P_H

#include <QObject>
#include <QMetaEnum>

class TransportThread;
class ProtoBase;

class ProtoBasePrivate
{
public:
    Q_DISABLE_COPY(ProtoBasePrivate)
    Q_DECLARE_PUBLIC(ProtoBase)

    ProtoBasePrivate(ProtoBase *q);

    ProtoBase *q_ptr;
    QString owner;
    QString mode;
    TransportThread *transport;
    QMetaEnum metaEnum;
};

#endif // PROTO_BASE_P_H
