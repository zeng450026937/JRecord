#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include "client/client.h"

class Device;
class DeviceModel;
class DeviceManagerPrivate;

class DeviceManager : public Client {
  Q_OBJECT
  Q_DISABLE_COPY(DeviceManager)
  Q_DECLARE_PRIVATE(DeviceManager)

 public:
  explicit DeviceManager(QObject *parent = 0);

  Q_INVOKABLE Device *device(const QString &uuid) const;

  Q_INVOKABLE void refresh();
  Q_INVOKABLE DeviceModel *model() const;

 public Q_SLOTS:

 Q_SIGNALS:
  void deviceConnected(const Device *device);

 protected:
  DeviceManager(DeviceManagerPrivate *d, QObject *parent = 0);
  QScopedPointer<DeviceManagerPrivate> d_ptr;
};

#endif  // DEVICE_MANAGER_H
