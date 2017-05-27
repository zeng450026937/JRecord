#ifndef USER_MODEL_H
#define USER_MODEL_H

#include <QSqlTableModel>

class UserModelPrivate;

class UserModel : public QSqlTableModel
{
    Q_OBJECT
    Q_DISABLE_COPY(UserModel)
    Q_DECLARE_PRIVATE(UserModel)
public:
    explicit UserModel(QSqlTableModel *parent = 0);

    // Define the role names to be used
    enum RoleNames {
        UserIdRole = Qt::UserRole,
        UserTypeRole,
        UserNameRole,
        DeviceTypeRole,
        DeviceNameRole,
        BatteryPercentRole,
        BatteryTimeRole,
        StatusRole,
        VADRole,
        LockedRole,

        RoleCount
    };

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    // return the roles mapping to be used by QML
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void lockUser(const int row, const bool lock);
    Q_INVOKABLE void lockUser(const QString &userId, const bool lock);

Q_SIGNALS:

public Q_SLOTS:

protected:
    UserModel(UserModelPrivate *d, QSqlTableModel *parent = 0);
    QScopedPointer<UserModelPrivate> d_ptr;
};

#endif // USER_MODEL_H
