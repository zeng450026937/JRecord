#ifndef USER_P_H
#define USER_P_H

#include <QObject>
#include "devicedescription.h"

class User;

class UserPrivate
{
    Q_DECLARE_PUBLIC(User)
public:
    UserPrivate(User* q);

    User* q_ptr;

    QString userId;
    QString userGroup;
    QString userName;
    DeviceDescription device;
};

#endif // USER_P_H
