#include "task_request.h"
#include <QDebug>
#include "task_reply.h"
#include "task_request_p.h"

TaskRequest::TaskRequest(QObject *parent)
    : TextMessage(new TaskRequestPrivate(this), parent) {}
// static
void TaskRequest::doDeleteLater(TaskRequest *request) {
  request->deleteLater();
}

void TaskRequest::setReply(TaskReply *reply) {
  Q_D(TaskRequest);
  if (reply) {
    if (d->reply) d->reply->deleteLater();
    d->reply = reply;
  }
}

TaskReply *TaskRequest::reply() {
  Q_D(TaskRequest);
  return d->reply;
}

bool TaskRequest::match(MessagePacket *pkt) {
  if (!pkt) return false;

  TextMessage *msg = dynamic_cast<TextMessage *>(pkt);

  if (msg && msg->command() == this->command()) {
    return true;
  } else {
    return false;
  }
}

TaskRequest::TaskRequest(TaskRequestPrivate *d, QObject *parent)
    : TextMessage(d, parent) {}
