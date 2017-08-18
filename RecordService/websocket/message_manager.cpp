#include "message_manager.h"
#include <QDebug>
#include "binarymessage.h"
#include "message_manager_p.h"
#include "message_reply.h"
#include "process_thread.h"
#include "textmessage.h"
#include "transport_thread.h"

MessageManagerPrivate::MessageManagerPrivate(MessageManager *q)
    : q_ptr(q), transportThread(Q_NULLPTR), processThread(Q_NULLPTR) {}

MessageManager::MessageManager(QObject *parent)
    : QObject(parent), d_ptr(new MessageManagerPrivate(this)) {}

MessageReply *MessageManager::postRequest(QSharedPointer<MessagePacket> msg) {
  Q_D(MessageManager);

  MessageReply *reply = new MessageReply(this);
  msg->setReply(reply);

  d->transportThread->pushMessage(msg);

  return reply;
}

void MessageManager::postMessage(QSharedPointer<MessagePacket> msg) {
  Q_D(MessageManager);
  d->transportThread->pushMessage(msg);
}

TransportThread *MessageManager::transportThread() const {
  return d_func()->transportThread;
}

ProcessThread *MessageManager::processThread() const {
  return d_func()->processThread;
}

void MessageManager::setTransportThread(TransportThread *transportThread) {
  Q_D(MessageManager);
  if (d->transportThread != transportThread) {
    if (d->transportThread) this->disconnect(d->transportThread);
    d->transportThread = transportThread;

    this->connect(d->transportThread,
                  SIGNAL(beforeTransport(QSharedPointer<MessagePacket>)),
                  SLOT(q_beforeTransport(QSharedPointer<MessagePacket>)),
                  Qt::DirectConnection);
    this->connect(d->transportThread,
                  SIGNAL(afterTransport(QSharedPointer<MessagePacket>)),
                  SLOT(q_afterTransport(QSharedPointer<MessagePacket>)),
                  Qt::DirectConnection);

    Q_EMIT transportThreadChanged(d->transportThread);
  }
}

void MessageManager::setProcessThread(ProcessThread *processThread) {
  Q_D(MessageManager);
  if (d->processThread != processThread) {
    if (d->processThread) this->disconnect(d->processThread);
    d->processThread = processThread;

    this->connect(d->processThread,
                  SIGNAL(beforeProcess(QSharedPointer<MessagePacket>)),
                  SLOT(q_beforeProcess(QSharedPointer<MessagePacket>)),
                  Qt::DirectConnection);
    this->connect(d->processThread,
                  SIGNAL(afterProcess(QSharedPointer<MessagePacket>)),
                  SLOT(q_afterProcess(QSharedPointer<MessagePacket>)),
                  Qt::DirectConnection);

    Q_EMIT processThreadChanged(d->processThread);
  }
}

MessageManager::MessageManager(MessageManagerPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}

void MessageManagerPrivate::q_beforeTransport(
    QSharedPointer<MessagePacket> pkt) {
  MessageReply *reply = pkt->reply();
  if (reply) {
    reply->setStatus(MessageReply::Executing);
    requestQueue.append(pkt);
  }
}
void MessageManagerPrivate::q_afterTransport(
    QSharedPointer<MessagePacket> pkt) {
  Q_UNUSED(pkt);
}

void MessageManagerPrivate::q_beforeProcess(QSharedPointer<MessagePacket> pkt) {
  Q_UNUSED(pkt);
}
void MessageManagerPrivate::q_afterProcess(QSharedPointer<MessagePacket> pkt) {
  if (requestQueue.count() > 0 && requestQueue.first()->equals(pkt.data())) {
    QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
    if (msg) {
      MessageReply *reply = requestQueue.takeFirst()->reply();
      if (reply) {
        reply->setData(msg->data());
        reply->setStatus(MessageReply::Completed);
        qDebug() << "request processed.";
      }
    }
  } else {
    qDebug() << "it's a notification from server or not supportted by current "
                "protocols.";
  }
}

#include "moc_message_manager.cpp"
