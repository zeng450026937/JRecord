#ifndef PROTO_INFO_H
#define PROTO_INFO_H

#include "proto_base.h"
#include <QJsonValue>

class Device;
class ProtoInfoPrivate;

class ProtoInfo : public ProtoBase
{
    Q_OBJECT
    Q_DISABLE_COPY(ProtoInfo)
    Q_DECLARE_PRIVATE(ProtoInfo)
public:
    explicit ProtoInfo(QObject *parent = nullptr);

    void process(QSharedPointer<MessagePacket> pkt) override;

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
    void push(Device *device);
    void pull();

};

#endif // PROTO_INFO_H
