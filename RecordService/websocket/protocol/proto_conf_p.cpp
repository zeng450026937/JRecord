#include "proto_conf_p.h"

ProtoConfPrivate::ProtoConfPrivate(ServiceBase *s, ProtoConf *q) :
    ProtoBasePrivate(s,q)
{
    mode = QStringLiteral("conference");
}
