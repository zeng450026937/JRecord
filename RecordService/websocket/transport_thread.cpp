#include "transport_thread.h"
#include "transport_thread_p.h"
#include "message_queue.h"
#include "textmessage.h"
#include "binarymessage.h"

TransportThread::TransportThread(QObject *parent) :
    MessageThread(new TransportThreadPrivate(this), parent)
{
    connect(this, SIGNAL(started()), SIGNAL(transportStarted()));
    connect(this, SIGNAL(finished()), SIGNAL(transportStopped()));
}

TransportThread::~TransportThread()
{
    if(this->isRunning()){
        Q_D(TransportThread);
        d->queue->setAbort(true);
        this->quit();
        this->wait(3000);
    }
}

void TransportThread::setQueue(MessageQueue *queue)
{
    Q_D(TransportThread);
    d->queue = queue;
}

MessageQueue *TransportThread::queue()
{
    Q_D(TransportThread);
    return d->queue;
}

void TransportThread::pushMessage(MessagePacket *message)
{
    Q_D(TransportThread);
    if(d->queue){
        d->queue->push(QSharedPointer<MessagePacket>(message));
    }
}

void TransportThread::run()
{
    Q_D(TransportThread);
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
                    Q_EMIT messageTransported(msg->make());
                }
            }
            if(pkt->type() == MessagePacket::Binary){
                QSharedPointer<BinaryMessage> msg = pkt.dynamicCast<BinaryMessage>();
                if(msg){
                    Q_EMIT messageTransported(msg->make());
                }
            }
        }

    }while (!d->queue->isAbort());
}
