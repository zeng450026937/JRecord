#ifndef PROTO_INFO_H
#define PROTO_INFO_H

#include "proto_base.h"
#include <QJsonValue>

class User;
class ProtoInfoPrivate;

class ProtoInfo : public ProtoBase
{
    Q_OBJECT
    Q_DISABLE_COPY(ProtoInfo)
    Q_DECLARE_PRIVATE(ProtoInfo)
public:
    explicit ProtoInfo(ServiceBase *service, QObject *parent = nullptr);

    QString mode() const override;

    void process(QSharedPointer<MessagePacket> pkt) override;

    MessagePacket *make(QString from, QString to, int action, QVariantMap data, QString mode = "") override;

    enum Actions{
        heartBeat,
        updateDeviceInfo,
        getDeviceList,
        ActionCount
    };
    Q_ENUM(Actions)

Q_SIGNALS:
    void actionRecived(Actions action, const QJsonValue &data);

public Q_SLOTS:
    void beat();
    void push(User *user);
    void pull();

public Q_SLOTS:

};

#endif // PROTO_INFO_H
