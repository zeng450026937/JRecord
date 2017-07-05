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

        //        this->transport(QSharedPointer<MessagePacket>(new TextMessage(
        //            QStringLiteral(""), QStringLiteral(""), d->mode,
        //            d->metaEnum.valueToKey(Actions::heartBeat),
        //            QJsonObject())));
        break;
      case updateDeviceInfo:
        action = Actions::updateDeviceInfo;
        data = msg->data();
        break;
      case getDeviceList:
        action = Actions::getDeviceList;
        data = msg->data().toObject().value(QStringLiteral("list")).toArray();
        msg->setData(data);
        break;
      default:
        action = Actions::ActionCount;
        break;
    }

    Q_EMIT actionRecived(action, data);

    QMutexLocker locker(&d->mutex);
    if (d->taskQueue.count() > 0) {
      if (msg->match(d->taskQueue.takeFirst().data())) {
        msg->notify();
        qDebug() << msg->command() << "notify message";
      } else {
        qDebug() << msg->command()
                 << "message unmatch. it should be a notification from server.";
      }
    } else {
      qDebug() << msg->command()
               << "no queued message. it should be a notification from server.";
    }
  }
}

void ProtoInfo::push(Device *device) {
  Q_D(ProtoInfo);

  TextMessage *msg = new TextMessage(
      QStringLiteral(""), QStringLiteral(""), d->mode,
      d->metaEnum.valueToKey(Actions::updateDeviceInfo), device->toJson());

  this->transport(QSharedPointer<MessagePacket>(msg));
}

void ProtoInfo::pull(callbackFunc fp) {
  Q_D(ProtoInfo);

  TextMessage *msg = new TextMessage(
      QStringLiteral(""), QStringLiteral(""), d->mode,
      d->metaEnum.valueToKey(Actions::getDeviceList), QJsonObject());

  msg->setNotification(fp);

  this->transport(QSharedPointer<MessagePacket>(msg));
}
