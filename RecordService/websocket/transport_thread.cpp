#include "transport_thread.h"
#include "transport_thread_p.h"
#include "message_queue.h"
#include "message_socket.h"
#include "textmessage.h"
#include "binarymessage.h"
#include <QDebug>

TransportThread::TransportThread(QObject *parent) :
    MessageThread(new TransportThreadPrivate(this), parent)
{
    QObject::connect(this, &TransportThread::socketChanged, [this](MessageSocket *socket){
        Q_D(TransportThread);

        QObject::disconnect(d->textConnection);
        QObject::disconnect(d->binaryConnection);

        d->textConnection = QObject::connect(this, &TransportThread::textTransported,
                                             socket, &MessageSocket::sendText);
        d->binaryConnection = QObject::connect(this, &TransportThread::binaryTransported,
                                               socket, &MessageSocket::sendBinary);
    });
}

TransportThread::~TransportThread()
{
    if(this->isRunning()){
        Q_D(TransportThread);
        d->queue->setActive(false);
        this->quit();
        this->wait(3000);
    }
}

void TransportThread::run()
{
    Q_D(TransportThread);
    do {
        if(d->queue == Q_NULLPTR)
            return;

        if(!d->queue->active())
            return;

        for(;;){
            QSharedPointer<MessagePacket> pkt = d->queue->pop();//block until new data arrived

            if(pkt.isNull())
                return;

            if(pkt->type() == MessagePacket::Text){
                QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
                if(msg){
                    Q_EMIT textTransported(msg->encode());
                    if(msg->action() != "heartBeat")
                        qDebug()<<"send:"<<msg->encode();
                }
            }
            if(pkt->type() == MessagePacket::Binary){
                QSharedPointer<BinaryMessage> msg = pkt.dynamicCast<BinaryMessage>();
                if(msg){
                    Q_EMIT binaryTransported(msg->make());
                }
            }
        }

    }while (d->queue->active());
}
