#include "service_base.h"
#include "service/service_base_p.h"
#include "websocket/transport_thread.h"
#include "websocket/process_thread.h"
#include "websocket/message_queue.h"
#include "websocket/textmessage.h"

ServiceBase::ServiceBase(QObject *parent) :
    QObject(parent),
    d_ptr(new ServiceBasePrivate(this))
{

}

ServiceBase::~ServiceBase()
{

}

bool ServiceBase::active() const
{
    return d_func()->active;
}

QString ServiceBase::errorString() const
{
    return d_func()->errorString;
}

QUrl ServiceBase::url() const
{
    return d_func()->url;
}
QString ServiceBase::userId() const
{
    return d_func()->userId;
}

QString ServiceBase::userGroup() const
{
    return d_func()->userGroup;
}

QString ServiceBase::userName() const
{
    return d_func()->userName;
}

QString ServiceBase::deviceType() const
{
    return d_func()->deviceType;
}
void ServiceBase::setActive(bool active)
{
    Q_D(ServiceBase);
    if(active != d->active){
        if(active){
            d->transport_queue->setAbort(false);
            d->process_queue->setAbort(false);

            d->transport_thread->start();
            d->process_thread->start();
            d->socket_thread->start();
            d->main_thread->start();

            #if(1)
                QVariantMap data;
                data.insert(QStringLiteral("userId"), d->userId);
                data.insert(QStringLiteral("userGroup"), d->userGroup);
                data.insert(QStringLiteral("userName"), d->userName);
                data.insert(QStringLiteral("deviceType"), d->deviceType);

                QScopedPointer<TextMessage> auth(new TextMessage);
                auth->setMode(QStringLiteral("auth"));
                auth->setAction(QStringLiteral("login"));
                auth->setData(data);

                QNetworkRequest request(d->url);
                request.setRawHeader("Accept", "application/json");
                request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
                request.setRawHeader("Authorization", auth->make().toUtf8());

                Q_EMIT open(request);
            #else
                Q_EMIT open(d->url);
            #endif
        }
        else{
            d->transport_queue->setAbort(true);
            d->process_queue->setAbort(true);

            d->transport_thread->quit();
            d->process_thread->quit();
            d->socket_thread->quit();
            d->main_thread->quit();
            d->transport_thread->wait(3000);
            d->process_thread->wait(3000);
            d->socket_thread->wait(3000);
            d->main_thread->wait(3000);

            Q_EMIT close();
        }
    }
}

void ServiceBase::setUrl(const QUrl &url)
{
    Q_D(ServiceBase);
    if(url != d->url){
        d->url = url;
        Q_EMIT urlChanged(d->url);
    }
}
void ServiceBase::setUserId(const QString &userId)
{
    Q_D(ServiceBase);
    if(userId != d->userId){
        d->userId = userId;
        Q_EMIT userIdChanged(d->userId);
    }
}

void ServiceBase::setUserGroup(const QString &userGroup)
{
    Q_D(ServiceBase);
    if(userGroup != d->userGroup){
        d->userGroup = userGroup;
        Q_EMIT userGroupChanged(d->userGroup);
    }
}

void ServiceBase::setUserName(const QString &userName)
{
    Q_D(ServiceBase);
    if(userName != d->userName){
        d->userName = userName;
        Q_EMIT deviceTypeChanged(d->userName);
    }
}

void ServiceBase::setDeviceType(const QString &deviceType)
{
    Q_D(ServiceBase);
    if(deviceType != d->deviceType){
        d->deviceType = deviceType;
        Q_EMIT deviceTypeChanged(d->deviceType);
    }
}

void ServiceBase::sendMessage(MessagePacket *message)
{
    Q_D(ServiceBase);
    if(d->active)
        d->transport_thread->pushMessage(message);
}

ServiceBase::ServiceBase(ServiceBasePrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}

