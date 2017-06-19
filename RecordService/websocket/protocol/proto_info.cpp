#include "proto_info.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMetaObject>
#include "device/device.h"
#include "proto_info_p.h"
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
  data.insert(QStringLiteral("deviceName"), device->name());
  data.insert(QStringLiteral("batteryPercent"), device->percent());
  data.insert(QStringLiteral("batteryTime"), device->time());
  data.insert(QStringLiteral("status"), device->status());
  data.insert(QStringLiteral("vad"), device->vad());

  this->transport(QStringLiteral(""), QStringLiteral(""),
                  d->metaEnum.valueToKey(Actions::updateDeviceInfo), data);
}

void ProtoInfo::pull() {
  Q_D(ProtoInfo);

  this->transport(QStringLiteral(""), QStringLiteral(""),
                  d->metaEnum.valueToKey(Actions::getDeviceList),
                  QVariantMap());
}
