#ifndef CONFERENCE_MANAGER_P_H
#define CONFERENCE_MANAGER_P_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMap>
#include "client/client_p.h"
#include "conference/conference.h"
#include "manager/conference_manager.h"

class ProtoConf;
class ProtoPerson;
class ProtoMobile;

class ConferenceManagerPrivate : public ClientPrivate {
  Q_DISABLE_COPY(ConferenceManagerPrivate)
  Q_DECLARE_PUBLIC(ConferenceManager)
 public:
  ConferenceManagerPrivate(ConferenceManager* q);

  QMap<QString, Conference*> confMap;
  ProtoConf* conf_protocol;
  ProtoPerson* person_protocol;
  ProtoMobile* mobile_protocol;
  ConferenceModel* model;

  void updateConference(Conference::Type type, const QJsonObject& data);
};

#endif  // CONFERENCE_MANAGER_P_H
