#include "device_p.h"

DevicePrivate::DevicePrivate(Device *q) :
    ClientPrivate(q),
    percent(0),
    time(0),
    lock(false),
    owner(Q_NULLPTR)
{

}
