#include "device_manager.h"
#include <QDebug>
#include <functional>
#include "device_manager_p.h"
#include "model/device_model.h"
#include "service/service_base.h"
#include "websocket/protocol/proto_info.h"

DeviceManager::DeviceManager(QObject *parent)
    : Client(new DeviceManagerPrivate(this), parent) {
  Q_D(DeviceManager);
  QObject::connect(
      this, &DeviceManager::serviceChanged, [this, d](ServiceBase *servie) {
        d->info_protocol =
            dynamic_cast<ProtoInfo *>(servie->protocol(ProtoBase::INFO_MODE));

        QObject::connect(d->info_protocol, &ProtoInfo::actionRecived, this,
                         [this, d](const int action, const QJsonValue &data) {
                           switch (action) {
                             //                             case
                             //                             ProtoInfo::getDeviceList:
                             //                               foreach
                             //                               (QJsonValue value,
                             //                               data.toArray()) {
                             //                                 d->updateDevice(value.toObject());
                             //                               }
                             //                               break;
                             case ProtoInfo::updateDeviceInfo:
                               d->updateDevice(data.toObject());
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
  if (d->info_protocol) d->info_protocol->pull();
  if (d->info_protocol)
    d->info_protocol->pull(std::bind(&DeviceManagerPrivate::updateDeviceList, d,
                                     std::placeholders::_1));
}

DeviceModel *DeviceManager::model() const { return d_func()->model; }

DeviceManager::DeviceManager(DeviceManagerPrivate *d, QObject *parent)
    : Client(d, parent) {}
