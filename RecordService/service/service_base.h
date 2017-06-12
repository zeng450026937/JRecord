#ifndef SERVICE_BASE_H
#define SERVICE_BASE_H

#include <QObject>
#include <QNetworkRequest>

class MessagePacket;
class ProtoBase;
class ServiceBasePrivate;

class ServiceBase : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ServiceBase)
    Q_DECLARE_PRIVATE(ServiceBase)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(QString errorString READ errorString)
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)

    Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)
    Q_PROPERTY(QString userGroup READ userGroup WRITE setUserGroup NOTIFY userGroupChanged)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString deviceType READ deviceType WRITE setDeviceType NOTIFY deviceTypeChanged)
    Q_PROPERTY(QString deviceUuid READ deviceUuid NOTIFY deviceUuidChanged)
public:
    ServiceBase(QObject *parent = 0);
    ~ServiceBase();

    enum Status{
        Connecting,
        Open,
        Closing,
        Closed,
        Error
    };
    Q_ENUM(Status)

    Status status() const;
    bool active() const;
    QString errorString() const;
    QUrl url() const;

    QString userId() const;
    QString userGroup() const;
    QString userName() const;
    QString deviceType() const;
    QString deviceUuid() const;

    //protocol which register by registerProtocol(), will be deleted when removeProtocol is called
    //register protocol with same mode,the old one will be deleted
    void registerProtocol(ProtoBase *protocol);
    void removeProtocol(const QString &name);
    ProtoBase *protocol(const QString &name);

public Q_SLOTS:
    void setActive(bool active);
    void setUrl(const QUrl &url);
    void setUserId(const QString &userId);
    void setUserGroup(const QString &userGroup);
    void setUserName(const QString &userName);
    void setDeviceType(const QString &deviceType);

Q_SIGNALS:
    void statusChanged(Status status);
    void activeChanged(bool active);
    void urlChanged(const QUrl &url);
    void userIdChanged(const QString &userId);
    void userGroupChanged(const QString &userGroup);
    void userNameChanged(const QString &userName);
    void deviceTypeChanged(const QString &deviceType);
    void deviceUuidChanged(const QString &deviceUuid);
    void protocolChanged(const QString &protocolName);

protected:
    ServiceBase(ServiceBasePrivate *d, QObject *parent = 0);
    QScopedPointer<ServiceBasePrivate> d_ptr;
};

#endif // SERVICE_BASE_H
