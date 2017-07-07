#ifndef PROTO_CONF_H
#define PROTO_CONF_H

#include "proto_base.h"

class ProtoConfPrivate;
class TaskReply;

class ProtoConf : public ProtoBase {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoConf)
  Q_DECLARE_PRIVATE(ProtoConf)
 public:
  explicit ProtoConf(QObject *parent = nullptr);

  enum Actions {
    lockDevice,
    unlockDevice,
    createConference,
    getConferenceInfo,
    getConferenceList,
    getConferenceFiles,
    joinConference,
    leveaveConference,
    startConference,
    resumeConference,
    pauseConference,
    stopConference,
    setConferenceInfo,
    deleteConferenceInfo,
    unknown
  };
  Q_ENUM(Actions)

  QSharedPointer<TaskRequest> makeRequest(int action,
                                          const QJsonValue &data) override;

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_CONF_H
