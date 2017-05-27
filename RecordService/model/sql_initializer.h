#ifndef SQL_INITIALIZER_H
#define SQL_INITIALIZER_H

#include <QString>

static const QString userTableName = QStringLiteral("USER");
static const QString conferenceTableName = QStringLiteral("CONFERENCE");
static const QString fileTableName = QStringLiteral("FILE");
static const QString downloadTableName = QStringLiteral("DOWNLOAD");

void connectToDatabase();

void createUserTable();
void createConferencTable();
void createFileTable();
void createDownloadTable();


#endif // SQL_INITIALIZER_H
