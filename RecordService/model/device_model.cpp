#include "device_model.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

static const char *deviceTableName = "Devices";

static void createTable()
{
    if (QSqlDatabase::database().tables().contains(deviceTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Devices' ("
        "'mac' TEXT UNIQUE NOT NULL,"
        "'seleted' INTEGER DEFAULT '0',"
        "'type' TEXT NOT NULL,"
        "'status' TEXT NOT NULL,"
        "'vad' TEXT NOT NULL,"
        "'name' TEXT NOT NULL,"
        "'battery_percent' INTEGER DEFAULT '0',"
        "'battery_time' INTEGER DEFAULT '0',"
        "'owner' TEXT NOT NULL,"
        "PRIMARY KEY(mac),"
        "FOREIGN KEY('type') REFERENCES DeviceType ( type ),"
        "FOREIGN KEY('status') REFERENCES DeviceStatus ( status ),"
        "FOREIGN KEY('vad') REFERENCES DeviceVAD ( vad ),"
        "FOREIGN KEY('owner') REFERENCES Accounts ( account )"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.exec("INSERT INTO Conversations VALUES('Me', 'Ernest Hemingway', '2016-01-07T14:36:06', 'Hello!')");
    query.exec("INSERT INTO Conversations VALUES('Ernest Hemingway', 'Me', '2016-01-07T14:36:16', 'Good afternoon.')");
    query.exec("INSERT INTO Conversations VALUES('Me', 'Albert Einstein', '2016-01-01T11:24:53', 'Hi!')");
    query.exec("INSERT INTO Conversations VALUES('Albert Einstein', 'Me', '2016-01-07T14:36:16', 'Good morning.')");
    query.exec("INSERT INTO Conversations VALUES('Hans Gude', 'Me', '2015-11-20T06:30:02', 'God morgen. Har du fått mitt maleri?')");
    query.exec("INSERT INTO Conversations VALUES('Me', 'Hans Gude', '2015-11-20T08:21:03', 'God morgen, Hans. Ja, det er veldig fint. Tusen takk! "
               "Hvor mange timer har du brukt på den?')");
}

DeviceModel::DeviceModel(QObject *parent)
    : QSqlTableModel(parent)
{
    createTable();

    setTable(deviceTableName);
    setSort(3, Qt::DescendingOrder);
    // Ensures that the model is sorted correctly after submitting a new row.
    setEditStrategy(QSqlTableModel::OnManualSubmit);

    // Set names to the role name hash container (QHash<int, QByteArray>)
    m_roleNames[MacRole] = "mac";
    m_roleNames[SeletedRole] = "selected";
    m_roleNames[TypeNameRole] = "type";
    m_roleNames[StatusRole] = "status";
    m_roleNames[VADRole] = "vad";
    m_roleNames[BatteryPercentRole] = "batteryPercent";
    m_roleNames[BatteryTimeRole] = "batteryTime";
    m_roleNames[OwnerRole] = "owner";
}

QString DeviceModel::device() const
{
    return m_device;
}
void DeviceModel::setAccount(const QString &device)
{
    if (device == m_device)
        return;

    m_device = device;

    const QString filterString = QString::fromLatin1("mac = '%1'").arg(m_device);
    setFilter(filterString);
    select();

    emit deviceChanged();
}

void DeviceModel::selectDevice(const int &row, const bool &selected)
{
    QSqlRecord newRecord = record(row);
    newRecord.setValue(QString(m_roleNames[SeletedRole]), selected);

    if (!setRecord(row, newRecord)) {
        qWarning() << "Failed to select device:" << lastError().text();
        return;
    }

    submitAll();
}

QVariant DeviceModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role < Qt::UserRole)
        return QSqlTableModel::data(index, role);

    const QSqlRecord sqlRecord = record(index.row());
    return sqlRecord.value(role - Qt::UserRole);
}

QHash<int, QByteArray> DeviceModel::roleNames() const
{
    return m_roleNames;
}
