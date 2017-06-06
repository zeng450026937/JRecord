#ifndef USER_P_H
#define USER_P_H

#include <QObject>

class DeviceDescription;
class User;

class UserPrivate
{
    Q_DISABLE_COPY(UserPrivate)
    Q_DECLARE_PUBLIC(User)
public:
    UserPrivate(User* q);
    ~UserPrivate();

    User* q_ptr;

    QString userId;
    QString userGroup;
    QString userName;
    DeviceDescription *device;
};

#endif // USER_P_H
