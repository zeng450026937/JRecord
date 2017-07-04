#include "task_reply.h"
#include "task_reply_p.h"

TaskReply::TaskReply(QObject *parent)
    : QObject(parent), d_ptr(new TaskReplyPrivate(this)) {}

TaskReply::TaskReply(TaskReplyPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
