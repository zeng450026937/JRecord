#ifndef DEVICE_MODEL_P_H
#define DEVICE_MODEL_P_H

#include <QHash>
#include <QObject>

class DeviceModel;

class DeviceModelPrivate {
  Q_DISABLE_COPY(DeviceModelPrivate)
  Q_DECLARE_PUBLIC(DeviceModel)
 public:
  DeviceModelPrivate(DeviceModel *q);

  DeviceModel *q_ptr;
  QHash<int, QByteArray> roleNames;
};

#endif  // DEVICE_MODEL_P_H
