#ifndef MESSAGE_PROCESSOR_H
#define MESSAGE_PROCESSOR_H

#include <QThread>

class MessageQueue;

class MessageProcessor : public QThread
{
    Q_OBJECT
public:
    explicit MessageProcessor(MessageQueue* q, QThread *parent = 0);

protected:
    void run() override;

private:
    MessageQueue* q_;
};

#endif // MESSAGE_PROCESSOR_H
