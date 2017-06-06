#ifndef DEVICE_P_H
#define DEVICE_P_H

#include <QObject>

class User;
class Device;

class DevicePrivate
{
    Q_DISABLE_COPY(DevicePrivate)
    Q_DECLARE_PUBLIC(Device)
public:
    DevicePrivate(Device *q);

    Device *q_ptr;
    QString type;
    QString uuid;
    QString name;
    QString status;
    QString vad;
    int percent;
    int time;
    User *owner;
};

#endif // DEVICE_P_H
