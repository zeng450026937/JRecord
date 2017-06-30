#ifndef PROTO_CONF_H
#define PROTO_CONF_H

#include "proto_base.h"

class ProtoConfPrivate;

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

 Q_SIGNALS:
  void actionRecived(const int action, const QJsonValue &data);

 public Q_SLOTS:
  void lock();
  void unlock();
  void create(const QString &title, const QString &content,
              const QString &members, const QString &devices);
  void start(const QString &uuid);
  void pause(const QString &uuid);
  void resume(const QString &uuid);
  void stop(const QString &uuid);
  void join(const QString &uuid);
  void leave(const QString &uuid);
  void query(const QString &uuid = "");
  void files(const QString &uuid);

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_CONF_H
