#ifndef MESSAGE_PACKET_H
#define MESSAGE_PACKET_H

#include <QObject>

class MessagePacketPrivate;

class MessagePacket : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MessagePacket)
  Q_DECLARE_PRIVATE(MessagePacket)
  Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
  Q_PROPERTY(MessageType type READ type WRITE setType NOTIFY typeChanged)

 public:
  explicit MessagePacket(QObject* parent = 0);

  enum MessageType { Text, Binary, Unknow };
  Q_ENUMS(MessageType)

  int id() const;
  MessageType type() const;

  virtual bool match(MessagePacket* pkt);
  virtual bool hasNotification();
  virtual bool notify();

 Q_SIGNALS:
  void idChanged(int id);
  void typeChanged(MessageType type);

 public Q_SLOTS:
  void setId(int id);
  void setType(MessageType type);

 protected:
  MessagePacket(MessagePacketPrivate* d, QObject* parent = 0);
  QScopedPointer<MessagePacketPrivate> d_ptr;
};

#endif  // MESSAGE_PACKET_H
