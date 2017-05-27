#ifndef MESSAGE_PACKET_H
#define MESSAGE_PACKET_H

#include <QObject>

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
};

Q_DECLARE_METATYPE(MessagePacket)

#endif // MESSAGE_PACKET_H
