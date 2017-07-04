#include "task_request.h"
#include "task_request_p.h"

TaskRequest::TaskRequest(QObject *parent)
    : QObject(parent), d_ptr(new TaskRequestPrivate(this)) {}

TaskRequest::Type TaskRequest::type() const { return d_func()->type; }

QJsonValue TaskRequest::data() const { return d_func()->data; }

void TaskRequest::setType(const TaskRequest::Type &type) {
  Q_D(TaskRequest);
  if (type != d->type) {
    d->type = type;
    Q_EMIT typeChanged(d->type);
  }
}

void TaskRequest::setData(const QJsonValue &data) {
  Q_D(TaskRequest);
  if (data != d->data) {
    d->data = data;
    Q_EMIT dataChanged(d->data);
  }
}

TaskRequest::TaskRequest(TaskRequestPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
