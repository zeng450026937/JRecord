#include "sql_initialize.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QDateTime>
#include <QDebug>


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
    query.addBindValue(accountTypeList);
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

    //dnd = do not disturb
    accountStatusList << "online" << "offline" << "busy" << "away" << "dnd";

    query.prepare("INSERT INTO AccountStatus VALUES (?)");
    query.addBindValue(accountStatusList);
    query.execBatch();
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

    QVariantList passwords;
    QVariantList displays;
    QVariantList types;
    QVariantList statuss;

    for(int i = 0; i < 15; i++){
        accountsList << QString("account %1").arg(i);
        passwords << QString("password %1").arg(i);
        displays << QString("display %1").arg(i);
        types << accountTypeList.at(i%1);
        statuss << accountStatusList.at(i%5);
    }

    query.addBindValue( accountsList );
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

    deviceTypeList << "PC" << "ANDROID" << "IOS";

    query.prepare("INSERT INTO DeviceType VALUES (?)");
    query.addBindValue(deviceTypeList);
    query.execBatch();
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

    deviceStatusList << "idle" << "recording" << "busy" << "background" << "low power" << "dnd";

    query.prepare("INSERT INTO DeviceStatus VALUES (?)");
    query.addBindValue(deviceStatusList);
    query.execBatch();
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

    deviceVadList << "good" << "noise" << "bad" << "no voice";

    query.prepare("INSERT INTO DeviceVAD VALUES (?)");
    query.addBindValue(deviceVadList);
    query.execBatch();
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
        "   'locked' INTEGER DEFAULT '0',"
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
    QVariantList locked;
    QVariantList types;
    QVariantList statuss;
    QVariantList vads;
    QVariantList names;
    QVariantList battery_percents;
    QVariantList battery_times;
    QVariantList owners;

    for(int i = 0; i < 15; i++){
        macs << QString("mac %1").arg(i);
        locked << (i%2?1:0);
        types << deviceTypeList.at(i%3);
        statuss << deviceStatusList.at(i%4);
        vads << deviceVadList.at(i%4);
        names << QString("name %1").arg(i);
        battery_percents << qrand()%100;
        battery_times << qrand()%3600;
        owners << accountsList.at(i%15);
    }

    query.addBindValue( macs );
    query.addBindValue( locked );
    query.addBindValue( types );
    query.addBindValue( statuss );
    query.addBindValue( vads );
    query.addBindValue( names );
    query.addBindValue( battery_percents );
    query.addBindValue( battery_times );
    query.addBindValue( owners );

    if(!query.execBatch()){
        qDebug()<<query.executedQuery();
        qDebug()<<query.lastError();
        return;
    }
}

void SqlInitialize::createConferencTypeTable()
{
    if (QSqlDatabase::database().tables().contains(conferenceTypeTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'ConferenceType' ("
        "   'type' TEXT NOT NULL,"
        "   PRIMARY KEY(type)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    conferenceTypeList << "regular" << "personal" << "performance" << "mobile";

    query.prepare("INSERT INTO ConferenceType VALUES (?)");
    query.addBindValue(conferenceTypeList);
    query.execBatch();
}
void SqlInitialize::createConferencsTable()
{
    if (QSqlDatabase::database().tables().contains(conferencesTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Conferencs' ("
        "   'uuid' TEXT NOT NULL,"
        "   'type' TEXT NOT NULL,"
        "   'title' TEXT NOT NULL,"
        "   'description' TEXT NOT NULL,"
        "   'members' TEXT NOT NULL,"
        "   'userlist' TEXT NOT NULL,"
        "   'create_time' TEXT NOT NULL,"
        "   'update_time' TEXT NOT NULL,"
        "   'completed' INTEGER DEFAULT '0',"
        "   'downloaded' INTEGER DEFAULT '0',"
        "   PRIMARY KEY(uuid)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.prepare("INSERT INTO Conferencs VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    QVariantList uuids;
    QVariantList types;
    QVariantList titles;
    QVariantList descriptions;
    QVariantList members;
    QVariantList userlist;
    QVariantList create_time;
    QVariantList update_time;
    QVariantList completed;
    QVariantList downloaded;

    for(int i = 0; i < 15; i++){
        uuids << QString("uuid %1").arg(i);
        types << conferenceTypeList.at(i%4);
        titles << QString("title %1").arg(i);
        descriptions << QString("description %1").arg(i);
        members << QString("member %1").arg(i);
        userlist << accountsList.at(i%15);
        create_time << QDateTime::currentDateTimeUtc().toString(Qt::ISODate);
        update_time << QDateTime::currentDateTimeUtc().toString(Qt::ISODate);
        completed << (i%2?1:0);
        downloaded << (i%2?1:0);
    }

    query.addBindValue( uuids );
    query.addBindValue( types );
    query.addBindValue( titles );
    query.addBindValue( descriptions );
    query.addBindValue( members );
    query.addBindValue( userlist );
    query.addBindValue( create_time );
    query.addBindValue( update_time );
    query.addBindValue( completed );
    query.addBindValue( downloaded );

    if(!query.execBatch()){
        qDebug()<<query.executedQuery();
        qDebug()<<query.lastError();
        return;
    }
}
void SqlInitialize::createFileTypeTable()
{
    if (QSqlDatabase::database().tables().contains(fileTypeTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'FileType' ("
        "   'type' TEXT NOT NULL,"
        "   PRIMARY KEY(type)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    fileTypeList << "normal" << "clip";

    query.prepare("INSERT INTO FileType VALUES (?)");
    query.addBindValue(fileTypeList);
    query.execBatch();
}
void SqlInitialize::createFileSuffixTable()
{
    if (QSqlDatabase::database().tables().contains(fileSuffixTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'FileSuffix' ("
        "   'suffix' TEXT NOT NULL,"
        "   PRIMARY KEY(suffix)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    fileSuffixList << "amr" << "mp3" << "m4a" << "wav";

    query.prepare("INSERT INTO FileSuffix VALUES (?)");
    query.addBindValue(fileSuffixList);
    query.execBatch();
}
void SqlInitialize::createFilesTable()
{
    if (QSqlDatabase::database().tables().contains(filesTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Files' ("
        "   'path' TEXT NOT NULL,"
        "   'type' TEXT NOT NULL,"
        "   'suffix' TEXT NOT NULL,"
        "   'conference' TEXT NOT NULL,"
        "   'owner' TEXT NOT NULL,"
        "   'device' TEXT NOT NULL,"
        "   'time_drift' INTEGER DEFAULT '0',"
        "   PRIMARY KEY(path),"
        "   FOREIGN KEY(type) REFERENCES Conferencs(type),"
        "   FOREIGN KEY(suffix) REFERENCES Conferencs(suffix),"
        "   FOREIGN KEY(conference) REFERENCES Conferencs(uuid),"
        "   FOREIGN KEY(owner) REFERENCES Accounts(account),"
        "   FOREIGN KEY(device) REFERENCES Devices(mac)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.prepare("INSERT INTO Files VALUES (?, ?, ?, ?, ?, ?, ?)");

    QVariantList paths;
    QVariantList types;
    QVariantList suffixs;
    QVariantList conferences;
    QVariantList owners;
    QVariantList devices;
    QVariantList time_drift;

    for(int i = 0; i < 15; i++){
        paths << QString("path %1").arg(i);
        types << fileTypeList.at(i%2);
        suffixs << fileSuffixList.at(i%4);
        conferences << conferencesList.at(i%15);
        owners << accountsList.at(i%15);
        devices << devicesList.at(i%15);
        time_drift << qrand()%60;
    }

    query.addBindValue( paths );
    query.addBindValue( types );
    query.addBindValue( suffixs );
    query.addBindValue( conferences );
    query.addBindValue( owners );
    query.addBindValue( devices );
    query.addBindValue( time_drift );

    if(!query.execBatch()){
        qDebug()<<query.executedQuery();
        qDebug()<<query.lastError();
        return;
    }
}

void SqlInitialize::createDownloadsTable()
{
    if (QSqlDatabase::database().tables().contains(downloadsTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Downloads' ("
        "   'id' INTEGER NOT NULL,"
        "   'conference' TEXT NOT NULL,"
        "   'owner' TEXT NOT NULL,"
        "   'startpos' INTEGER NOT NULL,"
        "   'data_size' INTEGER DEFAULT '0',"
        "   'data' BLOB DEFAULT '',"
        "   'completed' INTEGER DEFAULT '0',"
        "   'path' TEXT NOT NULL,"
        "   PRIMARY KEY(id),"
        "   FOREIGN KEY(conference) REFERENCES Conferencs(uuid),"
        "   FOREIGN KEY(owner) REFERENCES Accounts(account)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.prepare("INSERT INTO Downloads VALUES (?, ?, ?, ?, ?, ?, ?)");

    QVariantList ids;
    QVariantList conferences;
    QVariantList owners;
    QVariantList startposs;
    QVariantList data_sizes;
    QVariantList data;
    QVariantList completeds;
    QVariantList paths;

    for(int i = 0; i < 15; i++){
        ids << QString("id %1").arg(i);
        conferences << conferencesList.at(i%15);
        owners << accountsList.at(i%15);
        startposs << qrand()%60;
        data_sizes << qrand()%60;
        data << QByteArray("data");
        completeds << (i%2?1:0);
        paths << QString("path %1").arg(i);
    }

    query.addBindValue( ids );
    query.addBindValue( conferences );
    query.addBindValue( owners );
    query.addBindValue( startposs );
    query.addBindValue( data_sizes );
    query.addBindValue( data );
    query.addBindValue( completeds );
    query.addBindValue( paths );

    if(!query.execBatch()){
        qDebug()<<query.executedQuery();
        qDebug()<<query.lastError();
        return;
    }
}
