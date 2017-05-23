#include "authorization.h"
#include "authorization_p.h"
#include "websocket/message_socket.h"
#include "websocket/textmessage.h"
#include <QDebug>

Authorization::Authorization(QObject *parent) :
    QObject(parent),
    d_ptr(new AuthorizationPrivate(this))
{
    qRegisterMetaType<QNetworkRequest>();
}

QString Authorization::userId() const
{
    return d_func()->userId;
}

QString Authorization::userGroup() const
{
    return d_func()->userGroup;
}

QString Authorization::userName() const
{
    return d_func()->userName;
}

QString Authorization::deviceType() const
{
    return d_func()->deviceType;
}

bool Authorization::authorized() const
{
    return d_func()->authorized;
}

void Authorization::authorize()
{
    Q_D(Authorization);

    QVariantMap data;
    data.insert(QStringLiteral("userId"), d->userId);
    data.insert(QStringLiteral("userGroup"), d->userGroup);
    data.insert(QStringLiteral("userName"), d->userName);
    data.insert(QStringLiteral("deviceType"), d->deviceType);

    QScopedPointer<TextMessage> auth(new TextMessage);
    auth->setMode(QStringLiteral("auth"));
    auth->setAction(QStringLiteral("login"));
    auth->setData(data);

    QNetworkRequest request(d->socket->url());
    request.setRawHeader("Accept", "application/json");
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setRawHeader("Authorization", auth->make().toUtf8());

    Q_EMIT d->authorizing(request);
}

void Authorization::setSocket(MessageSocket *socket)
{
    Q_D(Authorization);
    if(d->socket)
        this->disconnect(d->socket);

    d->socket = socket;
    connect(d->socket, SIGNAL(connected()),
            d, SLOT(onConnected()));
    connect(d->socket, SIGNAL(disconnected()),
            d, SLOT(onDisConnected()));
    connect(d, SIGNAL(authorizing(QNetworkRequest)),
            d->socket, SLOT(open(QNetworkRequest)));
}

MessageSocket *Authorization::socket()
{
    Q_D(Authorization);
    return d->socket;
}

void Authorization::setuserId(QString userId)
{
    Q_D(Authorization);
    if(userId != d->userId){
        d->userId = userId;
        Q_EMIT userIdChanged(d->userId);
    }
}

void Authorization::setUserGroup(QString userGroup)
{
    Q_D(Authorization);
    if(userGroup != d->userGroup){
        d->userGroup = userGroup;
        Q_EMIT userGroupChanged(d->userGroup);
    }
}

void Authorization::setUserName(QString userName)
{
    Q_D(Authorization);
    if(userName != d->userName){
        d->userName = userName;
        Q_EMIT deviceTypeChanged(d->userName);
    }
}

void Authorization::setDeviceType(QString deviceType)
{
    Q_D(Authorization);
    if(deviceType != d->deviceType){
        d->deviceType = deviceType;
        Q_EMIT deviceTypeChanged(d->deviceType);
    }
}

Authorization::Authorization(AuthorizationPrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}
