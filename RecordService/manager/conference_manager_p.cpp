#include "conference_manager_p.h"

ConferenceManagerPrivate::ConferenceManagerPrivate(ConferenceManager *q)
    : ClientPrivate(q),
      conf_protocol(Q_NULLPTR),
      person_protocol(Q_NULLPTR),
      mobile_protocol(Q_NULLPTR) {}
