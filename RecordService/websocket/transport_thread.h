#ifndef TRANSPORT_THREAD_H
#define TRANSPORT_THREAD_H

#include "message_thread.h"

class TransportThreadPrivate;

class TransportThread : public MessageThread {
  Q_OBJECT
  Q_DISABLE_COPY(TransportThread)
  Q_DECLARE_PRIVATE(TransportThread)
 public:
  explicit TransportThread(QObject *parent = 0);
  ~TransportThread();

 Q_SIGNALS:
  void textTransported(const QString &message);
  void binaryTransported(const QByteArray &message);

 protected:
  void run() override;
};

#endif  // TRANSPORT_THREAD_H
