#include "task.h"
#include "task_p.h"

Task::Task(QObject *parent) : QObject(parent), d_ptr(new TaskPrivate(this)) {}

QString Task::mode() const { return d_func()->mode; }

int Task::action() const { return d_func()->action; }

QJsonObject Task::data() const { return d_func()->data; }

void Task::setMode(const QString &mode) {
  Q_D(Task);
  if (mode != d->mode) {
    d->mode = mode;
    Q_EMIT modeChanged(d->mode);
  }
}

void Task::setAction(const int action) {
  Q_D(Task);
  if (action != d->action) {
    d->action = action;
    Q_EMIT actionChanged(d->action);
  }
}

void Task::setData(const QJsonObject &data) {
  Q_D(Task);
  if (data != d->data) {
    d->data = data;
    Q_EMIT dataChanged(d->data);
  }
}

Task::Task(TaskPrivate *d, QObject *parent) : QObject(parent), d_ptr(d) {}
