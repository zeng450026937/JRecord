#ifndef PROTO_PERSON_P_H
#define PROTO_PERSON_P_H

#include "proto_base_p.h"
#include "proto_person.h"

class ProtoPerson;

class ProtoPersonPrivate : public ProtoBasePrivate {
  Q_DISABLE_COPY(ProtoPersonPrivate)
  Q_DECLARE_PUBLIC(ProtoPerson)
 public:
  ProtoPersonPrivate(ProtoPerson *q);
};

#endif  // PROTO_PERSON_P_H
