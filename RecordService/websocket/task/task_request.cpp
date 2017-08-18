#include "task_request.h"
#include "task_reply.h"
#include "task_request_p.h"

TaskRequest::TaskRequest(QObject *parent)
    : QObject(parent), d_ptr(new TaskRequestPrivate(this)) {}

// static
void TaskRequest::doDeleteLater(TaskRequest *request) {
  request->deleteLater();
}

TaskReply *TaskRequest::reply() const { return d_func()->reply; }

MessagePacket *TaskRequest::message() const { return d_func()->message; }

void TaskRequest::setReply(TaskReply *reply) {
  Q_D(TaskRequest);
  if (reply) {
    d->reply = reply;
    Q_EMIT replyChanged(d->reply);
  }
}

void TaskRequest::setMessage(MessagePacket *msg) {
  Q_D(TaskRequest);
  if (msg) {
    d->message = msg;
    Q_EMIT messageChanged(d->message);
  }
}

TaskRequest::TaskRequest(TaskRequestPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
