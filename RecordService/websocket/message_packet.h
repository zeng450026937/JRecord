#ifndef MESSAGE_PACKET_H
#define MESSAGE_PACKET_H

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

#endif // MESSAGE_PACKET_H
