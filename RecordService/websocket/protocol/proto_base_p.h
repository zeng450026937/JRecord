#ifndef PROTO_BASE_P_H
#define PROTO_BASE_P_H

#include <QObject>

class ServiceBase;
class ProtoBase;

class ProtoBasePrivate
{
public:
    Q_DISABLE_COPY(ProtoBasePrivate)
    Q_DECLARE_PUBLIC(ProtoBase)

    ProtoBasePrivate(ServiceBase *s, ProtoBase *q);

    ProtoBase *q_ptr;
    QString mode;
    ServiceBase *service;
};

#endif // PROTO_BASE_P_H
