#ifndef CONFERENCE_MANAGER_H
#define CONFERENCE_MANAGER_H

#include "client/client.h"

class Conference;
class ConferenceModel;
class ConferenceManagerPrivate;

class ConferenceManager : public Client {
  Q_OBJECT
  Q_DISABLE_COPY(ConferenceManager)
  Q_DECLARE_PRIVATE(ConferenceManager)

 public:
  explicit ConferenceManager(QObject *parent = 0);

  Q_INVOKABLE Conference *conference(const QString &uuid) const;
  Q_INVOKABLE ConferenceModel *model() const;

  Q_INVOKABLE void refresh();

 public Q_SLOTS:

 Q_SIGNALS:

 protected:
  ConferenceManager(ConferenceManagerPrivate *d, QObject *parent = 0);
};

#endif  // CONFERENCE_MANAGER_H
