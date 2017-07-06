#include "task_reply.h"
#include "task_reply_p.h"

TaskReply::TaskReply(QObject *parent)
    : QObject(parent), d_ptr(new TaskReplyPrivate(this)) {}

QJsonValue TaskReply::data() const { return d_func()->data; }

TaskReply::Status TaskReply::status() const { return d_func()->status; }

void TaskReply::setData(const QJsonValue &data) {
  Q_D(TaskReply);
  if (data != d->data) {
    d->data = data;
    Q_EMIT dataChanged(d->data);
  }
}

void TaskReply::setStatus(TaskReply::Status status) {
  Q_D(TaskReply);
  if (status != d->status) {
    d->status = status;
    Q_EMIT statusChanged(d->status);
  }
}

TaskReply::TaskReply(TaskReplyPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
