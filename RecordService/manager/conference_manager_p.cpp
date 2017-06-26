#include "conference_manager_p.h"
#include "model/conference_model.h"

ConferenceManagerPrivate::ConferenceManagerPrivate(ConferenceManager *q)
    : ClientPrivate(q),
      conf_protocol(Q_NULLPTR),
      person_protocol(Q_NULLPTR),
      mobile_protocol(Q_NULLPTR) {}

void ConferenceManagerPrivate::updateConference(Conference::Type type,
                                                const QJsonObject &data) {
  Conference *conference(Q_NULLPTR);

  conference = confMap.value(
      data.value(QLatin1String("conferenceUuid")).toString(), Q_NULLPTR);
  if (conference) {
    conference->fromJson(data);
  } else {
    conference = new Conference(data, q_ptr);
    conference->setType(type);
    conference->setService(service);
    confMap.insert(conference->uuid(), conference);

    model->addConference(conference);
  }
}
