#include "task_base.h"
#include "task_base_p.h"

TaskBase::TaskBase(QObject *parent)
    : ProtoBase(new TaskBasePrivate(this), parent) {}

int TaskBase::action() const { return d_func()->action; }

bool TaskBase::repeat() const { return d_func()->repeat; }

QJsonValue TaskBase::param() const { return d_func()->param; }

TaskBase::Status TaskBase::status() const { return d_func()->status; }

void TaskBase::setAction(int action) {
  Q_D(TaskBase);
  if (action != d->action) {
    d->action = action;
    Q_EMIT actionChanged(d->action);
  }
}

void TaskBase::setRepeat(bool repeat) {
  Q_D(TaskBase);
  if (repeat != d->repeat) {
    d->repeat = repeat;
    Q_EMIT repeatChanged(d->repeat);
  }
}

void TaskBase::setParam(const QJsonValue &param) {
  Q_D(TaskBase);
  if (param != d->param) {
    d->param = param;
    Q_EMIT paramChanged(d->param);
  }
}

void TaskBase::setStatus(TaskBase::Status status) {
  Q_D(TaskBase);
  if (status != d->status) {
    d->status = status;
    Q_EMIT statusChanged(d->status);
  }
}

TaskBase::TaskBase(TaskBasePrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
