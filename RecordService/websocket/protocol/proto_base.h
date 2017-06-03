#ifndef PROTO_BASE_H
#define PROTO_BASE_H

#include <QObject>
#include <QSharedPointer>
#include <QVariantMap>

class ServiceBase;
class MessagePacket;
class ProtoBasePrivate;

class ProtoBase : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ProtoBase)
    Q_DECLARE_PRIVATE(ProtoBase)
public:
    explicit ProtoBase(ServiceBase *service, QObject *parent = nullptr);

    virtual QString mode() const;

    /*
     *put heavy work in process function
    */
    virtual void process(QSharedPointer<MessagePacket> pkt);

    virtual MessagePacket *make(QString from, QString to, int action, QVariantMap data, QString mode = "");

Q_SIGNALS:

public Q_SLOTS:

protected:
    ProtoBase(ProtoBasePrivate *d, QObject *parent = nullptr);
    QScopedPointer<ProtoBasePrivate> d_ptr;
    friend class ServiceBase;
};

#endif // PROTO_BASE_H
