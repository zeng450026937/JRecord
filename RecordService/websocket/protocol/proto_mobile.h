#ifndef PROTO_MOBILE_H
#define PROTO_MOBILE_H

#include "proto_base.h"

class ProtoMobilePrivate;
class TaskReply;

class ProtoMobile : public ProtoBase {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoMobile)
  Q_DECLARE_PRIVATE(ProtoMobile)
 public:
  explicit ProtoMobile(QObject* parent = nullptr);

  enum Actions { getConferences, unknown };
  Q_ENUM(Actions)

 public Q_SLOTS:
  TaskReply* query();

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_MOBILE_H
