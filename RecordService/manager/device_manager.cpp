#include "device_manager.h"
#include <QDebug>
#include <functional>
#include "device_manager_p.h"
#include "model/device_model.h"
#include "service/service_base.h"
#include "websocket/protocol/proto_info.h"
#include "websocket/task/task_reply.h"

DeviceManager::DeviceManager(QObject *parent)
    : Client(new DeviceManagerPrivate(this), parent) {
  Q_D(DeviceManager);
  QObject::connect(
      this, &DeviceManager::serviceChanged, [this, d](ServiceBase *servie) {
        d->info_protocol =
            dynamic_cast<ProtoInfo *>(servie->protocol(ProtoBase::INFO_MODE));
      });

  d->model = new DeviceModel(this);
}

Device *DeviceManager::device(const QString &uuid) const {
  return d_func()->deviceMap.value(uuid, Q_NULLPTR);
}

void DeviceManager::refresh() {
  Q_D(DeviceManager);
  if (d->info_protocol) {
    TaskReply *reply = d->info_protocol->pull();
    if (reply) {
      QObject::connect(reply, &TaskReply::finished, this, [=]() {
        d->updateDeviceList(reply->data());
        reply->deleteLater();
      });
    }
  }
}

DeviceModel *DeviceManager::model() const { return d_func()->model; }

DeviceManager::DeviceManager(DeviceManagerPrivate *d, QObject *parent)
    : Client(d, parent) {}
