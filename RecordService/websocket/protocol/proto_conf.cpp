#include "proto_conf.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QMetaObject>
#include "proto_conf_p.h"
#include "service/service_base.h"
#include "websocket/task/task_manager.h"
#include "websocket/task/task_reply.h"
#include "websocket/task/task_request.h"
#include "websocket/textmessage.h"

ProtoConf::ProtoConf(QObject* parent)
    : ProtoBase(new ProtoConfPrivate(this), parent) {
  Q_D(ProtoConf);
  d->mode = ProtoBase::CONFERENCE_MODE;
  d->metaEnum = this->metaObject()->enumerator(
      this->metaObject()->indexOfEnumerator("Actions"));
}

void ProtoConf::process(QSharedPointer<MessagePacket> pkt) {
  QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
  if (msg) {
    const QMetaObject* MetaObject = this->metaObject();
    QMetaEnum MetaEnum =
        MetaObject->enumerator(MetaObject->indexOfEnumerator("Actions"));

    QJsonValue data;
    Actions action;
    switch (MetaEnum.keysToValue(msg->action().toUtf8())) {
      case Actions::lockDevice:
        action = Actions::lockDevice;
        data = msg->data();
        break;
      case Actions::unlockDevice:
        action = Actions::unlockDevice;
        data = msg->data();
        break;
      case Actions::createConference:
        action = Actions::createConference;
        data = msg->data();
        break;
      case Actions::startConference:
        action = Actions::startConference;
        data = msg->data();
        break;
      case Actions::getConferenceList:
        action = Actions::getConferenceList;
        data = msg->data().toObject().value(QStringLiteral("list"));
        msg->setData(data);
        break;
      case Actions::getConferenceFiles:
        action = Actions::getConferenceFiles;
        data = msg->data();
        break;
      default:
        action = Actions::unknown;
        break;
    }
    Q_EMIT actionReceived(action, data);
  }
}
