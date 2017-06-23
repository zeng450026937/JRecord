#ifndef DEVICE_MANAGER_P_H
#define DEVICE_MANAGER_P_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
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
  ProtoInfo* info_protocol;
  DeviceModel* model;

  void updateDevice(const QJsonObject& data);
};

#endif  // DEVICE_MANAGER_P_H
