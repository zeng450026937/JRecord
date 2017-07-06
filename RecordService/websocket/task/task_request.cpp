#include "task_request.h"
#include <QDebug>
#include "task_reply.h"
#include "task_request_p.h"

TaskRequest::TaskRequest(QObject *parent)
    : TextMessage(new TaskRequestPrivate(this), parent) {}

void TaskRequest::setReply(TaskReply *reply) {
  Q_D(TaskRequest);
  if (reply) {
    d->reply = reply;
  }
}

void TaskRequest::match(MessagePacket *pkt) {
  if (!pkt) return;

  TextMessage *msg = dynamic_cast<TextMessage *>(pkt);

  if (msg && msg->command() == this->command()) {
    pkt->setNotification(false);
  } else {
    pkt->setNotification(true);
  }
}

void TaskRequest::processed(MessagePacket *pkt) {
  Q_D(TaskRequest);
  TextMessage *msg = dynamic_cast<TextMessage *>(pkt);
  if (msg && d->reply) {
    d->reply->setData(msg->data());
    Q_EMIT d->reply->finished();
  }
}

TaskRequest::TaskRequest(TaskRequestPrivate *d, QObject *parent)
    : TextMessage(d, parent) {}
