#ifndef DEVICE_MANAGER_P_H
#define DEVICE_MANAGER_P_H

#include <QMap>
#include "client/client_p.h"
#include "manager/device_manager.h"

class ProtoInfo;

class DeviceManagerPrivate : public ClientPrivate {
  Q_DISABLE_COPY(DeviceManagerPrivate)
  Q_DECLARE_PUBLIC(DeviceManager)
 public:
  DeviceManagerPrivate(DeviceManager* q);

  QMap<QString, Device*> deviceMap;
  ProtoInfo* protocol;
  DeviceModel* model;
};

#endif  // DEVICE_MANAGER_P_H
