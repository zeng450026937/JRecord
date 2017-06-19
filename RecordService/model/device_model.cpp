#include "device_model.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include "device/device.h"
#include "device_model_p.h"
#include "sql_initializer.h"

DeviceModel::DeviceModel(QObject *parent)
    : QSqlTableModel(parent, QSqlDatabase::database()),
      d_ptr(new DeviceModelPrivate(this)) {
  createDeviceTable();

  setTable(deviceTableName);
  // setSort(8, Qt::AscendingOrder);
  // Ensures that the model is sorted correctly after submitting a new row.
  setEditStrategy(QSqlTableModel::OnManualSubmit);

  select();

  Q_D(DeviceModel);

  // Set names to the role name hash container (QHash<int, QByteArray>)
  d->roleNames[UuidRole] = "uuid";
}

QVariant DeviceModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) return QVariant();

  if (role < Qt::UserRole) return QSqlTableModel::data(index, role);

  const QSqlRecord sqlRecord = record(index.row());
  return sqlRecord.value(role - Qt::UserRole);
}

QHash<int, QByteArray> DeviceModel::roleNames() const {
  return d_func()->roleNames;
}

void DeviceModel::add(Device *device) {
  QSqlRecord deviceRecord;
  deviceRecord.setValue(UuidRole - Qt::UserRole, device->uuid());
  this->insertRecord(-1, deviceRecord);
  this->submitAll();
}

DeviceModel::DeviceModel(DeviceModelPrivate *d, QSqlTableModel *parent)
    : QSqlTableModel(parent), d_ptr(d) {}
