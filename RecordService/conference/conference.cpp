#include "conference.h"
#include "conference_p.h"

Conference::Conference(QObject *parent) :
    Client(new ConferencePrivate(this), parent)
{

}

void Conference::create()
{
    //TBD
}

void Conference::start()
{
    //TBD
}

void Conference::pause()
{
    //TBD
}

void Conference::resume()
{
    //TBD
}

void Conference::stop()
{
    //TBD
}

void Conference::join(const QString &uuid)
{
    Q_UNUSED(uuid);
    //TBD
}

void Conference::leave()
{
    //TBD
}

void Conference::query(Conference::Type type, const QString &uuid)
{
    Q_UNUSED(type);
    Q_UNUSED(uuid);
    //TBD
}

User *Conference::host() const
{
    return d_func()->host;
}

QString Conference::uuid() const
{
    return d_func()->uuid;
}

QDate Conference::createTime()
{
    return d_func()->createTime;
}

QDate Conference::updateTime()
{
    return d_func()->updateTime;
}

QString Conference::title() const
{
    return d_func()->title;
}

QString Conference::content() const
{
    return d_func()->content;
}

QString Conference::member() const
{
    return d_func()->member;
}

QQmlListProperty<User> Conference::userlist()
{
    return QQmlListProperty<User>(this, d_func(),
                                  &ConferencePrivate::append,
                                  &ConferencePrivate::count,
                                  &ConferencePrivate::at,
                                  &ConferencePrivate::clear);
}

void Conference::setHost(User *host)
{
    Q_D(Conference);
    if(host != d->host){
        d->host = host;
        Q_EMIT hostChanged();
    }
}



void Conference::setTitle(const QString &title)
{
    Q_D(Conference);
    if(title != d->title){
        d->title = title;
        Q_EMIT titleChanged(d->title);
    }
}

void Conference::setContent(const QString &content)
{
    Q_D(Conference);
    if(content != d->content){
        d->content = content;
        Q_EMIT contentChanged(d->content);
    }
}

void Conference::setMember(const QString &member)
{
    Q_D(Conference);
    if(member != d->member){
        d->member = member;
        Q_EMIT memberChanged(d->member);
    }
}
