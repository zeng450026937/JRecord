#include "proto_conf.h"
#include "proto_conf_p.h"
#include "service/service_base.h"
#include "websocket/textmessage.h"
#include <QMetaObject>
#include <QMetaEnum>
#include <QDebug>

ProtoConf::ProtoConf(ServiceBase *service, QObject *parent) :
    ProtoBase(new ProtoConfPrivate(service, this), parent)
{

}

QString ProtoConf::mode() const
{
    return d_func()->mode;
}

void ProtoConf::process(QSharedPointer<MessagePacket> pkt)
{
    QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
    if(msg){

        const QMetaObject *MetaObject = this->metaObject();
        QMetaEnum MetaEnum = MetaObject->enumerator(MetaObject->indexOfEnumerator("Actions"));

        Actions action;
        switch(MetaEnum.keysToValue(msg->action().toUtf8())){
        case lockDevice:
            action = Actions::lockDevice;
            break;
        case unlockDevice:
            action = Actions::unlockDevice;
            break;
        case createConference:
            action = Actions::createConference;
            break;
        case startConference:
            action = Actions::startConference;
            break;
        default:
            action = Actions::ActionCount;
            break;
        }

        Q_EMIT actionRecived(action, msg->json());
    }
}

MessagePacket *ProtoConf::make(QString from, QString to, int action, QVariantMap data, QString mode)
{
    const QMetaObject *MetaObject = this->metaObject();
    QMetaEnum MetaEnum = MetaObject->enumerator(MetaObject->indexOfEnumerator("Actions"));

    return new TextMessage(from,to,d_func()->mode,MetaEnum.valueToKey(action),data);
}

void ProtoConf::lock()
{

}

void ProtoConf::unlock()
{

}

void ProtoConf::create(const QString &title, const QString &content, const QString &members, const QString &devices)
{
    Q_D(ProtoConf);

    QVariantMap data;
    data.insert(QStringLiteral("title"),title);
    data.insert(QStringLiteral("content"),content);
    data.insert(QStringLiteral("members"),members);
    data.insert(QStringLiteral("devices"),devices);

    d->service->sendMessage(this->make(d->service->userId(),
                                       QStringLiteral(""),
                                       Actions::createConference,
                                       data)
                            );
}

void ProtoConf::start(const QString &uuid)
{
    Q_D(ProtoConf);

    QVariantMap data;
    data.insert(QStringLiteral("uuid"),uuid);

    d->service->sendMessage(this->make(d->service->userId(),
                                       QStringLiteral(""),
                                       Actions::startConference,
                                       data)
                            );
}

void ProtoConf::pause(const QString &uuid)
{
    Q_D(ProtoConf);

    QVariantMap data;
    data.insert(QStringLiteral("uuid"),uuid);

    d->service->sendMessage(this->make(d->service->userId(),
                                       QStringLiteral(""),
                                       Actions::pauseConference,
                                       data)
                            );
}

void ProtoConf::resume(const QString &uuid)
{

}

void ProtoConf::stop(const QString &uuid)
{
    Q_D(ProtoConf);

    QVariantMap data;
    data.insert(QStringLiteral("uuid"),uuid);

    d->service->sendMessage(this->make(d->service->userId(),
                                       QStringLiteral(""),
                                       Actions::stopConference,
                                       data)
                            );
}

void ProtoConf::join(const QString &uuid)
{

}

void ProtoConf::leave(const QString &uuid)
{

}

void ProtoConf::query(const QString &uuid)
{
    Q_D(ProtoConf);

    if(uuid.isEmpty()){

        d->service->sendMessage(this->make(d->service->userId(),
                                           QStringLiteral(""),
                                           Actions::getConferenceList,
                                           QVariantMap())
                                );
    }
    else{
        QVariantMap data;
        data.insert(QStringLiteral("uuid"),uuid);

        d->service->sendMessage(this->make(d->service->userId(),
                                           QStringLiteral(""),
                                           Actions::getConferenceInfo,
                                           data)
                                );
    }
}

