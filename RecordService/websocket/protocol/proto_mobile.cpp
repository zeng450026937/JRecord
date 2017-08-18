#include "proto_mobile.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMetaObject>
#include "proto_mobile_p.h"
#include "service/service_base.h"
#include "websocket/task/task_manager.h"
#include "websocket/task/task_reply.h"
#include "websocket/task/task_request.h"
#include "websocket/textmessage.h"

ProtoMobile::ProtoMobile(QObject* parent)
    : ProtoBase(new ProtoMobilePrivate(this), parent) {
  Q_D(ProtoMobile);
  d->mode = ProtoBase::MOBILE_MODE;
  d->metaEnum = this->metaObject()->enumerator(
      this->metaObject()->indexOfEnumerator("Actions"));
}

void ProtoMobile::process(QSharedPointer<MessagePacket> pkt) {
  QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
  if (msg) {
    const QMetaObject* MetaObject = this->metaObject();
    QMetaEnum MetaEnum =
        MetaObject->enumerator(MetaObject->indexOfEnumerator("Actions"));

    QJsonValue data;
    Actions action;
    switch (MetaEnum.keysToValue(msg->action().toUtf8())) {
      case getConferences:
        action = Actions::getConferences;
        data = msg->data().toObject().value(QStringLiteral("list"));
        msg->setData(data);
        break;
      default:
        action = Actions::unknown;
        break;
    }
    Q_EMIT actionReceived(action, data);
  }
}
