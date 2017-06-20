#ifndef CONFERENCE_MODEL_P_H
#define CONFERENCE_MODEL_P_H

#include <QHash>
#include <QObject>

class ConferenceModel;

class ConferenceModelPrivate {
  Q_DISABLE_COPY(ConferenceModelPrivate)
  Q_DECLARE_PUBLIC(ConferenceModel)
 public:
  ConferenceModelPrivate(ConferenceModel *q);

  ConferenceModel *q_ptr;
  QHash<int, QByteArray> roleNames;
};

#endif  // CONFERENCE_MODEL_P_H
