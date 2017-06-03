#include "proto_info.h"
#include "proto_info_p.h"
#include "service/service_base.h"
#include "websocket/textmessage.h"
#include "user/user.h"
#include <QMetaObject>
#include <QMetaEnum>
#include <QDebug>

ProtoInfo::ProtoInfo(ServiceBase *service, QObject *parent) :
    ProtoBase(new ProtoInfoPrivate(service, this), parent)
{

}

QString ProtoInfo::mode() const
{
    return d_func()->mode;
}

void ProtoInfo::process(QSharedPointer<MessagePacket> pkt)
{
    QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
    if(msg){

        const QMetaObject *MetaObject = this->metaObject();
        QMetaEnum MetaEnum = MetaObject->enumerator(MetaObject->indexOfEnumerator("Actions"));

        Actions action;
        switch(MetaEnum.keysToValue(msg->action().toUtf8())){
        case heartBeat:
            action = Actions::heartBeat;
            this->beat();
            break;
        case updateDeviceInfo:
            action = Actions::updateDeviceInfo;
            break;
        case getDeviceList:
            action = Actions::getDeviceList;
            break;
        default:
            action = Actions::ActionCount;
            break;
        }

        Q_EMIT actionRecived(action, msg->json());
    }
}

MessagePacket *ProtoInfo::make(QString from, QString to, int action, QVariantMap data, QString mode)
{
    const QMetaObject *MetaObject = this->metaObject();
    QMetaEnum MetaEnum = MetaObject->enumerator(MetaObject->indexOfEnumerator("Actions"));

    return new TextMessage(from,to,d_func()->mode,MetaEnum.valueToKey(action),data);
}

void ProtoInfo::beat()
{
    Q_D(ProtoInfo);

    d->service->sendMessage(this->make(d->service->userId(),
                                       QStringLiteral(""),
                                       Actions::heartBeat,
                                       QVariantMap())
                            );
}

void ProtoInfo::push(User *user)
{
    Q_D(ProtoInfo);

    QVariantMap data;
    data.insert(QStringLiteral("deviceName"),user->device()->name());
    data.insert(QStringLiteral("batteryPercent"),user->device()->percent());
    data.insert(QStringLiteral("batteryTime"),user->device()->time());
    data.insert(QStringLiteral("status"),user->device()->status());
    data.insert(QStringLiteral("vad"),user->device()->vad());

    d->service->sendMessage(this->make(d->service->userId(),
                                       QStringLiteral(""),
                                       Actions::updateDeviceInfo,
                                       data)
                            );
}

void ProtoInfo::pull()
{
    Q_D(ProtoInfo);

    d->service->sendMessage(this->make(d->service->userId(),
                                       QStringLiteral(""),
                                       Actions::getDeviceList,
                                       QVariantMap())
                            );
}
