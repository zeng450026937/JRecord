#include "device_manager.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include "device/device.h"
#include "device_manager_p.h"
#include "model/device_model.h"
#include "service/service_base.h"
#include "websocket/protocol/proto_info.h"

DeviceManager::DeviceManager(QObject *parent)
    : Client(new DeviceManagerPrivate(this), parent) {
  Q_D(DeviceManager);
  QObject::connect(
      this, &DeviceManager::serviceChanged, [this, d](ServiceBase *servie) {
        d->protocol =
            dynamic_cast<ProtoInfo *>(servie->protocol(QStringLiteral("info")));

        QObject::connect(
            d->protocol, &ProtoInfo::actionRecived, this,
            [this, d](const int action, const QJsonValue &data) {
              Device *device(Q_NULLPTR);
              switch (action) {
                case ProtoInfo::getDeviceList:
                  d->model->clearAll();
                  foreach (QJsonValue value, data.toArray()) {
                    device = new Device(value.toVariant().toMap(), this);
                    device->setService(d->service);
                    d->deviceMap.insert(device->uuid(), device);
                    d->model->addDevice(device);
                  }
                  break;
                case ProtoInfo::updateDeviceInfo:
                case ProtoInfo::notifyDeviceInfoChange:
                  device = d->deviceMap.value(
                      data.toObject().value("deviceUuid").toString(),
                      Q_NULLPTR);
                  if (device) {
                    device->fromVariant(data.toObject().toVariantMap());
                  } else {
                    device = new Device(data.toObject().toVariantMap(), this);
                    device->setService(d->service);
                    d->deviceMap.insert(device->uuid(), device);
                    d->model->addDevice(device);
                  }
                  break;
                default:
                  break;
              }
            });
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
    : Client(d, parent) {}
