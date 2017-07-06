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

 public Q_SLOTS:
  TaskReply *lock();
  TaskReply *unlock();
  TaskReply *create(const QString &title, const QString &content,
                    const QString &members, const QString &devices);
  TaskReply *start(const QString &uuid);
  TaskReply *pause(const QString &uuid);
  TaskReply *resume(const QString &uuid);
  TaskReply *stop(const QString &uuid);
  TaskReply *join(const QString &uuid);
  TaskReply *leave(const QString &uuid);
  TaskReply *query(const QString &uuid = "");
  TaskReply *files(const QString &uuid);

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_CONF_H
