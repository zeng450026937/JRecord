#include "user_p.h"
#include "devicedescription.h"

UserPrivate::UserPrivate(User *q) :
    q_ptr(q),
    userGroup(QStringLiteral("ND")),
    device(new DeviceDescription)
{

}

UserPrivate::~UserPrivate()
{
    delete device;
}
