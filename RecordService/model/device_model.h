#ifndef DEVICEMODEL_H
#define DEVICEMODEL_H

#include <QSqlRelationalTableModel>

class DeviceModel : public QSqlRelationalTableModel
{
    Q_OBJECT
    Q_PROPERTY(QString device READ device WRITE setDevice NOTIFY deviceChanged)

public:
    explicit UserEntryModel(QObject *parent = 0);

    QString device() const;
    void setDevice(const QString &device);

    Q_INVOKABLE void selectDevice(const int &row, const bool &selected);

    // Define the role names to be used
    enum RoleNames {
        MacRole = Qt::UserRole,
        SeletedRole,
        TypeNameRole,
        StatusRole,
        VADRole,
        BatteryPercentRole,
        BatteryTimeRole,
        OwnerRole,

        RoleCount
    };

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    // return the roles mapping to be used by QML
    QHash<int, QByteArray> roleNames() const override;

signals:
    void deviceChanged();

private:
    QString device;
    QHash<int, QByteArray> m_roleNames;
};

#endif // DEVICEMODEL_H
