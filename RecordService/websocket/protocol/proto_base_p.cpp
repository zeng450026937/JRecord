#include "proto_base_p.h"

ProtoBasePrivate::ProtoBasePrivate(ServiceBase *s, ProtoBase *q) :
    q_ptr(q),
    service(s)
{

}
