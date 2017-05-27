#include "sql_initializer.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QDateTime>
#include <QDebug>


void connectToDatabase()
{
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.isValid()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        if (!database.isValid())
            qFatal("Cannot add database: %s", qPrintable(database.lastError().text()));
    }

    if(database.isOpen())
        return;

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

void createUserTable()
{
    if (QSqlDatabase::database().tables().contains(userTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'USER' ("
        "   'userId' TEXT NOT NULL,"
        "   'userType' TEXT NOT NULL,"
        "   'userName' TEXT NOT NULL,"
        "   'deviceType' TEXT NOT NULL,"
        "   'deviceName' TEXT NOT NULL,"
        "   'batteryPercent' INTEGER DEFAULT '0',"
        "   'batteryTime' INTEGER DEFAULT '0',"
        "   'status' TEXT NOT NULL,"
        "   'vad' TEXT NOT NULL,"
        "   'locked' INTEGER DEFAULT '0',"
        "   PRIMARY KEY(userId)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.prepare("INSERT INTO USER VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    QVariantList userId;
    QVariantList userType;
    QVariantList userName;
    QVariantList deviceType;
    QVariantList deviceName;
    QVariantList batteryPercent;
    QVariantList batteryTime;
    QVariantList status;
    QVariantList vad;
    QVariantList locked;

    for(int i = 0; i < 15; i++){
        userId << QString("userId %1").arg(i);
        userType << QString("userType %1").arg(i);
        userName << QString("userName %1").arg(i);
        deviceType << QString("deviceType %1").arg(i);
        deviceName << QString("deviceName %1").arg(i);
        batteryPercent << qrand()%100;
        batteryTime << qrand()%3600;
        status << QString("status %1").arg(i);
        vad << QString("vad %1").arg(i);
        locked << (i%2?1:0);
    }

    query.addBindValue( userId );
    query.addBindValue( userType );
    query.addBindValue( userName );
    query.addBindValue( deviceType );
    query.addBindValue( deviceName );
    query.addBindValue( batteryPercent );
    query.addBindValue( batteryTime );
    query.addBindValue( status );
    query.addBindValue( vad );
    query.addBindValue( locked );

    if(!query.execBatch()){
        qDebug()<<query.executedQuery();
        qDebug()<<query.lastError();
        return;
    }
}


void createConferencsTable()
{
    if (QSqlDatabase::database().tables().contains(conferenceTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Conferencs' ("
        "   'uuid' TEXT NOT NULL,"
        "   'type' TEXT NOT NULL,"
        "   'title' TEXT NOT NULL,"
        "   'content' TEXT NOT NULL,"
        "   'members' TEXT NOT NULL,"
        "   'userlist' TEXT NOT NULL,"
        "   'create_time' TEXT NOT NULL,"
        "   'update_time' TEXT NOT NULL,"
        "   'status' TEXT NOT NULL,"
        "   'downloaded' INTEGER DEFAULT '0',"
        "   PRIMARY KEY(uuid)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.prepare("INSERT INTO Conferencs VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    QVariantList uuid;
    QVariantList type;
    QVariantList title;
    QVariantList content;
    QVariantList members;
    QVariantList userlist;
    QVariantList create_time;
    QVariantList update_time;
    QVariantList status;
    QVariantList downloaded;

    for(int i = 0; i < 15; i++){
        uuid << QString("uuid %1").arg(i);
        type << QString("type %1").arg(i);
        title << QString("title %1").arg(i);
        content << QString("content %1").arg(i);
        members << QString("member %1").arg(i);
        userlist << QString("userlist %1").arg(i);
        create_time << QDateTime::currentDateTimeUtc().toString(Qt::ISODate);
        update_time << QDateTime::currentDateTimeUtc().toString(Qt::ISODate);
        status << QString("status %1").arg(i);
        downloaded << (i%2?1:0);
    }

    query.addBindValue( uuid );
    query.addBindValue( type );
    query.addBindValue( title );
    query.addBindValue( content );
    query.addBindValue( members );
    query.addBindValue( userlist );
    query.addBindValue( create_time );
    query.addBindValue( update_time );
    query.addBindValue( status );
    query.addBindValue( downloaded );

    if(!query.execBatch()){
        qDebug()<<query.executedQuery();
        qDebug()<<query.lastError();
        return;
    }
}

void createFilesTable()
{
    if (QSqlDatabase::database().tables().contains(fileTableName)) {
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
        "   PRIMARY KEY(path)"
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
        types << QString("types %1").arg(i);
        suffixs << QString("suffixs %1").arg(i);
        conferences << QString("conferences %1").arg(i);
        owners << QString("owners %1").arg(i);
        devices << QString("devices %1").arg(i);
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

void createDownloadsTable()
{
    if (QSqlDatabase::database().tables().contains(downloadTableName)) {
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
        "   PRIMARY KEY(id)"
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
        conferences << QString("conferences %1").arg(i);
        owners << QString("owners %1").arg(i);
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
