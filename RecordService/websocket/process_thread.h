#ifndef PROCESS_THREAD_H
#define PROCESS_THREAD_H

#include "message_thread.h"

class MessagePacket;
class ProcessThreadPrivate;

class ProcessThread : public MessageThread
{
    Q_OBJECT
    Q_DISABLE_COPY(ProcessThread)
    Q_DECLARE_PRIVATE(ProcessThread)
public:
    explicit ProcessThread(QObject *parent = 0);
    ~ProcessThread();

    void setSocket(QWebSocket *socket) override;

Q_SIGNALS:
    void processStarted();
    void processStopped();

public Q_SLOTS:
    void pushMessage(MessagePacket *message);

protected:
    void run() override;
};

#endif // PROCESS_THREAD_H
