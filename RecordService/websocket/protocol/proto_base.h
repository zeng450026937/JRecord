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
    Q_PROPERTY(QString mode READ mode CONSTANT)
    Q_PROPERTY(QString owner READ owner WRITE setOwner NOTIFY ownerChanged)
public:
    explicit ProtoBase(QObject *parent = nullptr);

    QString mode() const;
    QString owner() const;

Q_SIGNALS:
    void ownerChanged(const QString &owner);

public Q_SLOTS:
    void setOwner(const QString &owner);

protected:
    /*
     *put heavy work in process function
    */
    virtual void process(QSharedPointer<MessagePacket> pkt);

    virtual void transport(QString to, QString action, QVariantMap data);

    ProtoBase(ProtoBasePrivate *d, QObject *parent = nullptr);
    QScopedPointer<ProtoBasePrivate> d_ptr;
    friend class ProcessThread;
    friend class ServiceBase;
};

#endif // PROTO_BASE_H
