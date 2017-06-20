#include "conference_p.h"

ConferencePrivate::ConferencePrivate(Conference *q)
    : ClientPrivate(q),
      count(0),
      host(Q_NULLPTR),
      type(Conference::Unknown),
      status(Conference::Error) {}
