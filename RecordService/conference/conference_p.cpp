#include "conference_p.h"

ConferencePrivate::ConferencePrivate(Conference *q) :
    ClientPrivate(q)
{

}

void ConferencePrivate::append(User *user)
{
    return userlist.append(user);
}

int ConferencePrivate::count() const
{
    return userlist.count();
}

User *ConferencePrivate::at(int index) const
{
    return userlist.at(index);
}

void ConferencePrivate::clear()
{
    return userlist.clear();
}

void ConferencePrivate::append(QQmlListProperty<User> *list, User *user)
{
    reinterpret_cast< ConferencePrivate* >(list->data)->append(user);
}

int ConferencePrivate::count(QQmlListProperty<User> *list)
{
    return reinterpret_cast< ConferencePrivate* >(list->data)->count();
}

User *ConferencePrivate::at(QQmlListProperty<User> *list, int index)
{
    return reinterpret_cast< ConferencePrivate* >(list->data)->at(index);
}

void ConferencePrivate::clear(QQmlListProperty<User> *list)
{
    reinterpret_cast< ConferencePrivate* >(list->data)->clear();
}
