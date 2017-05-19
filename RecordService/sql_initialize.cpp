#include "sql_initialize.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>


void SqlInitialize::connectToDatabase()
{
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.isValid()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        if (!database.isValid())
            qFatal("Cannot add database: %s", qPrintable(database.lastError().text()));
    }

    const QDir writeDir = QCoreApplication::applicationDirPath();
    if (!writeDir.mkpath("."))
        qFatal("Failed to create writable directory at %s", qPrintable(writeDir.absolutePath()));

    // Ensure that we have a writable location on all devices.
    const QString fileName = writeDir.absolutePath() + "/record-database.sqlite3";
    // When using the SQLite driver, open() will create the SQLite database if it doesn't exist.
    database.setDatabaseName(fileName);
    if (!database.open()) {
        qFatal("Cannot open database: %s", qPrintable(database.lastError().text()));
        QFile::remove(fileName);
    }
}

void SqlInitialize::createAccountTypeTable()
{
    if (QSqlDatabase::database().tables().contains(accountTypeTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'AccountType' ("
        "   'type' TEXT NOT NULL,"
        "   PRIMARY KEY(type)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    accountTypeList << "ND";

    query.prepare("INSERT INTO AccountType VALUES (?)");

    query.execBatch();
}
void SqlInitialize::createAccountStatusTable()
{
    if (QSqlDatabase::database().tables().contains(accountStatusTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'AccountStatus' ("
        "   'status' TEXT NOT NULL,"
        "   PRIMARY KEY(status)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    accountStatusList << "online" << "offline" << "busy" << "away" << "dnd";

    query.prepare("INSERT INTO AccountStatus VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");

    query.exec("INSERT INTO AccountStatus VALUES('online')");
    query.exec("INSERT INTO AccountStatus VALUES('offline')");
    query.exec("INSERT INTO AccountStatus VALUES('busy')");
    query.exec("INSERT INTO AccountStatus VALUES('away')");
    query.exec("INSERT INTO AccountStatus VALUES('dnd')");//dnd = do not disturb
}
void SqlInitialize::createAccountsTable()
{
    if (QSqlDatabase::database().tables().contains(accountsTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Accounts' ("
        "   'account' TEXT NOT NULL,"
        "   'password' TEXT DEFAULT '',"
        "   'display' TEXT DEFAULT 'undefined',"
        "   'type' TEXT DEFAULT 'ND',"
        "   'status' TEXT DEFAULT 'online',"
        "   PRIMARY KEY(account),"
        "   FOREIGN KEY(type) REFERENCES AccountType(type),"
        "   FOREIGN KEY(status) REFERENCES AccountStatus(status)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.prepare("INSERT INTO Accounts VALUES (?, ?, ?, ?, ?)");

    QVariantList accounts;
    QVariantList passwords;
    QVariantList displays;
    QVariantList types;
    QVariantList statuss;

    for(int i : 15){
        accounts << QString("account %1").arg(i);
        passwords << QString("password %1").arg(i);
        displays << QString("display %1").arg(i);
        types << QString("ND");
        statuss << QString("online");
    }

    query.addBindValue( accounts );
    query.addBindValue( passwords );
    query.addBindValue( displays );
    query.addBindValue( types );
    query.addBindValue( statuss );

    if(!query.execBatch()){
        qDebug()<<query.executedQuery();
        qDebug()<<query.lastError();
        return;
    }
}

void SqlInitialize::createDeviceTypeTable()
{
    if (QSqlDatabase::database().tables().contains(deviceTypeTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'DeviceType' ("
        "   'type' TEXT NOT NULL,"
        "   PRIMARY KEY(type)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.exec("INSERT INTO DeviceType VALUES('PC')");
    query.exec("INSERT INTO DeviceType VALUES('ANDROID')");
    query.exec("INSERT INTO DeviceType VALUES('IOS')");
}
void SqlInitialize::createDeviceStatusTable()
{
    if (QSqlDatabase::database().tables().contains(deviceStatusTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'DeviceStatus' ("
        "   'status' TEXT NOT NULL,"
        "   PRIMARY KEY(status)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.exec("INSERT INTO DeviceStatus VALUES('idle')");
    query.exec("INSERT INTO DeviceStatus VALUES('recording')");
    query.exec("INSERT INTO DeviceStatus VALUES('busy')");
    query.exec("INSERT INTO DeviceStatus VALUES('background')");
    query.exec("INSERT INTO DeviceStatus VALUES('low power')");
    query.exec("INSERT INTO DeviceStatus VALUES('dnd')");//dnd = do not disturb
}
void SqlInitialize::createDeviceVadTable()
{
    if (QSqlDatabase::database().tables().contains(deviceVadTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'DeviceVAD' ("
        "   'vad' TEXT NOT NULL,"
        "   PRIMARY KEY(vad)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.exec("INSERT INTO DeviceVAD VALUES('good')");
    query.exec("INSERT INTO DeviceVAD VALUES('noise')");
    query.exec("INSERT INTO DeviceVAD VALUES('bad')");
    query.exec("INSERT INTO DeviceVAD VALUES('no voice')");
}
void SqlInitialize::createDevicesTable()
{
    if (QSqlDatabase::database().tables().contains(devicesTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Devices' ("
        "   'mac' TEXT NOT NULL,"
        "   'seleted' INTEGER DEFAULT '0',"
        "   'type' TEXT NOT NULL,"
        "   'status' TEXT NOT NULL,"
        "   'vad' TEXT NOT NULL,"
        "   'name' TEXT NOT NULL,"
        "   'battery_percent' INTEGER DEFAULT '0',"
        "   'battery_time' INTEGER DEFAULT '0',"
        "   'owner' TEXT NOT NULL,"
        "   PRIMARY KEY(mac),"
        "   FOREIGN KEY(type) REFERENCES DeviceType(type),"
        "   FOREIGN KEY(status) REFERENCES DeviceStatus(status),"
        "   FOREIGN KEY(vad) REFERENCES DeviceVAD(vad),"
        "   FOREIGN KEY(owner) REFERENCES Accounts(account)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.prepare("INSERT INTO Devices VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");

    QVariantList macs;
    QVariantList seleteds;
    QVariantList types;
    QVariantList statuss;
    QVariantList vads;
    QVariantList names;
    QVariantList battery_percents;
    QVariantList battery_times;
    QVariantList owners;

    for(int i : 15){
        macs << QString("mac %1").arg(i);
        seleteds << i%2?1:0;
        types << QString("display %1").arg(i);
        statuss << QString("ND");
        vads << QString("online");
        names << QString("password %1").arg(i);
        battery_percents << QString("display %1").arg(i);
        battery_times << QString("ND");
        owners << QString("account %1").arg(i);
    }

    query.addBindValue( accounts );
    query.addBindValue( passwords );
    query.addBindValue( displays );
    query.addBindValue( types );
    query.addBindValue( statuss );

    if(!query.execBatch()){
        qDebug()<<query.executedQuery();
        qDebug()<<query.lastError();
        return;
    }
}

void SqlInitialize::createConferencTypeTable();
void SqlInitialize::createConferencsTable();
void SqlInitialize::createFileTypeTable();
void SqlInitialize::createFileSuffixTable();
void SqlInitialize::createFilesTable();

void SqlInitialize::createDownloadsTable();
