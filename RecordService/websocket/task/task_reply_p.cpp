#include "task_reply_p.h"

TaskReplyPrivate::TaskReplyPrivate(TaskReply *q)
    : q_ptr(q), status(TaskReply::Idle) {}
