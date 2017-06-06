#include "devicedescription_p.h"

DeviceDescriptionPrivate::DeviceDescriptionPrivate(DeviceDescription *q) :
    q_ptr(q),
    type(QStringLiteral("PC")),
    percent(0),
    time(0)
{

}
