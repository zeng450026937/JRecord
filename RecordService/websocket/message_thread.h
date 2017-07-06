#ifndef MESSAGE_THREAD_H
#define MESSAGE_THREAD_H

#include <QSharedPointer>
#include <QThread>

class ProtoBase;
class MessagePacket;
class MessageSocket;
class MessageQueue;
class MessageThreadPrivate;

class MessageThread : public QThread {
  Q_OBJECT
  Q_DISABLE_COPY(MessageThread)
  Q_DECLARE_PRIVATE(MessageThread)
  Q_PROPERTY(MessageQueue *queue READ queue WRITE setQueue NOTIFY queueChanged)
  Q_PROPERTY(
      MessageSocket *socket READ socket WRITE setSocket NOTIFY socketChanged)
  Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
 public:
  explicit MessageThread(QObject *parent = 0);
  ~MessageThread();

  void setProtocols(QHash<QString, ProtoBase *> *protocols);

  bool active() const;
  MessageQueue *queue() const;
  MessageSocket *socket() const;

 Q_SIGNALS:
  void activeChanged(bool active);
  void queueChanged(MessageQueue *queue);
  void socketChanged(MessageSocket *socket);

 public Q_SLOTS:
  void setActive(bool active);
  void setQueue(MessageQueue *queue);
  void setSocket(MessageSocket *socket);

  void pushMessage(QSharedPointer<MessagePacket> message);

 protected:
  MessageThread(MessageThreadPrivate *d, QObject *parent = 0);
  QScopedPointer<MessageThreadPrivate> d_ptr;
};

#endif  // MESSAGE_THREAD_H
