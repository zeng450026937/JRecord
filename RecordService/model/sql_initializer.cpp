#include "sql_initializer.h"

#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

void connectToDatabase() {
  QSqlDatabase database = QSqlDatabase::database();
  if (!database.isValid()) {
    database = QSqlDatabase::addDatabase("QSQLITE");
    if (!database.isValid())
      qFatal("Cannot add database: %s",
             qPrintable(database.lastError().text()));
  }

  if (database.isOpen()) return;

  const QDir writeDir = QCoreApplication::applicationDirPath();
  if (!writeDir.mkpath("."))
    qFatal("Failed to create writable directory at %s",
           qPrintable(writeDir.absolutePath()));

  // Ensure that we have a writable location on all devices.
  const QString fileName = writeDir.absolutePath() + "/private.db";
  // const QString fileName = ":memory:";
  // When using the SQLite driver, open() will create the SQLite database if it
  // doesn't exist.
  database.setDatabaseName(fileName);
  if (!database.open()) {
    qFatal("Cannot open database: %s", qPrintable(database.lastError().text()));
    QFile::remove(fileName);
  }
}

void createDeviceTable() {
  if (QSqlDatabase::database().tables().contains(deviceTableName)) {
    // The table already exists; we don't need to do anything.
    return;
  }

  QSqlQuery query;
  if (!query.exec("CREATE TABLE IF NOT EXISTS 'DEVICE' ("
                  "   'uuid' TEXT NOT NULL,"
                  "   'type' TEXT DEFAULT '',"
                  "   'name' TEXT DEFAULT '',"
                  "   'percent' INTEGER DEFAULT '0',"
                  "   'time' INTEGER DEFAULT '0',"
                  "   'status' TEXT DEFAULT '',"
                  "   'vad' TEXT DEFAULT '',"
                  "   'lock' INTEGER DEFAULT '0',"
                  "   PRIMARY KEY(uuid)"
                  ")")) {
    qFatal("Failed to query database: %s",
           qPrintable(query.lastError().text()));
  }
}

void createConferenceTable() {
  if (QSqlDatabase::database().tables().contains(conferenceTableName)) {
    // The table already exists; we don't need to do anything.
    return;
  }

  QSqlQuery query;
  if (!query.exec("CREATE TABLE IF NOT EXISTS 'CONFERENCE' ("
                  "   'uuid' TEXT NOT NULL,"
                  "   'type' INTEGER DEFAULT '0',"
                  "   'hostId' TEXT DEFAULT '',"
                  "   'hostName' TEXT DEFAULT '',"
                  "   'hostGroup' TEXT DEFAULT 'ND',"
                  "   'hostDevice' TEXT DEFAULT '',"
                  "   'title' TEXT DEFAULT '',"
                  "   'content' TEXT DEFAULT '',"
                  "   'members' TEXT DEFAULT '',"
                  "   'gps' TEXT DEFAULT '',"
                  "   'tag' TEXT DEFAULT '',"
                  "   'createTime' TEXT DEFAULT '',"
                  "   'updateTime' TEXT DEFAULT '',"
                  "   'status' INTEGER DEFAULT '0',"
                  "   PRIMARY KEY(uuid)"
                  ")")) {
    qFatal("Failed to query database: %s",
           qPrintable(query.lastError().text()));
  }
}

void createFilesTable() {
  if (QSqlDatabase::database().tables().contains(fileTableName)) {
    // The table already exists; we don't need to do anything.
    return;
  }

  QSqlQuery query;
  if (!query.exec("CREATE TABLE IF NOT EXISTS 'FILE' ("
                  "   'path' TEXT NOT NULL,"
                  "   'type' TEXT NOT NULL,"
                  "   'suffix' TEXT NOT NULL,"
                  "   'conference' TEXT NOT NULL,"
                  "   'owner' TEXT NOT NULL,"
                  "   'device' TEXT NOT NULL,"
                  "   'time_drift' INTEGER DEFAULT '0',"
                  "   PRIMARY KEY(path)"
                  ")")) {
    qFatal("Failed to query database: %s",
           qPrintable(query.lastError().text()));
  }

  query.prepare("INSERT INTO Files VALUES (?, ?, ?, ?, ?, ?, ?)");

  QVariantList paths;
  QVariantList types;
  QVariantList suffixs;
  QVariantList conferences;
  QVariantList owners;
  QVariantList devices;
  QVariantList time_drift;

  for (int i = 0; i < 15; i++) {
    paths << QString("path %1").arg(i);
    types << QString("types %1").arg(i);
    suffixs << QString("suffixs %1").arg(i);
    conferences << QString("conferences %1").arg(i);
    owners << QString("owners %1").arg(i);
    devices << QString("devices %1").arg(i);
    time_drift << qrand() % 60;
  }

  query.addBindValue(paths);
  query.addBindValue(types);
  query.addBindValue(suffixs);
  query.addBindValue(conferences);
  query.addBindValue(owners);
  query.addBindValue(devices);
  query.addBindValue(time_drift);

  if (!query.execBatch()) {
    qDebug() << query.executedQuery();
    qDebug() << query.lastError();
    return;
  }
}

void createDownloadsTable() {
  if (QSqlDatabase::database().tables().contains(downloadTableName)) {
    // The table already exists; we don't need to do anything.
    return;
  }

  QSqlQuery query;
  if (!query.exec("CREATE TABLE IF NOT EXISTS 'DOWNLOAD' ("
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
    qFatal("Failed to query database: %s",
           qPrintable(query.lastError().text()));
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

  for (int i = 0; i < 15; i++) {
    ids << QString("id %1").arg(i);
    conferences << QString("conferences %1").arg(i);
    owners << QString("owners %1").arg(i);
    startposs << qrand() % 60;
    data_sizes << qrand() % 60;
    data << QByteArray("data");
    completeds << (i % 2 ? 1 : 0);
    paths << QString("path %1").arg(i);
  }

  query.addBindValue(ids);
  query.addBindValue(conferences);
  query.addBindValue(owners);
  query.addBindValue(startposs);
  query.addBindValue(data_sizes);
  query.addBindValue(data);
  query.addBindValue(completeds);
  query.addBindValue(paths);

  if (!query.execBatch()) {
    qDebug() << query.executedQuery();
    qDebug() << query.lastError();
    return;
  }
}
