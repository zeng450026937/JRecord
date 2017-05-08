#ifndef BINARY_MESSAGE_H
#define BINARY_MESSAGE_H

#include <QByteArray>
#include <QString>
#include <QObject>

class BinaryMessage
{
public:
    BinaryMessage(QByteArray& binary);

    int type;
    const int type_size;
    QString sender;
    const int sender_size;
    QString file_uuid;
    const int file_uuid_size;
    int meeting_time;
    const int meeting_time_size;
    int file_startpos;
    const int file_startpos_size;
    int file_status;
    const int file_status_size;
    int data_size;
    const int data_size_size;

    QByteArray data;

private:
    void Read(QByteArray& binary);
    int total_size;
};
Q_DECLARE_METATYPE(BinaryMessage)

#endif // BINARY_MESSAGE_H
