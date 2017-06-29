#ifndef PROTO_INFO_H
#define PROTO_INFO_H

#include <QJsonValue>
#include "proto_base.h"

class Device;
class ProtoInfoPrivate;

class ProtoInfo : public ProtoBase {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoInfo)
  Q_DECLARE_PRIVATE(ProtoInfo)
 public:
  explicit ProtoInfo(QObject* parent = nullptr);

  enum Actions { heartBeat, updateDeviceInfo, getDeviceList, ActionCount };
  Q_ENUM(Actions)

 Q_SIGNALS:
  void actionRecived(const int action, const QJsonValue& data);

 public Q_SLOTS:
  void push(Device* device);
  void pull();

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_INFO_H
