#include "devicedescription.h"
#include "devicedescription_p.h"

DeviceDescription::DeviceDescription(QObject *parent) :
    QObject(parent),
    d_ptr(new DeviceDescriptionPrivate(this))
{

}

QString DeviceDescription::type() const
{
    return d_func()->type;
}

QString DeviceDescription::name() const
{
    return d_func()->name;
}

QString DeviceDescription::status() const
{
    return d_func()->status;
}

QString DeviceDescription::vad() const
{
    return d_func()->vad;
}

int DeviceDescription::percent() const
{
    return d_func()->percent;
}

int DeviceDescription::time() const
{
    return d_func()->time;
}

void DeviceDescription::setType(const QString &type)
{
    Q_D(DeviceDescription);
    if(type != d->type){
        d->type = type;
        Q_EMIT deviceChanged();
    }
}

void DeviceDescription::setName(const QString &name)
{
    Q_D(DeviceDescription);
    if(name != d->name){
        d->name = name;
        Q_EMIT deviceChanged();
    }
}

void DeviceDescription::setStatus(const QString &status)
{
    Q_D(DeviceDescription);
    if(status != d->status){
        d->status = status;
        Q_EMIT deviceChanged();
    }
}

void DeviceDescription::setVad(const QString &vad)
{
    Q_D(DeviceDescription);
    if(vad != d->vad){
        d->vad = vad;
        Q_EMIT deviceChanged();
    }
}

void DeviceDescription::setPercent(const int percent)
{
    Q_D(DeviceDescription);
    if(percent != d->percent){
        d->percent = percent;
        Q_EMIT deviceChanged();
    }
}

void DeviceDescription::setTime(const int time)
{
    Q_D(DeviceDescription);
    if(time != d->time){
        d->time = time;
        Q_EMIT deviceChanged();
    }
}

DeviceDescription::DeviceDescription(DeviceDescriptionPrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}
