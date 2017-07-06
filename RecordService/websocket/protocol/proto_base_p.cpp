#include "proto_base_p.h"

ProtoBasePrivate::ProtoBasePrivate(ProtoBase *q)
    : q_ptr(q), taskManager(Q_NULLPTR) {}
