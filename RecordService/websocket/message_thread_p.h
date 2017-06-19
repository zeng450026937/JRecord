#ifndef MESSAGE_THREAD_P_H
#define MESSAGE_THREAD_P_H

#include <QHash>
#include <QObject>

class ProtoBase;
class MessageThread;
class MessageQueue;
class MessageSocket;

class MessageThreadPrivate {
  Q_DISABLE_COPY(MessageThreadPrivate)
  Q_DECLARE_PUBLIC(MessageThread)
 public:
  MessageThreadPrivate(MessageThread *q);

  MessageThread *q_ptr;
  MessageQueue *queue;
  MessageSocket *socket;
  bool active;
  QHash<QString, ProtoBase *> *protocols;
};

#endif  // MESSAGE_THREAD_P_H
