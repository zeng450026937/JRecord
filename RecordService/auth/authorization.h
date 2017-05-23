#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QObject>

class MessageSocket;
class AuthorizationPrivate;

class Authorization : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Authorization)
    Q_DECLARE_PRIVATE(Authorization)

    Q_PROPERTY(QString userId READ userId WRITE setuserId NOTIFY userIdChanged)
    Q_PROPERTY(QString userGroup READ userGroup WRITE setUserGroup NOTIFY userGroupChanged)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString deviceType READ deviceType WRITE setDeviceType NOTIFY deviceTypeChanged)
    Q_PROPERTY(bool authorized READ authorized NOTIFY authorizedChanged)

public:
    explicit Authorization(QObject *parent = 0);

    QString userId() const;
    QString userGroup() const;
    QString userName() const;
    QString deviceType() const;
    bool authorized() const;

    Q_INVOKABLE void authorize();

    void setSocket(MessageSocket *socket);
    MessageSocket *socket();

public Q_SLOTS:
    void setuserId(QString userId);
    void setUserGroup(QString userGroup);
    void setUserName(QString userName);
    void setDeviceType(QString deviceType);

Q_SIGNALS:
    void userIdChanged(QString &userId);
    void userGroupChanged(QString &userGroup);
    void userNameChanged(QString &userName);
    void deviceTypeChanged(QString &deviceType);
    void authorizedChanged(bool authorized);

protected:
    Authorization(AuthorizationPrivate *d, QObject *parent = 0);
    QScopedPointer<AuthorizationPrivate> d_ptr;
};

#endif // AUTHORIZATION_H
