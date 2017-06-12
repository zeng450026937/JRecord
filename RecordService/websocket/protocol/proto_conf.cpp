#include "proto_conf.h"
#include "proto_conf_p.h"
#include "service/service_base.h"
#include "websocket/textmessage.h"
#include <QMetaObject>
#include <QMetaEnum>
#include <QDebug>

ProtoConf::ProtoConf(QObject *parent) :
    ProtoBase(new ProtoConfPrivate(this), parent)
{
    Q_D(ProtoConf);
    d->mode = QStringLiteral("conference");
    d->metaEnum = this->metaObject()->enumerator(this->metaObject()->indexOfEnumerator("Actions"));
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

    this->transport(QStringLiteral(""),
                    d->metaEnum.valueToKey(createConference),
                    data);
}

void ProtoConf::start(const QString &uuid)
{
    Q_D(ProtoConf);

    QVariantMap data;
    data.insert(QStringLiteral("uuid"),uuid);

    this->transport(QStringLiteral(""),
                    d->metaEnum.valueToKey(startConference),
                    data);
}

void ProtoConf::pause(const QString &uuid)
{
    Q_D(ProtoConf);

    QVariantMap data;
    data.insert(QStringLiteral("uuid"),uuid);

    this->transport(QStringLiteral(""),
                    d->metaEnum.valueToKey(pauseConference),
                    data);
}

void ProtoConf::resume(const QString &uuid)
{

}

void ProtoConf::stop(const QString &uuid)
{
    Q_D(ProtoConf);

    QVariantMap data;
    data.insert(QStringLiteral("uuid"),uuid);

    this->transport(QStringLiteral(""),
                    d->metaEnum.valueToKey(stopConference),
                    data);
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

        this->transport(QStringLiteral(""),
                        d->metaEnum.valueToKey(getConferenceList),
                        QVariantMap());
    }
    else{
        QVariantMap data;
        data.insert(QStringLiteral("uuid"),uuid);

        this->transport(QStringLiteral(""),
                        d->metaEnum.valueToKey(getConferenceInfo),
                        data);
    }
}

