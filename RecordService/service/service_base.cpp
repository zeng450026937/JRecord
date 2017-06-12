#include "service_base.h"
#include "service/service_base_p.h"
#include "websocket/transport_thread.h"
#include "websocket/process_thread.h"
#include "websocket/message_queue.h"
#include "websocket/textmessage.h"
#include "websocket/message_socket.h"
#include "websocket/protocol/proto_base.h"
#include "websocket/protocol/proto_base_p.h"
#include "websocket/protocol/proto_info.h"
#include "websocket/protocol/proto_conf.h"

ServiceBase::ServiceBase(QObject *parent) :
    QObject(parent),
    d_ptr(new ServiceBasePrivate(this))
{
    Q_D(ServiceBase);

    this->registerProtocol(new ProtoInfo(this));
    this->registerProtocol(new ProtoConf(this));

    d->process_thread->setProtocols(&d->protocols);
    d->transport_thread->setProtocols(&d->protocols);
}

ServiceBase::~ServiceBase()
{
    Q_D(ServiceBase);
    this->setActive(false);

    d->protocols.clear();
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

QString ServiceBase::deviceUuid() const
{
    return d_func()->deviceUuid;
}

void ServiceBase::registerProtocol(ProtoBase *protocol)
{
    Q_D(ServiceBase);

    this->removeProtocol(protocol->mode());

    protocol->d_func()->transport = d->transport_thread;
    QObject::connect(this, &ServiceBase::userIdChanged,
                     protocol, &ProtoBase::setOwner);

    d->protocols.insert(protocol->mode(), protocol);

    Q_EMIT protocolChanged(protocol->mode());
}

void ServiceBase::removeProtocol(const QString &name)
{
    Q_D(ServiceBase);
    ProtoBase *protocol = d->protocols.value(name, Q_NULLPTR);
    if(protocol)
        protocol->deleteLater();
    d->protocols.remove(name);
}

ProtoBase *ServiceBase::protocol(const QString &name)
{
    return d_func()->protocols.value(name, Q_NULLPTR);
}

void ServiceBase::setActive(bool active)
{
    Q_D(ServiceBase);
    if(active != d->active){
        if(active){

            d->status = ServiceBase::Connecting;
            Q_EMIT statusChanged(d->status);

            QVariantMap data;
            data.insert(QStringLiteral("userId"), d->userId);
            data.insert(QStringLiteral("userGroup"), d->userGroup);
            data.insert(QStringLiteral("userName"), d->userName);
            data.insert(QStringLiteral("deviceType"), d->deviceType);
            data.insert(QStringLiteral("deviceUuid"), d->deviceUuid);

            QScopedPointer<TextMessage> auth(new TextMessage);
            auth->setMode(QStringLiteral("auth"));
            auth->setAction(QStringLiteral("login"));
            auth->setData(data);

            QNetworkRequest request(d->url);
            request.setRawHeader("Accept", "application/json");
            request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
            request.setRawHeader("Authorization", auth->encode().toUtf8());

            d->socket->setRequest(request);
        }
        else{

            d->status = ServiceBase::Closing;
            Q_EMIT statusChanged(d->status);
        }

        d->active = active;
        Q_EMIT activeChanged(d->active);
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

ServiceBase::ServiceBase(ServiceBasePrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}

