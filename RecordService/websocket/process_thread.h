#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H

#include "message_thread.h"

class ProcessThreadPrivate;

class ProcessThread : public MessageThread {
  Q_OBJECT
  Q_DISABLE_COPY(ProcessThread)
  Q_DECLARE_PRIVATE(ProcessThread)
 public:
  explicit ProcessThread(QObject *parent = 0);
  ~ProcessThread();

 Q_SIGNALS:
  void beforeProcess(QSharedPointer<MessagePacket> pkt);
  void afterProcess(QSharedPointer<MessagePacket> pkt);

 protected:
  void run() override;
};

#endif  // PROCESS_THREAD_H
