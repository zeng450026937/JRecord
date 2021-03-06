#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <QObject>
#include <QSharedPointer>

#include "message_packet.h"

class MessageQueuePrivate;

class MessageQueue : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MessageQueue)
  Q_DECLARE_PRIVATE(MessageQueue)
  Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
  Q_PROPERTY(bool empty READ empty)
  Q_PROPERTY(bool size READ size NOTIFY sizeChanged)
 public:
  explicit MessageQueue(QObject *parent = 0);
  ~MessageQueue();

  void push(QSharedPointer<MessagePacket> t);

  QSharedPointer<MessagePacket> pop(bool block = true);

  void flush();

  bool active();
  bool empty();
  int size();

 Q_SIGNALS:
  void activeChanged(bool active);
  void sizeChanged(int size);

 public Q_SLOTS:
  void setActive(bool active);

 protected:
  MessageQueue(MessageQueuePrivate *d, QObject *parent = 0);
  QScopedPointer<MessageQueuePrivate> d_ptr;
};

#endif  // MESSAGE_QUEUE_H
