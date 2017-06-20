#ifndef DEVICE_MODEL_H
#define DEVICE_MODEL_H

#include <QSqlTableModel>

class Device;
class DeviceModelPrivate;

class DeviceModel : public QSqlTableModel {
  Q_OBJECT
  Q_DISABLE_COPY(DeviceModel)
  Q_DECLARE_PRIVATE(DeviceModel)
 public:
  explicit DeviceModel(QObject *parent = 0);

  // Define the role names to be used
  enum RoleNames {
    UuidRole = Qt::UserRole,
    TypeRole,
    NameRole,
    PercentRole,
    TimeRole,
    StatusRole,
    VadRole,
    LockRole,
    RoleCount
  };

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  // return the roles mapping to be used by QML
  QHash<int, QByteArray> roleNames() const override;

  Q_INVOKABLE void addDevice(Device *device);
  Q_INVOKABLE void clearAll();

 Q_SIGNALS:

 public Q_SLOTS:

 protected:
  DeviceModel(DeviceModelPrivate *d, QSqlTableModel *parent = 0);
  QScopedPointer<DeviceModelPrivate> d_ptr;
};

#endif  // DEVICE_MODEL_H
