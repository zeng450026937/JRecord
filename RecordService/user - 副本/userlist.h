#ifndef INFORMATION_H
#define INFORMATION_H

#include "client/client.h"
#include "user/user.h"
#include <QQmlListProperty>

class UserListPrivate;

class UserList : public Client
{
    Q_OBJECT
    Q_DISABLE_COPY(UserList)
    Q_DECLARE_PRIVATE(UserList)
    Q_PROPERTY(QQmlListProperty<User> list READ list NOTIFY listChanged)

public:
    explicit UserList(QObject *parent = 0);

    QQmlListProperty<User> list();

    Q_INVOKABLE void pull();
    Q_INVOKABLE void push(User *user);

    void setService(ServiceBase *servie) override;

Q_SIGNALS:
    void listChanged();
    void pullCompleted();
    void pushCompleted();

public Q_SLOTS:

protected:
    UserList(UserListPrivate *d, QObject *parent = 0);
};

#endif // INFORMATION_H
