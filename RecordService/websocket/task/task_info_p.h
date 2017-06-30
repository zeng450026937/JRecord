#ifndef TASK_INFO_P_H
#define TASK_INFO_P_H

#include "task_info.h"
#include "websocket/protocol/proto_info_p.h"

class TaskInfoPrivate : public ProtoInfoPrivate {
  Q_DISABLE_COPY(TaskInfoPrivate)
  Q_DECLARE_PUBLIC(TaskInfo)
 public:
  TaskInfoPrivate(TaskInfo *q);
};

#endif  // TASK_INFO_P_H
