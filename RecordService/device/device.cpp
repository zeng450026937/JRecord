#include "device.h"
#include "device_p.h"
#include "user/user.h"

Device::Device(QObject *parent) : Client(new DevicePrivate(this), parent) {
  Q_D(Device);
  d->owner = new User(this);
}

Device::Device(const QJsonObject &json, QObject *parent)
    : Client(new DevicePrivate(this), parent) {
  Q_D(Device);
  d->owner = new User(this);
  this->fromJson(json);
}

void Device::fromJson(const QJsonObject &json) {
  Q_D(Device);
  if (d->owner) {
    d->owner->setUserId(json.value(QStringLiteral("userId")).toString());
    d->owner->setUserName(json.value(QStringLiteral("userName")).toString());
    d->owner->setUserGroup(json.value(QStringLiteral("userGroup")).toString());
  }

  this->setUuid(json.value(QStringLiteral("deviceUuid")).toString());
  this->setName(json.value(QStringLiteral("deviceName")).toString());
  this->setType(json.value(QStringLiteral("deviceType")).toString());
  this->setStatus(json.value(QStringLiteral("status")).toString());
  this->setPercent(json.value(QStringLiteral("batteryPercent")).toInt());
  this->setTime(json.value(QStringLiteral("batteryTime")).toInt());
  this->setVad(json.value(QStringLiteral("vad")).toString());
}

QJsonObject Device::toJson() {
  QJsonObject json;
  Q_D(Device);

  if (d->owner) {
    json.insert(QStringLiteral("userId"), d->owner->userId());
    json.insert(QStringLiteral("userName"), d->owner->userName());
    json.insert(QStringLiteral("userGroup"), d->owner->userGroup());
  }
  json.insert(QStringLiteral("deviceUuid"), d->uuid);
  json.insert(QStringLiteral("deviceName"), d->name);
  json.insert(QStringLiteral("deviceType"), d->type);
  json.insert(QStringLiteral("status"), d->status);
  json.insert(QStringLiteral("batteryPercent"), d->percent);
  json.insert(QStringLiteral("batteryTime"), d->time);
  json.insert(QStringLiteral("vad"), d->vad);

  return json;
}

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
  if (type.isEmpty()) return;
  if (type != d->type) {
    d->type = type;
    Q_EMIT typeChanged(d->type);
  }
}

void Device::setUuid(const QString &uuid) {
  Q_D(Device);
  if (uuid.isEmpty()) return;
  if (uuid != d->uuid) {
    d->uuid = uuid;
    Q_EMIT uuidChanged(d->uuid);
  }
}

void Device::setName(const QString &name) {
  Q_D(Device);
  if (name.isEmpty()) return;
  if (name != d->name) {
    d->name = name;
    Q_EMIT nameChanged(d->name);
  }
}

void Device::setStatus(const QString &status) {
  Q_D(Device);
  if (status.isEmpty()) return;
  if (status != d->status) {
    d->status = status;
    Q_EMIT statusChanged(d->status);
  }
}

void Device::setVad(const QString &vad) {
  Q_D(Device);
  if (vad.isEmpty()) return;
  if (vad != d->vad) {
    d->vad = vad;
    Q_EMIT vadChanged(d->vad);
  }
}

void Device::setPercent(const int percent) {
  Q_D(Device);
  if (percent < 0) return;
  if (percent != d->percent) {
    d->percent = percent;
    Q_EMIT percentChanged(d->percent);
  }
}

void Device::setTime(const int time) {
  Q_D(Device);
  if (time < 0) return;
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
  if (owner == Q_NULLPTR) return;
  if (owner != d->owner) {
    if (d->owner) d->owner->deleteLater();
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

Device::Device(DevicePrivate *d, QObject *parent) : Client(d, parent) {}
