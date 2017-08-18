#ifndef MESSAGE_PACKET_H
#define MESSAGE_PACKET_H

#include <QObject>
#include <QUuid>

class MessagePacketPrivate;
class MessageReply;

class MessagePacket : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MessagePacket)
  Q_DECLARE_PRIVATE(MessagePacket)
  Q_PROPERTY(MessageType type READ type WRITE setType NOTIFY typeChanged)
  Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
  Q_PROPERTY(MessageReply* reply READ reply WRITE setReply NOTIFY replyChanged)

 public:
  explicit MessagePacket(QObject* parent = 0);

  enum MessageType { Text, Binary, Unknow };
  Q_ENUMS(MessageType)

  virtual bool equals(MessagePacket* msg);

  MessageType type() const;
  QUuid uuid() const;
  MessageReply* reply() const;

 Q_SIGNALS:
  void typeChanged(MessageType type);
  void uuidChanged(const QUuid& uuid);
  void replyChanged(MessageReply* reply);

 public Q_SLOTS:
  void setType(MessageType type);
  void setUuid(const QUuid& uuid);
  void setReply(MessageReply* reply);

 protected:
  MessagePacket(MessagePacketPrivate* d, QObject* parent = 0);
  QScopedPointer<MessagePacketPrivate> d_ptr;
};

#endif  // MESSAGE_PACKET_H
