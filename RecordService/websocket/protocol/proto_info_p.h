#ifndef PROTO_INFO_P_H
#define PROTO_INFO_P_H

#include "proto_base_p.h"
#include "proto_info.h"

class ProtoInfoPrivate : public ProtoBasePrivate {
  Q_DISABLE_COPY(ProtoInfoPrivate)
  Q_DECLARE_PUBLIC(ProtoInfo)
 public:
  ProtoInfoPrivate(ProtoInfo *q);
};

#endif  // PROTO_INFO_P_H
