#include "proto_conf.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QMetaObject>
#include "proto_conf_p.h"
#include "service/service_base.h"
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
        data = msg->data().toObject().value(QStringLiteral("list")).toArray();
        break;
      case Actions::getConferenceFiles:
        action = Actions::getConferenceFiles;
        data = msg->data();
        break;
      default:
        action = Actions::unknown;
        break;
    }

    Q_EMIT actionRecived(action, data);
  }
}

void ProtoConf::lock() {}

void ProtoConf::unlock() {}

void ProtoConf::create(const QString& title, const QString& content,
                       const QString& members, const QString& devices) {
  Q_D(ProtoConf);

  QJsonObject data;
  data.insert(QStringLiteral("title"), title);
  data.insert(QStringLiteral("content"), content);
  data.insert(QStringLiteral("members"), members);
  data.insert(QStringLiteral("devices"), devices);

  TextMessage* msg =
      new TextMessage(QStringLiteral(""), QStringLiteral(""), d->mode,
                      d->metaEnum.valueToKey(Actions::createConference), data);

  this->transport(QSharedPointer<MessagePacket>(msg));
}

void ProtoConf::start(const QString& uuid) {
  Q_D(ProtoConf);

  QJsonObject data;
  data.insert(QStringLiteral("conferenceUuid"), uuid);

  TextMessage* msg =
      new TextMessage(QStringLiteral(""), QStringLiteral(""), d->mode,
                      d->metaEnum.valueToKey(Actions::startConference), data);

  this->transport(QSharedPointer<MessagePacket>(msg));
}

void ProtoConf::pause(const QString& uuid) {
  Q_D(ProtoConf);

  QJsonObject data;
  data.insert(QStringLiteral("conferenceUuid"), uuid);

  TextMessage* msg =
      new TextMessage(QStringLiteral(""), QStringLiteral(""), d->mode,
                      d->metaEnum.valueToKey(Actions::pauseConference), data);

  this->transport(QSharedPointer<MessagePacket>(msg));
}

void ProtoConf::resume(const QString& uuid) {
  Q_D(ProtoConf);

  QJsonObject data;
  data.insert(QStringLiteral("conferenceUuid"), uuid);

  TextMessage* msg =
      new TextMessage(QStringLiteral(""), QStringLiteral(""), d->mode,
                      d->metaEnum.valueToKey(Actions::resumeConference), data);

  this->transport(QSharedPointer<MessagePacket>(msg));
}

void ProtoConf::stop(const QString& uuid) {
  Q_D(ProtoConf);

  QJsonObject data;
  data.insert(QStringLiteral("conferenceUuid"), uuid);

  TextMessage* msg =
      new TextMessage(QStringLiteral(""), QStringLiteral(""), d->mode,
                      d->metaEnum.valueToKey(Actions::stopConference), data);

  this->transport(QSharedPointer<MessagePacket>(msg));
}

void ProtoConf::join(const QString& uuid) {}

void ProtoConf::leave(const QString& uuid) {}

void ProtoConf::query(const QString& uuid) {
  Q_D(ProtoConf);

  if (uuid.isEmpty()) {
    TextMessage* msg = new TextMessage(
        QStringLiteral(""), QStringLiteral(""), d->mode,
        d->metaEnum.valueToKey(Actions::getConferenceList), QJsonObject());

    this->transport(QSharedPointer<MessagePacket>(msg));
  } else {
    QJsonObject data;
    data.insert(QStringLiteral("conferenceUuid"), uuid);

    TextMessage* msg = new TextMessage(
        QStringLiteral(""), QStringLiteral(""), d->mode,
        d->metaEnum.valueToKey(Actions::getConferenceInfo), data);

    this->transport(QSharedPointer<MessagePacket>(msg));
  }
}

void ProtoConf::files(const QString& uuid) {
  Q_D(ProtoConf);

  QJsonObject data;
  data.insert(QStringLiteral("conferenceUuid"), uuid);

  TextMessage* msg = new TextMessage(
      QStringLiteral(""), QStringLiteral(""), d->mode,
      d->metaEnum.valueToKey(Actions::getConferenceFiles), data);

  this->transport(QSharedPointer<MessagePacket>(msg));
}
