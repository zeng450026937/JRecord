#ifndef PROTO_CONF_P_H
#define PROTO_CONF_P_H

#include "proto_base_p.h"
#include "proto_conf.h"

class ProtoConf;

class ProtoConfPrivate : public ProtoBasePrivate
{
    Q_DISABLE_COPY(ProtoConfPrivate)
    Q_DECLARE_PUBLIC(ProtoConf)
public:
    ProtoConfPrivate(ProtoConf *q);
};

#endif // PROTO_CONF_P_H
