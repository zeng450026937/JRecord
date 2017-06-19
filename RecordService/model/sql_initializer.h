#ifndef SQL_INITIALIZER_H
#define SQL_INITIALIZER_H

#include <QString>

static const QString deviceTableName = QStringLiteral("DEVICE");
static const QString conferenceTableName = QStringLiteral("CONFERENCE");
static const QString fileTableName = QStringLiteral("FILE");
static const QString downloadTableName = QStringLiteral("DOWNLOAD");

void connectToDatabase();

void createDeviceTable();
void createConferencTable();
void createFileTable();
void createDownloadTable();

#endif  // SQL_INITIALIZER_H
