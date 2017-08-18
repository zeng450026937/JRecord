#include "message_reply.h"
#include <QTimerEvent>
#include "message_reply_p.h"

MessageReplyPrivate::MessageReplyPrivate(MessageReply *q)
    : q_ptr(q), status(MessageReply::Idle), timer(0) {}

MessageReply::MessageReply(QObject *parent)
    : QObject(parent), d_ptr(new MessageReplyPrivate(this)) {
  qRegisterMetaType<MessageReply::Status>();
  Q_D(MessageReply);
  QObject::connect(this, &MessageReply::statusChanged, this,
                   [=](MessageReply::Status status) {
                     switch (status) {
                       case MessageReply::Executing:
                         d->timer = this->startTimer(5000);
                         break;
                       case MessageReply::Completed:
                         this->killTimer(d->timer);
                         Q_EMIT finished();
                         break;
                       case MessageReply::Timeout:
                         this->killTimer(d->timer);
                         Q_EMIT timeout();
                         break;
                       case MessageReply::Idle:
                       case MessageReply::Error:
                       default:
                         break;
                     }
                   });
}

QJsonValue MessageReply::data() const { return d_func()->data; }

MessageReply::Status MessageReply::status() const { return d_func()->status; }

void MessageReply::setData(const QJsonValue &data) {
  Q_D(MessageReply);
  if (data != d->data) {
    d->data = data;
    Q_EMIT dataChanged(d->data);
  }
}

void MessageReply::setStatus(MessageReply::Status status) {
  Q_D(MessageReply);
  if (status != d->status) {
    d->status = status;
    Q_EMIT statusChanged(d->status);
  }
}

MessageReply::MessageReply(MessageReplyPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}

void MessageReply::timerEvent(QTimerEvent *event) {
  Q_D(MessageReply);
  if (event->timerId() == d->timer) {
    this->setStatus(Timeout);
  }
}
