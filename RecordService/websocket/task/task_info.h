#ifndef TASK_INFO_H
#define TASK_INFO_H

#include "websocket/protocol/proto_info.h"

class TaskInfoPrivate;

class TaskInfo : public ProtoInfo {
  Q_OBJECT
  Q_DISABLE_COPY(TaskInfo)
  Q_DECLARE_PRIVATE(TaskInfo)
 public:
  explicit TaskInfo(QObject* parent = nullptr);

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // TASK_INFO_H
