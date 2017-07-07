#include "task_reply.h"
#include <QTimerEvent>
#include "task_reply_p.h"

TaskReply::TaskReply(QObject *parent)
    : QObject(parent), d_ptr(new TaskReplyPrivate(this)) {
  qRegisterMetaType<TaskReply::Status>();
  Q_D(TaskReply);
  QObject::connect(this, &TaskReply::statusChanged, this,
                   [=](TaskReply::Status status) {
                     switch (status) {
                       case TaskReply::Executing:
                         d->timer = this->startTimer(5000);
                         break;
                       case TaskReply::Completed:
                         this->killTimer(d->timer);
                         Q_EMIT finished();
                         break;
                       case TaskReply::Timeout:
                         this->killTimer(d->timer);
                         Q_EMIT timeout();
                         break;
                       case TaskReply::Idle:
                       case TaskReply::Error:
                       default:
                         break;
                     }
                   });
}

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

void TaskReply::timerEvent(QTimerEvent *event) {
  Q_D(TaskReply);
  if (event->timerId() == d->timer) {
    this->setStatus(Timeout);
  }
}
