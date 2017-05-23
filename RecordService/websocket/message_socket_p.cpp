#include "message_socket_p.h"
#include "process_thread.h"
#include "transport_thread.h"
#include "textmessage.h"
#include "binarymessage.h"
#include <QWebSocket>

MessageSocketPrivate::MessageSocketPrivate(MessageSocket *q) :
    q_ptr(q),
    socket(Q_NULLPTR),
    event_thread(Q_NULLPTR),
    transport(Q_NULLPTR),
    process(Q_NULLPTR),
    ref(0)
{
    socket = new QWebSocket(QStringLiteral(""),QWebSocketProtocol::VersionLatest,q_ptr);

    qRegisterMetaType<QByteArray>();

    QObject::connect(socket, SIGNAL(connected()),
            this, SLOT(onConnected()));
    QObject::connect(socket, SIGNAL(disconnected()),
            this, SLOT(onDisconnected()));
    QObject::connect(socket, SIGNAL(textMessageReceived(QString)),
            this, SLOT(onTextMessageReceived(QString)));
    QObject::connect(socket, SIGNAL(binaryMessageReceived(QByteArray)),
            this, SLOT(onBinaryMessageReceived(QByteArray&)));
}

MessageSocketPrivate::~MessageSocketPrivate()
{
    if(socket){
        if(socket->isValid())
            socket->close(QWebSocketProtocol::CloseCodeNormal, QStringLiteral("client closed"));

        delete socket;
    }
}

void MessageSocketPrivate::onConnected()
{
    Q_Q(MessageSocket);
    status = MessageSocket::Open;
    Q_EMIT q->connected();
    Q_EMIT q->statusChanged(status);
}

void MessageSocketPrivate::onDisconnected()
{
    Q_Q(MessageSocket);
    status = MessageSocket::Closed;
    Q_EMIT q->disconnected();
    Q_EMIT q->statusChanged(status);
}

void MessageSocketPrivate::sendTextMessage(const QString &message)
{
    socket->sendTextMessage(message);
}

void MessageSocketPrivate::sendBinaryMessage(const QByteArray &message)
{
    socket->sendBinaryMessage(message);
}

void MessageSocketPrivate::onTextMessageReceived(const QString &message)
{
    qDebug()<<"text message received:"<<message;

    if(process)
        process->pushMessage(new TextMessage(message));
}

void MessageSocketPrivate::onBinaryMessageReceived(const QByteArray &message)
{
    qDebug()<<"binary message received:"<<message;

    if(process)
        process->pushMessage(new BinaryMessage(message));
}
