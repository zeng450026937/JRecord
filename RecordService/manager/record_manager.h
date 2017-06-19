#ifndef RECORD_MANAGER_H
#define RECORD_MANAGER_H

#include "client/client.h"

class Record;
class RecordManagerPrivate;

class RecordManager : public Client {
  Q_OBJECT
  Q_DISABLE_COPY(RecordManager)
  Q_DECLARE_PRIVATE(RecordManager)

 public:
  explicit RecordManager(QObject *parent = 0);

  Q_INVOKABLE Record *record(const QString &uuid);

 public Q_SLOTS:

 Q_SIGNALS:

 protected:
  RecordManager(RecordManagerPrivate *d, QObject *parent = 0);
  QScopedPointer<RecordManagerPrivate> d_ptr;
};

#endif  // RECORD_MANAGER_H
