#include "proto_person.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMetaObject>
#include "proto_person_p.h"
#include "service/service_base.h"
#include "websocket/textmessage.h"

ProtoPerson::ProtoPerson(QObject* parent)
    : ProtoBase(new ProtoPersonPrivate(this), parent) {
  Q_D(ProtoPerson);
  d->mode = QStringLiteral("personal");
  d->metaEnum = this->metaObject()->enumerator(
      this->metaObject()->indexOfEnumerator("Actions"));
}

void ProtoPerson::process(QSharedPointer<MessagePacket> pkt) {
  QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
  if (msg) {
    const QMetaObject* MetaObject = this->metaObject();
    QMetaEnum MetaEnum =
        MetaObject->enumerator(MetaObject->indexOfEnumerator("Actions"));

    QJsonValue data;
    Actions action;
    switch (MetaEnum.keysToValue(msg->action().toUtf8())) {
      case getPersonalList:
        action = Actions::getPersonalList;
        data = QJsonArray::fromVariantList(
            msg->data().value(QStringLiteral("list")).toList());
        break;
      default:
        action = Actions::unknown;
        break;
    }

    Q_EMIT actionRecived(action, data);
  }
}

void ProtoPerson::query(const QString& userId) {
  Q_D(ProtoPerson);

  QVariantMap data;
  data.insert(QStringLiteral("userId"), userId);

  this->transport(QStringLiteral(""), QStringLiteral(""),
                  d->metaEnum.valueToKey(Actions::getPersonalList), data);
}
