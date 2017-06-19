#ifndef PROTO_BINARY_P_H
#define PROTO_BINARY_P_H

#include "proto_base_p.h"
#include "proto_binary.h"

class ProtoBinary;

class ProtoBinaryPrivate : public ProtoBasePrivate {
  Q_DISABLE_COPY(ProtoBinaryPrivate)
  Q_DECLARE_PUBLIC(ProtoBinary)
 public:
  ProtoBinaryPrivate(ProtoBinary *q);
};

#endif  // PROTO_BINARY_P_H
