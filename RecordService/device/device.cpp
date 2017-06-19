#include "device.h"
#include "device_p.h"
#include "user/user.h"

Device::Device(QObject *parent) : Client(new DevicePrivate(this), parent) {}

QString Device::type() const { return d_func()->type; }

QString Device::uuid() const { return d_func()->uuid; }

QString Device::name() const { return d_func()->name; }

QString Device::status() const { return d_func()->status; }

QString Device::vad() const { return d_func()->vad; }

int Device::percent() const { return d_func()->percent; }

int Device::time() const { return d_func()->time; }

bool Device::lock() const { return d_func()->lock; }

User *Device::owner() const { return d_func()->owner; }

void Device::setType(const QString &type) {
  Q_D(Device);
  if (type != d->type) {
    d->type = type;
    Q_EMIT typeChanged(d->type);
  }
}

void Device::setUuid(const QString &uuid) {
  Q_D(Device);
  if (uuid != d->uuid) {
    d->uuid = uuid;
    Q_EMIT uuidChanged(d->uuid);
  }
}

void Device::setName(const QString &name) {
  Q_D(Device);
  if (name != d->name) {
    d->name = name;
    Q_EMIT nameChanged(d->name);
  }
}

void Device::setStatus(const QString &status) {
  Q_D(Device);
  if (status != d->status) {
    d->status = status;
    Q_EMIT statusChanged(d->status);
  }
}

void Device::setVad(const QString &vad) {
  Q_D(Device);
  if (vad != d->vad) {
    d->vad = vad;
    Q_EMIT vadChanged(d->vad);
  }
}

void Device::setPercent(const int percent) {
  Q_D(Device);
  if (percent != d->percent) {
    d->percent = percent;
    Q_EMIT percentChanged(d->percent);
  }
}

void Device::setTime(const int time) {
  Q_D(Device);
  if (time != d->time) {
    d->time = time;
    Q_EMIT timeChanged(d->time);
  }
}

void Device::setLock(const bool lock) {
  Q_D(Device);
  if (lock != d->lock) {
    d->lock = lock;
    Q_EMIT lockChanged(d->lock);
  }
}

void Device::setOwner(User *owner) {
  Q_D(Device);
  if (owner != d->owner) {
    d->owner = owner;

    QObject::connect(d->owner, &User::userIdChanged,
                     [this, d](const QString &userId) {
                       Q_UNUSED(userId);
                       Q_EMIT ownerChanged(d->owner);
                     });
    QObject::connect(d->owner, &User::userGroupChanged,
                     [this, d](const QString &userGroup) {
                       Q_UNUSED(userGroup);
                       Q_EMIT ownerChanged(d->owner);
                     });
    QObject::connect(d->owner, &User::userNameChanged,
                     [this, d](const QString &userName) {
                       Q_UNUSED(userName);
                       Q_EMIT ownerChanged(d->owner);
                     });

    Q_EMIT ownerChanged(d->owner);
  }
}

Device::Device(const QVariantMap &data, QObject *parent)
    : Client(new DevicePrivate(this), parent) {
  Q_D(Device);
  d->owner = new User(this);
  d->owner->setUserId(data.value(QStringLiteral("userId")).toString());
  d->owner->setUserName(data.value(QStringLiteral("userName")).toString());
  d->owner->setUserGroup(data.value(QStringLiteral("userGroup")).toString());

  this->setUuid(data.value(QStringLiteral("deviceUuid")).toString());
  this->setName(data.value(QStringLiteral("deviceName")).toString());
  this->setType(data.value(QStringLiteral("deviceType")).toString());
  this->setStatus(data.value(QStringLiteral("status")).toString());
  this->setPercent(data.value(QStringLiteral("batteryPercent")).toInt());
  this->setTime(data.value(QStringLiteral("batteryTime")).toInt());
  this->setVad(data.value(QStringLiteral("vad")).toString());
}

Device::Device(DevicePrivate *d, QObject *parent) : Client(d, parent) {}
