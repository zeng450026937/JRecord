#ifndef PROTO_MOBILE_P_H
#define PROTO_MOBILE_P_H

#include "proto_base_p.h"
#include "proto_mobile.h"

class ProtoMobile;

class ProtoMobilePrivate : public ProtoBasePrivate {
  Q_DISABLE_COPY(ProtoMobilePrivate)
  Q_DECLARE_PUBLIC(ProtoMobile)
 public:
  ProtoMobilePrivate(ProtoMobile *q);
};

#endif  // PROTO_MOBILE_P_H
