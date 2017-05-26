#ifndef DEVICEDESCRIPTION_P_H
#define DEVICEDESCRIPTION_P_H

#include <QObject>

class DeviceDescription;

class DeviceDescriptionPrivate
{
    Q_DISABLE_COPY(DeviceDescriptionPrivate)
    Q_DECLARE_PUBLIC(DeviceDescription)
public:
    DeviceDescriptionPrivate(DeviceDescription *q);

    DeviceDescription *q_ptr;
    QString type;
    QString name;
    QString status;
    QString vad;
    int percent;
    int time;
};

#endif // DEVICEDESCRIPTION_P_H
