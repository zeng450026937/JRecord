#ifndef CONFERENCE_P_H
#define CONFERENCE_P_H

#include "client/client_p.h"
#include "conference.h"
#include <QDate>

class User;

class ConferencePrivate : public ClientPrivate
{
    Q_DISABLE_COPY(ConferencePrivate)
    Q_DECLARE_PUBLIC(Conference)
public:
    ConferencePrivate(Conference *q);

    QString uuid;
    QDate createTime;
    QDate updateTime;
    QString title;
    QString content;
    QString member;

    User *host;
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

#endif // CONFERENCE_P_H
