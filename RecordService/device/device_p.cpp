#include "device_p.h"

DevicePrivate::DevicePrivate(Device *q) :
    q_ptr(q),
    percent(0),
    time(0),
    owner(Q_NULLPTR)
{

}
