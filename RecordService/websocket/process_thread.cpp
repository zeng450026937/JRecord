#include "process_thread.h"
#include "process_thread_p.h"
#include "message_queue.h"
#include "message_socket.h"
#include "textmessage.h"
#include "binarymessage.h"
#include "protocol/proto_base.h"
#include <QDebug>

ProcessThread::ProcessThread(QObject *parent) :
    MessageThread(new ProcessThreadPrivate(this), parent)
{

}

ProcessThread::~ProcessThread()
{
    if(this->isRunning()){
        Q_D(ProcessThread);
        d->queue->setActive(false);
        this->quit();
        this->wait(3000);
    }
}

void ProcessThread::setSocket(MessageSocket *socket)
{
    Q_D(ProcessThread);
    if(d->socket){
        QObject::disconnect(d->textConnection);
        QObject::disconnect(d->binaryConnection);
    }

    d->textConnection = QObject::connect(socket, &MessageSocket::textReceived,
                     [this](const QString &message){
        pushMessage(new TextMessage(message));
    });
    d->binaryConnection = QObject::connect(socket, &MessageSocket::binaryReceived,
                     [this](const QByteArray &message){
        pushMessage(new BinaryMessage(message));
    });

    MessageThread::setSocket(socket);
}

void ProcessThread::run()
{
    Q_D(ProcessThread);
    do {
        if(d->queue == Q_NULLPTR || !d->queue->active())
            return;

        for(;;){
            QSharedPointer<MessagePacket> pkt = d->queue->pop();//block until new data arrived

            if(pkt.isNull())
                return;

            if(pkt->type() == MessagePacket::Text){
                QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
                if(msg){
                    //TBD
                    ProtoBase *protocol = d->protocols->value(msg->mode(), Q_NULLPTR);
                    if(protocol){
                        protocol->process(pkt);
                    }
                    if(msg->action() != "heartBeat")
                        qDebug()<<"received:"<<msg->makeJson();
                }
            }
            if(pkt->type() == MessagePacket::Binary){
                QSharedPointer<BinaryMessage> msg = pkt.dynamicCast<BinaryMessage>();
                if(msg){

                }
            }
        }

    }while (d->queue->active());
}
