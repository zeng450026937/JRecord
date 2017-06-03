#include "proto_info_p.h"

ProtoInfoPrivate::ProtoInfoPrivate(ServiceBase *s, ProtoInfo *q) :
    ProtoBasePrivate(s,q)
{
    mode = QStringLiteral("info");
}
