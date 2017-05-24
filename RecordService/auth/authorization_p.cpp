#include "authorization_p.h"
#include "auth/authorization.h"
#include "service/service_base.h"
#include "websocket/message_socket.h"
#include <QDebug>

AuthorizationPrivate::AuthorizationPrivate(Authorization *q) :
    q_ptr(q),
    userGroup(QStringLiteral("ND")),
    deviceType(QStringLiteral("PC")),
    authorized(false),
    socket(Q_NULLPTR)
{ 
    qRegisterMetaType<QNetworkRequest>();

    if(ServiceBase::GetInstance()->isRunning())
        socket = ServiceBase::GetInstance()->messageSocket();
    else{
        qDebug()<<QStringLiteral("socket service is not running!");
    }

    if(socket){
        connect(socket, SIGNAL(connected()),
                this, SLOT(onConnected()));
        connect(socket, SIGNAL(disconnected()),
                this, SLOT(onDisConnected()));

        connect(this, SIGNAL(authorizing(QNetworkRequest)),
                socket, SLOT(open(QNetworkRequest)));
        connect(this, SIGNAL(authorizing(QUrl)),
                socket, SLOT(open(QUrl)));
    }
}

void AuthorizationPrivate::onConnected()
{
    Q_Q(Authorization);
    authorized = true;
    Q_EMIT q->authorizedChanged(authorized);
}

void AuthorizationPrivate::onDisConnected()
{
    Q_Q(Authorization);
    authorized = false;
    Q_EMIT q->authorizedChanged(authorized);
}
