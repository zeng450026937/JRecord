#include "device_manager_p.h"
#include "device/device.h"
#include "model/device_model.h"

DeviceManagerPrivate::DeviceManagerPrivate(DeviceManager *q)
    : ClientPrivate(q), info_protocol(Q_NULLPTR) {}

void DeviceManagerPrivate::updateDevice(const QJsonValue &data) {
  Device *device(Q_NULLPTR);

  if (data.isObject()) {
    QJsonObject dataObject = data.toObject();

    device = deviceMap.value(
        dataObject.value(QLatin1String("deviceUuid")).toString(), Q_NULLPTR);
    if (device) {
      device->fromJson(dataObject);
    } else {
      device = new Device(dataObject, q_ptr);
      device->setService(service);
      deviceMap.insert(device->uuid(), device);
      model->addDevice(device);
    }
  }
}

void DeviceManagerPrivate::updateDeviceList(const QJsonValue &data) {
  foreach (QJsonValue value, data.toArray()) { this->updateDevice(value); }
}
