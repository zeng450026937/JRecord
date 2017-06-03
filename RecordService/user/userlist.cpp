#include "userlist.h"
#include "userlist_p.h"
#include "service/service_base.h"
#include "websocket/protocol/proto_info.h"

UserList::UserList(QObject *parent) :
    Client(new UserListPrivate(this), parent)
{

}

QQmlListProperty<User> UserList::list()
{
    return QQmlListProperty<User>(this, d_func(),
                                  &UserListPrivate::append,
                                  &UserListPrivate::count,
                                  &UserListPrivate::at,
                                  &UserListPrivate::clear);
}

void UserList::pull()
{
    Q_D(UserList);
    if(d->protocol && d->service){
        d->protocol->pull();
    }
}

void UserList::push(User *user)
{
    Q_D(UserList);
    if(d->protocol && d->service){
        d->protocol->push(user);
    }
}

void UserList::setService(ServiceBase *servie)
{
    Client::setService(servie);

    Q_D(UserList);
    if(d->protocol == Q_NULLPTR){
        if(d->service){
            d->protocol = static_cast<ProtoInfo*>(d->service->protocol(d->protocolName));

            if(d->protocol){

                QObject::connect(d->protocol, &ProtoInfo::actionRecived,
                                 [this,d](ProtoInfo::Actions action, const QJsonValue &data){

                    Q_UNUSED(data);
                    switch (action) {
                    case ProtoInfo::heartBeat:
                        //nothing
                        break;
                    case ProtoInfo::updateDeviceInfo:
                        Q_EMIT pushCompleted();
                        break;
                    case ProtoInfo::getDeviceList:
                        Q_EMIT pullCompleted();
                        break;
                    }
                });
            }
        }
    }
}

UserList::UserList(UserListPrivate *d, QObject *parent) :
    Client(d, parent)
{

}
