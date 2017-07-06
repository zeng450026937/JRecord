#include "service_base_p.h"
#include <QThread>
#include <QUuid>
#include "service/service_base.h"
#include "websocket/message_queue.h"
#include "websocket/message_socket.h"
#include "websocket/process_thread.h"
#include "websocket/transport_thread.h"

ServiceBasePrivate::ServiceBasePrivate(ServiceBase *q)
    : q_ptr(q),
      active(false),
      device(Q_NULLPTR),
      taskManager(Q_NULLPTR),
      conferenceManager(Q_NULLPTR),
      deviceManager(Q_NULLPTR),
      socket_thread(new QThread),
      socket(new MessageSocket),
      transport_thread(new TransportThread),
      process_thread(new ProcessThread),
      transport_queue(new MessageQueue),
      process_queue(new MessageQueue) {
  uuid = QUuid::createUuid().toString();
  uuid.replace(QStringLiteral("-"), "");
  uuid.replace(QStringLiteral("{"), "");
  uuid.replace(QStringLiteral("}"), "");

  socket->moveToThread(socket_thread);

  transport_queue->moveToThread(socket_thread);
  process_queue->moveToThread(socket_thread);

  transport_thread->moveToThread(socket_thread);
  process_thread->moveToThread(socket_thread);

  transport_thread->setSocket(socket);
  process_thread->setSocket(socket);

  transport_thread->setQueue(transport_queue);
  process_thread->setQueue(process_queue);

  socket_thread->start();

  QObject::connect(socket, &MessageSocket::activeChanged, q_ptr,
                   [this](const bool active) {
                     Q_Q(ServiceBase);
                     if (active) {
                       this->status = ServiceBase::Open;
                       this->active = true;
                     } else {
                       this->status = ServiceBase::Closed;
                       this->active = false;
                     }
                     Q_EMIT q->statusChanged(status);
                     Q_EMIT q->activeChanged(active);
                   });

  QObject::connect(socket, &MessageSocket::errorChanged, q_ptr,
                   [this](const QString error) {
                     Q_Q(ServiceBase);
                     if (errorString != error) {
                       errorString = error;
                       Q_EMIT q->errorStringChanged(errorString);
                     }
                   });

  QObject::connect(socket, &MessageSocket::activeChanged, transport_queue,
                   &MessageQueue::setActive);
  QObject::connect(socket, &MessageSocket::activeChanged, process_queue,
                   &MessageQueue::setActive);

  QObject::connect(transport_queue, &MessageQueue::activeChanged,
                   transport_thread, &TransportThread::setActive);
  QObject::connect(process_queue, &MessageQueue::activeChanged, process_thread,
                   &ProcessThread::setActive);
}

ServiceBasePrivate::~ServiceBasePrivate() {
  socket_thread->quit();
  socket_thread->wait(3000);

  socket_thread->deleteLater();

  transport_queue->deleteLater();
  process_queue->deleteLater();
  transport_thread->deleteLater();
  process_thread->deleteLater();
  socket->deleteLater();
}
