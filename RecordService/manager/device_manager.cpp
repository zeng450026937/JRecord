#include "device_manager.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include "device/device.h"
#include "device_manager_p.h"
#include "model/device_model.h"
#include "service/service_base.h"
#include "websocket/protocol/proto_info.h"

DeviceManager::DeviceManager(QObject *parent)
    : Client(parent), d_ptr(new DeviceManagerPrivate(this)) {
  Q_D(DeviceManager);
  QObject::connect(
      this, &DeviceManager::serviceChanged, [d](ServiceBase *servie) {
        d->protocol = (ProtoInfo *)servie->protocol(QStringLiteral("info"));
      });

  QObject::connect(
      d->protocol, &ProtoInfo::actionRecived,
      [this, d](ProtoInfo::Actions action, const QJsonValue &data) {

        QJsonArray;
        foreach (QJsonValue value, data.toArray()) {
          Device *device = new Device(value.toVariant().toMap(), this);
          d->deviceMap.insert(device->uuid(), device);
          d->model->add(device);
        }
      });

  d->model = new DeviceModel(this);
}

Device *DeviceManager::device(const QString &uuid) const {
  return d_func()->deviceMap.value(uuid, Q_NULLPTR);
}

void DeviceManager::refresh() {
  Q_D(DeviceManager);
  if (d->protocol) d->protocol->pull();
}

DeviceModel *DeviceManager::model() const { return d_func()->model; }

DeviceManager::DeviceManager(DeviceManagerPrivate *d, QObject *parent)
    : Client(parent), d_ptr(d) {}
