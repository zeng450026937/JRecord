#include "message_thread.h"
#include "message_queue.h"
#include "message_thread_p.h"
#include "websocket/protocol/proto_base.h"

MessageThread::MessageThread(QObject *parent)
    : QThread(parent), d_ptr(new MessageThreadPrivate(this)) {
  QObject::connect(this, &MessageThread::started, [=]() {
    Q_D(MessageThread);
    d->active = true;
    Q_EMIT activeChanged(d->active);
  });
  QObject::connect(this, &MessageThread::finished, [=]() {
    Q_D(MessageThread);
    d->active = false;
    Q_EMIT activeChanged(d->active);
  });
}

MessageThread::~MessageThread() { this->setActive(false); }

void MessageThread::setProtocols(QHash<QString, ProtoBase *> *protocols) {
  Q_D(MessageThread);
  d->protocols = protocols;
}

bool MessageThread::active() const { return d_func()->active; }

MessageQueue *MessageThread::queue() const { return d_func()->queue; }

MessageSocket *MessageThread::socket() const { return d_func()->socket; }

void MessageThread::setQueue(MessageQueue *queue) {
  Q_D(MessageThread);
  if (queue != d->queue) {
    d->queue = queue;
    Q_EMIT queueChanged(d->queue);
  }
}

void MessageThread::setSocket(MessageSocket *socket) {
  Q_D(MessageThread);
  if (socket != d->socket) {
    d->socket = socket;
    Q_EMIT socketChanged(d->socket);
  }
}

void MessageThread::setActive(bool active) {
  Q_D(MessageThread);
  if (active != d->active) {
    if (active)
      this->start();
    else {
      this->quit();
      this->wait(3000);
    }
  }
}

void MessageThread::pushMessage(MessagePacket *message) {
  Q_D(MessageThread);
  if (d->queue) {
    d->queue->push(QSharedPointer<MessagePacket>(message));
  }
}

MessageThread::MessageThread(MessageThreadPrivate *d, QObject *parent)
    : QThread(parent), d_ptr(d) {}
