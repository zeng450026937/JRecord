#ifndef MESSAGE_PACKET_H
#define MESSAGE_PACKET_H

#include <QString>
#include <QByteArray>
#include <QVariant>

class MessagePacket
{
public:
    enum MessageType{
        Text,
        Binary,
        Unknow
    };
    virtual ~MessagePacket() {}
    virtual MessageType type() { return Unknow; }
    virtual void process() = 0;
};

class TextMessageData
{
public:
    TextMessageData() {}

    QString command;
    QString result;
    QVariantMap data;
};
class TextMessage : public MessagePacket
{
public:
    TextMessage(QString msg);
    ~TextMessage();
    MessageType type() override { return Text; }
    void process() override;

    static QByteArray makeMessage(QString sender, QString receiver, QString command, QVariantMap data);
public:
    TextMessageData* d_ptr;
private:
    void parse(QString msg);
};

class BinaryMessageData
{
public:
    BinaryMessageData():
        type(0),
        type_size(4),
        sender(""),
        sender_size(17),
        file_uuid(""),
        file_uuid_size(32),
        meeting_time(0),
        meeting_time_size(4),
        file_startpos(0),
        file_startpos_size(4),
        file_status(0),
        file_status_size(4),
        data_size(0),
        data_size_size(4)
    {
        total_size = type_size + sender_size + file_uuid_size +
                     meeting_time_size + file_startpos_size +
                     file_status_size + data_size_size;
    }

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
    int total_size;

    QByteArray data;
};
class BinaryMessage : public MessagePacket
{
public:
    BinaryMessage(QByteArray msg);
    ~BinaryMessage();
    MessageType type() override { return Binary; }
    void process() override;
public:
    BinaryMessageData* d_ptr;
private:
    void parse(QByteArray msg);
};

#endif // MESSAGE_PACKET_H
