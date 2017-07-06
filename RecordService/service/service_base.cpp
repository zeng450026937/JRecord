#include "service_base.h"
#include "device/device.h"
#include "manager/conference_manager.h"
#include "manager/device_manager.h"
#include "service/service_base_p.h"
#include "user/user.h"
#include "websocket/message_queue.h"
#include "websocket/message_socket.h"
#include "websocket/process_thread.h"
#include "websocket/protocol/proto_base.h"
#include "websocket/protocol/proto_base_p.h"
#include "websocket/protocol/proto_binary.h"
#include "websocket/protocol/proto_conf.h"
#include "websocket/protocol/proto_info.h"
#include "websocket/protocol/proto_mobile.h"
#include "websocket/protocol/proto_person.h"
#include "websocket/task/task_manager.h"
#include "websocket/task/task_manager.h"
#include "websocket/textmessage.h"
#include "websocket/transport_thread.h"

ServiceBase::ServiceBase(QObject *parent)
    : QObject(parent), d_ptr(new ServiceBasePrivate(this)) {
  Q_D(ServiceBase);

  d->taskManager = new TaskManager(this);
  d->taskManager->setTransportThread(d->transport_thread);
  d->taskManager->setProcessThread(d->process_thread);

  d->process_thread->setProtocols(&d->protocols);
  d->transport_thread->setProtocols(&d->protocols);

  this->registerProtocol(new ProtoBinary(this));
  this->registerProtocol(new ProtoInfo(this));
  this->registerProtocol(new ProtoConf(this));
  this->registerProtocol(new ProtoPerson(this));
  this->registerProtocol(new ProtoMobile(this));

  d->deviceManager = new DeviceManager(this);
  d->deviceManager->setService(this);
  d->conferenceManager = new ConferenceManager(this);
  d->conferenceManager->setService(this);
}

ServiceBase::~ServiceBase() {
  Q_D(ServiceBase);
  this->setActive(false);

  d->protocols.clear();
}

bool ServiceBase::active() const { return d_func()->active; }

QString ServiceBase::errorString() const { return d_func()->errorString; }

QUrl ServiceBase::url() const { return d_func()->url; }

Device *ServiceBase::device() const { return d_func()->device; }

void ServiceBase::registerProtocol(ProtoBase *protocol) {
  Q_D(ServiceBase);
  this->removeProtocol(protocol->mode());
  protocol->d_func()->taskManager = d->taskManager;
  d->protocols.insert(protocol->mode(), protocol);
  Q_EMIT protocolChanged(protocol->mode());
}

void ServiceBase::removeProtocol(const QString &name) {
  Q_D(ServiceBase);
  ProtoBase *protocol = d->protocols.value(name, Q_NULLPTR);
  if (protocol) protocol->deleteLater();
  d->protocols.remove(name);
}

ProtoBase *ServiceBase::protocol(const QString &name) {
  return d_func()->protocols.value(name, Q_NULLPTR);
}

DeviceManager *ServiceBase::deviceManager() const {
  return d_func()->deviceManager;
}

ConferenceManager *ServiceBase::conferenceManager() const {
  return d_func()->conferenceManager;
}

void ServiceBase::setActive(bool active) {
  Q_D(ServiceBase);
  if (active != d->active) {
    if (active) {
      d->status = ServiceBase::Connecting;
      Q_EMIT statusChanged(d->status);

      QScopedPointer<TextMessage> auth(new TextMessage);
      auth->setMode(QStringLiteral("auth"));
      auth->setAction(QStringLiteral("login"));
      auth->setData(d->device->toJson());

      QNetworkRequest request(d->url);
      request.setRawHeader("Accept", "application/json");
      request.setHeader(QNetworkRequest::ContentTypeHeader,
                        QVariant("application/json"));
      request.setRawHeader("Authorization", auth->encode().toUtf8());

      d->socket->setRequest(request);
    } else {
      d->status = ServiceBase::Closing;
      Q_EMIT statusChanged(d->status);
    }

    QMetaObject::invokeMethod(d->socket, "setActive", Qt::QueuedConnection,
                              QGenericReturnArgument(Q_NULLPTR),
                              Q_ARG(const bool, active));
  }
}

void ServiceBase::setUrl(const QUrl &url) {
  Q_D(ServiceBase);
  if (url != d->url) {
    d->url = url;
    Q_EMIT urlChanged(d->url);
  }
}

void ServiceBase::setDevice(Device *device) {
  Q_D(ServiceBase);
  if (device != d->device) {
    d->device = device;
    d->device->setUuid(d->uuid);
    Q_EMIT deviceChanged(d->device);
  }
}

ServiceBase::ServiceBase(ServiceBasePrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
