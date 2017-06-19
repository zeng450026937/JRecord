#ifndef RECORD_MANAGER_P_H
#define RECORD_MANAGER_P_H

#include <QMap>
#include "client/client_p.h"
#include "manager/record_manager.h"

class Record;
class ProtoBinary;
class RecordManager;

class RecordManagerPrivate : public ClientPrivate {
  Q_DISABLE_COPY(RecordManagerPrivate)
  Q_DECLARE_PUBLIC(RecordManager)
 public:
  RecordManagerPrivate(RecordManager* q);

  QMap<QString, Record*> recordMap;
  ProtoBinary* protocol;
};

#endif  // RECORD_MANAGER_P_H
