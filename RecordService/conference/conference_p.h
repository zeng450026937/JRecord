#ifndef CONFERENCE_P_H
#define CONFERENCE_P_H

#include <QDate>
#include "client/client_p.h"
#include "conference.h"

class ProtoConf;

class ConferencePrivate : public ClientPrivate {
  Q_DISABLE_COPY(ConferencePrivate)
  Q_DECLARE_PUBLIC(Conference)
 public:
  ConferencePrivate(Conference *q);

  QString uuid;
  Conference::Type type;
  Device *host;
  QString title;
  QString content;
  QString member;
  QString gps;
  QString tag;
  QDate createTime;
  QDate updateTime;
  Conference::Status status;
  int count;
  QString errorString;

  QList<Device *> devicelist;
};

#endif  // CONFERENCE_P_H
