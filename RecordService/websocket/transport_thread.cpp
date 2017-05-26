#include "transport_thread.h"
#include "transport_thread_p.h"
#include "message_queue.h"
#include "textmessage.h"
#include "binarymessage.h"
#include <QWebSocket>

TransportThread::TransportThread(QObject *parent) :
    MessageThread(new TransportThreadPrivate(this), parent)
{
    QObject::connect(this, SIGNAL(started()), SIGNAL(transportStarted()));
    QObject::connect(this, SIGNAL(finished()), SIGNAL(transportStopped()));
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

void TransportThread::setSocket(QWebSocket *socket)
{
    Q_D(TransportThread);

    if(d->socket){
        QObject::disconnect(d->textConnection);
        QObject::disconnect(d->binaryConnection);
    }

    d->textConnection = QObject::connect(this, SIGNAL(messageTransported(QString)),
                     socket, SLOT(sendTextMessage(QString)));
    d->binaryConnection = QObject::connect(this, SIGNAL(messageTransported(QByteArray)),
                     socket, SLOT(sendBinaryMessage(QByteArray)));

    MessageThread::setSocket(socket);
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
        if(d->queue == Q_NULLPTR || d->queue->abort())
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

    }while (!d->queue->abort());
}
