#include "proto_info.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMetaObject>
#include "device/device.h"
#include "proto_info_p.h"
#include "user/user.h"
#include "websocket/task/task_manager.h"
#include "websocket/task/task_reply.h"
#include "websocket/task/task_request.h"
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
        break;
      case updateDeviceInfo:
        action = Actions::updateDeviceInfo;
        data = msg->data();
        break;
      case getDeviceList:
        action = Actions::getDeviceList;
        data = msg->data().toObject().value(QStringLiteral("list"));
        msg->setData(data);
        break;
      default:
        action = Actions::ActionCount;
        break;
    }
    Q_EMIT actionReceived(action, data);
  }
}
