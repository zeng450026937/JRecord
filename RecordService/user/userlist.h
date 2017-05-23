#ifndef INFORMATION_H
#define INFORMATION_H

#include <QObject>
#include <QQmlListProperty>
#include "user.h"

class UserListPrivate;

class UserList : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(UserList)
    Q_DECLARE_PRIVATE(UserList)
    Q_PROPERTY(QQmlListProperty<User> userlist READ userlist)

public:
    explicit UserList(QObject *parent = 0);

    QQmlListProperty<User> userlist();

    Q_INVOKABLE void pull();
    Q_INVOKABLE void push(User *user);

Q_SIGNALS:
    void pullCompleted();
    void pushCompleted();

protected:
    UserList(UserListPrivate *d, QObject *parent = 0);

private:
    QScopedPointer<UserListPrivate> d_ptr;
};

#endif // INFORMATION_H
