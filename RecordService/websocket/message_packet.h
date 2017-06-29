#ifndef MESSAGE_PACKET_H
#define MESSAGE_PACKET_H

#include <QObject>

class MessagePacketPrivate;

class MessagePacket : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MessagePacket)
  Q_DECLARE_PRIVATE(MessagePacket)
  Q_PROPERTY(MessageType type READ type WRITE setType NOTIFY typeChanged)

 public:
  explicit MessagePacket(QObject* parent = 0);

  enum MessageType { Text, Binary, Unknow };
  Q_ENUMS(MessageType)

  MessageType type() const;

 Q_SIGNALS:
  void typeChanged(MessageType type);

 public Q_SLOTS:
  void setType(MessageType type);

 protected:
  MessagePacket(MessagePacketPrivate* d, QObject* parent = 0);
  QScopedPointer<MessagePacketPrivate> d_ptr;
};

#endif  // MESSAGE_PACKET_H
