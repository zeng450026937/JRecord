#ifndef PROTO_PERSON_H
#define PROTO_PERSON_H

#include "proto_base.h"

class ProtoPersonPrivate;
class TaskReply;

class ProtoPerson : public ProtoBase {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoPerson)
  Q_DECLARE_PRIVATE(ProtoPerson)
 public:
  explicit ProtoPerson(QObject* parent = nullptr);

  enum Actions { getPersonalList, unknown };
  Q_ENUM(Actions)

  QSharedPointer<TaskRequest> makeRequest(int action,
                                          const QJsonValue& data) override;

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_PERSON_H
