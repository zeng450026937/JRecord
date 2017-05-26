#ifndef SQL_INITIALIZE_H
#define SQL_INITIALIZE_H

#include <QString>
#include <QVariant>

class SqlInitialize
{
public:
    SqlInitialize() :
        userTableName(QStringLiteral("USER")),
        conferenceTableName(QStringLiteral("CONFERENCE")),
        fileTableName(QStringLiteral("FILE")),
        downloadTableName(QStringLiteral("DOWNLOAD"))
    {}

    ~SqlInitialize(){}
    //deprecated
    const QString userTableName;
    const QString conferenceTableName;
    const QString filesTableName;
    const QString downloadsTableName;

    void connectToDatabase();

    void createUserTable();
    void createConferencTable();
    void createFileTable();
    void createDownloadTable();
};





#endif // SQL_INITIALIZE_H
