#include "user_model.h"
#include "user_model_p.h"
#include "sql_initializer.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>


UserModel::UserModel(QSqlTableModel *parent) :
    QSqlTableModel(parent, QSqlDatabase::database()),
    d_ptr(new UserModelPrivate(this))
{
    createUserTable();

    setTable(userTableName);
    setSort(8, Qt::AscendingOrder);
    // Ensures that the model is sorted correctly after submitting a new row.
    setEditStrategy(QSqlTableModel::OnManualSubmit);

    select();

    Q_D(UserModel);

    // Set names to the role name hash container (QHash<int, QByteArray>)
    d->roleNames[UserIdRole] = "userId";
    d->roleNames[UserTypeRole] = "userType";
    d->roleNames[UserNameRole] = "userName";
    d->roleNames[DeviceTypeRole] = "deviceType";
    d->roleNames[DeviceNameRole] = "deviceName";
    d->roleNames[BatteryPercentRole] = "batteryPercent";
    d->roleNames[BatteryTimeRole] = "batteryTime";
    d->roleNames[StatusRole] = "status";
    d->roleNames[VADRole] = "vad";
    d->roleNames[LockedRole] = "locked";
}

QVariant UserModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role < Qt::UserRole)
        return QSqlTableModel::data(index, role);

    const QSqlRecord sqlRecord = record(index.row());
    return sqlRecord.value(role - Qt::UserRole);
}

QHash<int, QByteArray> UserModel::roleNames() const
{
    return d_func()->roleNames;
}

void UserModel::lockUser(const int row, const bool lock)
{
    QSqlRecord newRecord = record(row);
    newRecord.setValue(LockedRole - Qt::UserRole, lock);

    if (!setRecord(row, newRecord)) {
        qWarning() << "Failed to lock user:" << lastError().text();
        return;
    }

    submitAll();
}

void UserModel::lockUser(const QString &userId, const bool lock)
{
    Q_UNUSED(userId);
    Q_UNUSED(lock);
    select();
}

UserModel::UserModel(UserModelPrivate *d, QSqlTableModel *parent) :
    QSqlTableModel(parent),
    d_ptr(d)
{

}
