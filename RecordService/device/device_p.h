#ifndef DEVICE_P_H
#define DEVICE_P_H

#include "client/client_p.h"
#include "device.h"

class User;
class Device;

class DevicePrivate : public ClientPrivate
{
    Q_DISABLE_COPY(DevicePrivate)
    Q_DECLARE_PUBLIC(Device)
public:
    DevicePrivate(Device *q);

    QString type;
    QString uuid;
    QString name;
    QString status;
    QString vad;
    int percent;
    int time;
    bool lock;
    User *owner;
};

#endif // DEVICE_P_H
