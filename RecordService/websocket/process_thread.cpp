#include "process_thread.h"
#include "process_thread_p.h"
#include "message_queue.h"
#include "textmessage.h"
#include "binarymessage.h"

ProcessThread::ProcessThread(QObject *parent) :
    MessageThread(new ProcessThreadPrivate(this), parent)
{
    connect(this, SIGNAL(started()), SIGNAL(processStarted()));
    connect(this, SIGNAL(finished()), SIGNAL(processStopped()));
}

ProcessThread::~ProcessThread()
{
    if(this->isRunning()){
        Q_D(ProcessThread);
        d->queue->setAbort(true);
        this->quit();
        this->wait(3000);
    }
}

void ProcessThread::setQueue(MessageQueue *queue)
{
    Q_D(ProcessThread);
    d->queue = queue;
}

MessageQueue *ProcessThread::queue()
{
    Q_D(ProcessThread);
    return d->queue;
}

void ProcessThread::pushMessage(MessagePacket *message)
{
    Q_D(ProcessThread);
    if(d->queue){
        d->queue->push(QSharedPointer<MessagePacket>(message));
    }
}

void ProcessThread::run()
{
    Q_D(ProcessThread);
    do {
        if(d->queue == Q_NULLPTR || d->queue->isAbort())
            return;

        for(;;){
            QSharedPointer<MessagePacket> pkt = d->queue->pop();//block until new data arrived

            if(pkt.isNull())
                return;

            if(pkt->type() == MessagePacket::Text){
                QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
                if(msg){
                    //TBD
                }
            }
            if(pkt->type() == MessagePacket::Binary){
                QSharedPointer<BinaryMessage> msg = pkt.dynamicCast<BinaryMessage>();
                if(msg){
                    //TBD
                }
            }
        }

    }while (!d->queue->isAbort());
}
