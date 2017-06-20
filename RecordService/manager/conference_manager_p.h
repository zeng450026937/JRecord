#ifndef CONFERENCE_MANAGER_P_H
#define CONFERENCE_MANAGER_P_H

#include <QMap>
#include "client/client_p.h"
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
};

#endif  // CONFERENCE_MANAGER_P_H
