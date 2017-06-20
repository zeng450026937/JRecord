#include "conference.h"
#include "conference_p.h"
#include "device/device.h"
#include "service/service_base.h"
#include "user/user.h"
#include "websocket/protocol/proto_conf.h"

Conference::Conference(QObject *parent)
    : Client(new ConferencePrivate(this), parent) {
  Q_D(Conference);
  d->host = new Device(this);
}

void Conference::fromVariant(const QVariantMap &data) {
  Q_D(Conference);

  if (d->type == Personal) {
    if (d->host) {
      d->host->owner()->setUserId(
          data.value(QStringLiteral("userId")).toString());
      d->host->owner()->setUserName(
          data.value(QStringLiteral("username")).toString());
      d->host->owner()->setUserGroup(
          data.value(QStringLiteral("userGroup")).toString());
      d->host->setUuid(data.value(QStringLiteral("deviceUuid")).toString());
      d->host->setName(data.value(QStringLiteral("deviceName")).toString());
    }

    this->setUuid(data.value(QStringLiteral("conferenceUuid")).toString());
    this->setGps(data.value(QStringLiteral("gpsAddress")).toString());
    this->setTag(data.value(QStringLiteral("tag")).toString());
  }
}

void Conference::create() {
  // TBD
}

void Conference::start() {
  // TBD
}

void Conference::pause() {
  // TBD
}

void Conference::resume() {
  // TBD
}

void Conference::stop() {
  // TBD
}

void Conference::query() {
  // TBD
}

QString Conference::uuid() const { return d_func()->uuid; }

Conference::Type Conference::type() const { return d_func()->type; }

Device *Conference::host() const { return d_func()->host; }

QString Conference::title() const { return d_func()->title; }

QString Conference::content() const { return d_func()->content; }

QString Conference::member() const { return d_func()->member; }

QString Conference::gps() const { return d_func()->gps; }

QString Conference::tag() const { return d_func()->tag; }

QDate Conference::createTime() const { return d_func()->createTime; }

QDate Conference::updateTime() const { return d_func()->updateTime; }

Conference::Status Conference::status() const { return d_func()->status; }

int Conference::count() const { return d_func()->count; }

QString Conference::errorString() const { return d_func()->errorString; }

void Conference::setUuid(const QString &uuid) {
  Q_D(Conference);
  if (uuid.isEmpty()) return;
  if (uuid != d->uuid) {
    d->uuid = uuid;
    Q_EMIT uuidChanged(d->uuid);
  }
}

void Conference::setType(Conference::Type type) {
  Q_D(Conference);
  if (type != d->type) {
    d->type = type;
    Q_EMIT typeChanged(d->type);
  }
}

void Conference::setHost(Device *host) {
  Q_D(Conference);
  if (host == Q_NULLPTR) return;
  if (host != d->host) {
    d->host = host;
    QObject::connect(d->host, &Device::ownerChanged,
                     [this, d](const User *owner) {
                       Q_UNUSED(owner);
                       Q_EMIT hostChanged(d->host);
                     });

    Q_EMIT hostChanged(d->host);
  }
}

void Conference::setTitle(const QString &title) {
  Q_D(Conference);
  if (title.isEmpty()) return;
  if (title != d->title) {
    d->title = title;
    Q_EMIT titleChanged(d->title);
  }
}

void Conference::setContent(const QString &content) {
  Q_D(Conference);
  if (content.isEmpty()) return;
  if (content != d->content) {
    d->content = content;
    Q_EMIT contentChanged(d->content);
  }
}

void Conference::setMember(const QString &member) {
  Q_D(Conference);
  if (member.isEmpty()) return;
  if (member != d->member) {
    d->member = member;
    Q_EMIT memberChanged(d->member);
  }
}

void Conference::setGps(const QString &gps) {
  Q_D(Conference);
  if (gps.isEmpty()) return;
  if (gps != d->gps) {
    d->gps = gps;
    Q_EMIT gpsChanged(d->gps);
  }
}

void Conference::setTag(const QString &tag) {
  Q_D(Conference);
  if (tag.isEmpty()) return;
  if (tag != d->tag) {
    d->tag = tag;
    Q_EMIT tagChanged(d->tag);
  }
}

void Conference::setCreateTime(const QDate &createTime) {
  Q_D(Conference);
  if (createTime != d->createTime) {
    d->createTime = createTime;
    Q_EMIT createTimeChanged(d->createTime);
  }
}

void Conference::setUpdateTime(const QDate &updateTime) {
  Q_D(Conference);
  if (updateTime != d->updateTime) {
    d->updateTime = updateTime;
    Q_EMIT updateTimeChanged(d->updateTime);
  }
}

void Conference::setStatus(const Conference::Status status) {
  Q_D(Conference);
  if (status != d->status) {
    d->status = status;
    Q_EMIT statusChanged(d->status);
  }
}

void Conference::setCount(const int count) {
  Q_D(Conference);
  if (count < 0) return;
  if (count != d->count) {
    d->count = count;
    Q_EMIT countChanged(d->count);
  }
}

void Conference::setErrorString(const QString &errorString) {
  Q_D(Conference);
  if (errorString != d->errorString) {
    d->errorString = errorString;
    Q_EMIT errorStringChanged(d->errorString);
  }
}

Conference::Conference(Type type, const QVariantMap &data, QObject *parent)
    : Client(new ConferencePrivate(this), parent) {
  Q_D(Conference);
  d->host = new Device(this);
  this->setType(type);

  this->fromVariant(data);
}

Conference::Conference(ConferencePrivate *d, QObject *parent)
    : Client(d, parent) {}
