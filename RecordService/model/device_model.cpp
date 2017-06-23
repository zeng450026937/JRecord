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
  d->roleNames[TypeRole] = "type";
  d->roleNames[NameRole] = "name";
  d->roleNames[PercentRole] = "percent";
  d->roleNames[TimeRole] = "time";
  d->roleNames[StatusRole] = "status";
  d->roleNames[VadRole] = "vad";
  d->roleNames[LockRole] = "lock";
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

void DeviceModel::addDevice(Device *device) {
  QSqlRecord newRecord = this->record();
  newRecord.setValue(UuidRole - Qt::UserRole, device->uuid());
  newRecord.setValue(TypeRole - Qt::UserRole, device->type());
  newRecord.setValue(NameRole - Qt::UserRole, device->name());
  newRecord.setValue(PercentRole - Qt::UserRole, device->percent());
  newRecord.setValue(TimeRole - Qt::UserRole, device->time());
  newRecord.setValue(StatusRole - Qt::UserRole, device->status());
  newRecord.setValue(VadRole - Qt::UserRole, device->vad());
  newRecord.setValue(LockRole - Qt::UserRole, device->lock());

  this->insertRecord(-1, newRecord);
}

DeviceModel::DeviceModel(DeviceModelPrivate *d, QSqlTableModel *parent)
    : QSqlTableModel(parent), d_ptr(d) {}
