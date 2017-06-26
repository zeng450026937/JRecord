#include "device_manager_p.h"
#include "device/device.h"
#include "model/device_model.h"

DeviceManagerPrivate::DeviceManagerPrivate(DeviceManager *q)
    : ClientPrivate(q), info_protocol(Q_NULLPTR) {}

void DeviceManagerPrivate::updateDevice(const QJsonObject &data) {
  Device *device(Q_NULLPTR);

  device = deviceMap.value(data.value(QLatin1String("deviceUuid")).toString(),
                           Q_NULLPTR);
  if (device) {
    device->fromJson(data);
  } else {
    device = new Device(data, q_ptr);
    device->setService(service);
    deviceMap.insert(device->uuid(), device);
    model->addDevice(device);
  }
}
