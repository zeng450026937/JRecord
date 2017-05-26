#include "process_thread.h"
#include "process_thread_p.h"
#include "message_queue.h"
#include "textmessage.h"
#include "binarymessage.h"
#include <QWebSocket>

ProcessThread::ProcessThread(QObject *parent) :
    MessageThread(new ProcessThreadPrivate(this), parent)
{
    QObject::connect(this, SIGNAL(started()), SIGNAL(processStarted()));
    QObject::connect(this, SIGNAL(finished()), SIGNAL(processStopped()));
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

void ProcessThread::setSocket(QWebSocket *socket)
{
    Q_D(ProcessThread);
    if(d->socket){
        QObject::disconnect(d->textConnection);
        QObject::disconnect(d->binaryConnection);
    }

    d->textConnection = QObject::connect(socket, &QWebSocket::textMessageReceived,
                     [this](const QString &message){ pushMessage(new TextMessage(message)); });
    d->binaryConnection = QObject::connect(socket, &QWebSocket::binaryMessageReceived,
                     [this](const QByteArray &message){ pushMessage(new BinaryMessage(message)); });

    MessageThread::setSocket(socket);
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
        if(d->queue == Q_NULLPTR || d->queue->abort())
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

    }while (!d->queue->abort());
}
