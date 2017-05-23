#include "userlist_p.h"

UserListPrivate::UserListPrivate(UserList *q) :
    q_ptr(q)
{

}

void UserListPrivate::append(User *user)
{
    return userlist.append(user);
}

int UserListPrivate::count() const
{
    return userlist.count();
}

User *UserListPrivate::at(int index) const
{
    return userlist.at(index);
}

void UserListPrivate::clear()
{
    return userlist.clear();
}

void UserListPrivate::append(QQmlListProperty<User> *list, User *user)
{
    reinterpret_cast< UserListPrivate* >(list->data)->append(user);
}

int UserListPrivate::count(QQmlListProperty<User> *list)
{
    return reinterpret_cast< UserListPrivate* >(list->data)->count();
}

User *UserListPrivate::at(QQmlListProperty<User> *list, int index)
{
    return reinterpret_cast< UserListPrivate* >(list->data)->at(index);
}

void UserListPrivate::clear(QQmlListProperty<User> *list)
{
    reinterpret_cast< UserListPrivate* >(list->data)->clear();
}
