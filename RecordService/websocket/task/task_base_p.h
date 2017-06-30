#ifndef TASK_BASE_P_H
#define TASK_BASE_P_H

#include <QJsonObject>
#include "task_base.h"
#include "websocket/protocol/proto_base_p.h"

class TaskBasePrivate : public ProtoBasePrivate {
 public:
  Q_DISABLE_COPY(TaskBasePrivate)
  Q_DECLARE_PUBLIC(TaskBase)

  TaskBasePrivate(TaskBase *q);

  QString mode;
  int action;
  bool repeat;
  QJsonObject param;
  QJsonObject result;
  TaskBase::Status status;
};

#endif  // TASK_BASE_P_H
