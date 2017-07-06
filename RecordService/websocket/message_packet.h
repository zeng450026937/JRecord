#ifndef MESSAGE_PACKET_H
#define MESSAGE_PACKET_H

#include <QObject>

class MessagePacketPrivate;

class MessagePacket : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MessagePacket)
  Q_DECLARE_PRIVATE(MessagePacket)
  Q_PROPERTY(MessageType type READ type WRITE setType NOTIFY typeChanged)
  Q_PROPERTY(bool notification READ notification WRITE setNotification NOTIFY
                 notificationChanged)

 public:
  explicit MessagePacket(QObject* parent = 0);

  enum MessageType { Text, Binary, Unknow };
  Q_ENUMS(MessageType)

  MessageType type() const;
  bool notification() const;

 Q_SIGNALS:
  void typeChanged(MessageType type);
  void notificationChanged(bool notification);

 public Q_SLOTS:
  void setType(MessageType type);
  void setNotification(bool notification);

 protected:
  MessagePacket(MessagePacketPrivate* d, QObject* parent = 0);
  QScopedPointer<MessagePacketPrivate> d_ptr;
};

#endif  // MESSAGE_PACKET_H
