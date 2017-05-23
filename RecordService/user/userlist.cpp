#include "userlist.h"
#include "userlist_p.h"

UserList::UserList(QObject *parent) :
    QObject(parent),
    d_ptr(new UserListPrivate(this))
{

}

QQmlListProperty<User> UserList::userlist()
{
    return QQmlListProperty<User>(this, d_func(),
                                  &UserListPrivate::append,
                                  &UserListPrivate::count,
                                  &UserListPrivate::at,
                                  &UserListPrivate::clear);
}

void UserList::pull()
{
    //TBD
}

void UserList::push(User *user)
{
    Q_UNUSED(user);
    //TBD
}

UserList::UserList(UserListPrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}
