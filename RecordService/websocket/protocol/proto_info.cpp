#include "proto_info.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMetaObject>
#include "device/device.h"
#include "proto_info_p.h"
#include "user/user.h"
#include "websocket/textmessage.h"

ProtoInfo::ProtoInfo(QObject *parent)
    : ProtoBase(new ProtoInfoPrivate(this), parent) {
  Q_D(ProtoInfo);
  d->mode = QStringLiteral("info");
  d->metaEnum = this->metaObject()->enumerator(
      this->metaObject()->indexOfEnumerator("Actions"));
}

void ProtoInfo::process(QSharedPointer<MessagePacket> pkt) {
  QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
  if (msg) {
    Q_D(ProtoInfo);

    QJsonValue data;
    Actions action;
    switch (d->metaEnum.keysToValue(msg->action().toUtf8())) {
      case heartBeat:
        action = Actions::heartBeat;
        this->beat();
        break;
      case updateDeviceInfo:
        action = Actions::updateDeviceInfo;
        data = QJsonObject::fromVariantMap(msg->data());
        break;
      case notifyDeviceInfoChange:
        action = Actions::notifyDeviceInfoChange;
        data = QJsonObject::fromVariantMap(msg->data());
        break;
      case getDeviceList:
        action = Actions::getDeviceList;
        data = QJsonArray::fromVariantList(
            msg->data().value(QStringLiteral("list")).toList());
        break;
      default:
        action = Actions::ActionCount;
        break;
    }

    Q_EMIT actionRecived(action, data);
  }
}

void ProtoInfo::beat() {
  Q_D(ProtoInfo);

  this->transport(QStringLiteral(""), QStringLiteral(""),
                  d->metaEnum.valueToKey(Actions::heartBeat), QVariantMap());
}

void ProtoInfo::push(Device *device) {
  Q_D(ProtoInfo);

  QVariantMap data;
  data.insert(QStringLiteral("deviceUuid"), device->uuid());
  data.insert(QStringLiteral("deviceName"), device->name());
  data.insert(QStringLiteral("deviceType"), device->type());
  data.insert(QStringLiteral("batteryPercent"), device->percent());
  data.insert(QStringLiteral("batteryTime"), device->time());
  data.insert(QStringLiteral("status"), device->status());
  data.insert(QStringLiteral("vad"), device->vad());
  data.insert(QStringLiteral("userId"), device->owner()->userId());
  data.insert(QStringLiteral("userName"), device->owner()->userName());
  data.insert(QStringLiteral("userGroup"), device->owner()->userGroup());

  this->transport(QStringLiteral(""), QStringLiteral(""),
                  d->metaEnum.valueToKey(Actions::updateDeviceInfo), data);
}

void ProtoInfo::pull() {
  Q_D(ProtoInfo);

  this->transport(QStringLiteral(""), QStringLiteral(""),
                  d->metaEnum.valueToKey(Actions::getDeviceList),
                  QVariantMap());
}
