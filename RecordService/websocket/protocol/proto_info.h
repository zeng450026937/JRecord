#ifndef PROTO_INFO_H
#define PROTO_INFO_H

#include "proto_base.h"

class ProtoInfoPrivate;
class Device;
class TaskReply;

class ProtoInfo : public ProtoBase {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoInfo)
  Q_DECLARE_PRIVATE(ProtoInfo)
 public:
  explicit ProtoInfo(QObject* parent = nullptr);

  enum Actions { heartBeat, updateDeviceInfo, getDeviceList, ActionCount };
  Q_ENUM(Actions)

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_INFO_H
