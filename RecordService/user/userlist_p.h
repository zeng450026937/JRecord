#ifndef INFORMATION_P_H
#define INFORMATION_P_H

#include <QObject>
#include <QQmlListProperty>

class User;
class UserList;

class UserListPrivate
{
    Q_DISABLE_COPY(UserListPrivate)
    Q_DECLARE_PUBLIC(UserList)
public:
    UserListPrivate(UserList *q);

    UserList *q_ptr;
    QList<User *> userlist;

public:
    void append(User* user);
    int count() const;
    User* at(int index) const;
    void clear();

    static void append(QQmlListProperty<User>*list, User*user);
    static int count(QQmlListProperty<User>*list);
    static User* at(QQmlListProperty<User>*list, int index);
    static void clear(QQmlListProperty<User>*list);
};

#endif // INFORMATION_P_H
