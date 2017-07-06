#include "task_manager.h"
#include <QDebug>
#include "task_manager_p.h"
#include "task_reply.h"
#include "task_request.h"
#include "websocket/binarymessage.h"
#include "websocket/process_thread.h"
#include "websocket/textmessage.h"
#include "websocket/transport_thread.h"
#include "websocket/transport_thread.h"

TaskManager::TaskManager(QObject *parent)
    : QObject(parent), d_ptr(new TaskManagerPrivate(this)) {}

TaskReply *TaskManager::post(QSharedPointer<TaskRequest> request) {
  Q_D(TaskManager);

  TaskReply *reply = new TaskReply(this);

  request->setReply(reply);

  QMutexLocker locker(&d->mutex);
  d->requestQueue.append(request);

  d->transportThread->pushMessage(request);

  return reply;
}

TransportThread *TaskManager::transportThread() const {
  return d_func()->transportThread;
}

ProcessThread *TaskManager::processThread() const {
  return d_func()->processThread;
}

void TaskManager::setTransportThread(TransportThread *transportThread) {
  Q_D(TaskManager);
  if (d->transportThread != transportThread) {
    this->disconnect(d->transportThread);
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

void TaskManager::setProcessThread(ProcessThread *processThread) {
  Q_D(TaskManager);
  if (d->processThread != processThread) {
    this->disconnect(d->processThread);
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

TaskManager::TaskManager(TaskManagerPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}

void TaskManagerPrivate::q_beforeTransport(QSharedPointer<MessagePacket> pkt) {
  Q_UNUSED(pkt);
}
void TaskManagerPrivate::q_afterTransport(QSharedPointer<MessagePacket> pkt) {
  Q_UNUSED(pkt);
}

void TaskManagerPrivate::q_beforeProcess(QSharedPointer<MessagePacket> pkt) {
  QMutexLocker locker(&mutex);
  if (requestQueue.count() > 0) {
    requestQueue.first()->match(pkt.data());
  }
}
void TaskManagerPrivate::q_afterProcess(QSharedPointer<MessagePacket> pkt) {
  QMutexLocker locker(&mutex);
  if (!pkt->notification() && requestQueue.count() > 0) {
    requestQueue.takeFirst()->processed(pkt.data());
  } else {
    qDebug() << "it should be a notification from server.";
  }
}

#include "moc_task_manager.cpp"
