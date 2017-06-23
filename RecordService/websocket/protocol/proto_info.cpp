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
  d->mode = ProtoBase::INFO_MODE;
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
        data = msg->data();
        break;
      case notifyDeviceInfoChange:
        action = Actions::notifyDeviceInfoChange;
        data = msg->data();
        break;
      case getDeviceList:
        action = Actions::getDeviceList;
        data = msg->data().value(QStringLiteral("list")).toArray();
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
                  d->metaEnum.valueToKey(Actions::heartBeat), QJsonObject());
}

void ProtoInfo::push(Device *device) {
  Q_D(ProtoInfo);

  this->transport(QStringLiteral(""), QStringLiteral(""),
                  d->metaEnum.valueToKey(Actions::updateDeviceInfo),
                  device->toJson());
}

void ProtoInfo::pull() {
  Q_D(ProtoInfo);

  this->transport(QStringLiteral(""), QStringLiteral(""),
                  d->metaEnum.valueToKey(Actions::getDeviceList),
                  QJsonObject());
}
