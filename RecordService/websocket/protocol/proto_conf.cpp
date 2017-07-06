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
  }
}

TaskReply* ProtoConf::lock() {
  TaskReply* reply(Q_NULLPTR);
  return reply;
}

TaskReply* ProtoConf::unlock() {
  TaskReply* reply(Q_NULLPTR);
  return reply;
}

TaskReply* ProtoConf::create(const QString& title, const QString& content,
                             const QString& members, const QString& devices) {
  Q_D(ProtoConf);

  TaskReply* reply(Q_NULLPTR);

  if (d->taskManager) {
    QJsonObject data;
    data.insert(QStringLiteral("title"), title);
    data.insert(QStringLiteral("content"), content);
    data.insert(QStringLiteral("members"), members);
    data.insert(QStringLiteral("devices"), devices);

    QSharedPointer<TaskRequest> request(new TaskRequest);
    request->setMode(d->mode);
    request->setAction(d->metaEnum.valueToKey(Actions::createConference));
    request->setData(data);

    reply = d->taskManager->post(request);
  }
  return reply;
}

TaskReply* ProtoConf::start(const QString& uuid) {
  Q_D(ProtoConf);

  TaskReply* reply(Q_NULLPTR);

  if (d->taskManager) {
    QJsonObject data;
    data.insert(QStringLiteral("conferenceUuid"), uuid);

    QSharedPointer<TaskRequest> request(new TaskRequest);
    request->setMode(d->mode);
    request->setAction(d->metaEnum.valueToKey(Actions::startConference));
    request->setData(data);

    reply = d->taskManager->post(request);
  }
  return reply;
}

TaskReply* ProtoConf::pause(const QString& uuid) {
  Q_D(ProtoConf);

  TaskReply* reply(Q_NULLPTR);

  if (d->taskManager) {
    QJsonObject data;
    data.insert(QStringLiteral("conferenceUuid"), uuid);

    QSharedPointer<TaskRequest> request(new TaskRequest);
    request->setMode(d->mode);
    request->setAction(d->metaEnum.valueToKey(Actions::pauseConference));
    request->setData(data);

    reply = d->taskManager->post(request);
  }
  return reply;
}

TaskReply* ProtoConf::resume(const QString& uuid) {
  Q_D(ProtoConf);

  TaskReply* reply(Q_NULLPTR);

  if (d->taskManager) {
    QJsonObject data;
    data.insert(QStringLiteral("conferenceUuid"), uuid);

    QSharedPointer<TaskRequest> request(new TaskRequest);
    request->setMode(d->mode);
    request->setAction(d->metaEnum.valueToKey(Actions::resumeConference));
    request->setData(data);

    reply = d->taskManager->post(request);
  }
  return reply;
}

TaskReply* ProtoConf::stop(const QString& uuid) {
  Q_D(ProtoConf);

  TaskReply* reply(Q_NULLPTR);

  if (d->taskManager) {
    QJsonObject data;
    data.insert(QStringLiteral("conferenceUuid"), uuid);

    QSharedPointer<TaskRequest> request(new TaskRequest);
    request->setMode(d->mode);
    request->setAction(d->metaEnum.valueToKey(Actions::stopConference));
    request->setData(data);

    reply = d->taskManager->post(request);
  }
  return reply;
}

TaskReply* ProtoConf::join(const QString& uuid) {
  Q_D(ProtoConf);
  TaskReply* reply(Q_NULLPTR);

  if (d->taskManager) {
    QJsonObject data;
    data.insert(QStringLiteral("conferenceUuid"), uuid);

    QSharedPointer<TaskRequest> request(new TaskRequest);
    request->setMode(d->mode);
    request->setAction(d->metaEnum.valueToKey(Actions::stopConference));
    request->setData(data);

    reply = d->taskManager->post(request);
  }
  return reply;
}

TaskReply* ProtoConf::leave(const QString& uuid) {
  Q_D(ProtoConf);
  TaskReply* reply(Q_NULLPTR);

  if (d->taskManager) {
    QJsonObject data;
    data.insert(QStringLiteral("conferenceUuid"), uuid);

    QSharedPointer<TaskRequest> request(new TaskRequest);
    request->setMode(d->mode);
    request->setAction(d->metaEnum.valueToKey(Actions::stopConference));
    request->setData(data);

    reply = d->taskManager->post(request);
  }
  return reply;
}

TaskReply* ProtoConf::query(const QString& uuid) {
  Q_D(ProtoConf);

  TaskReply* reply(Q_NULLPTR);
  if (uuid.isEmpty()) {
    if (d->taskManager) {
      QSharedPointer<TaskRequest> request(new TaskRequest);
      request->setMode(d->mode);
      request->setAction(d->metaEnum.valueToKey(Actions::getConferenceList));
      request->setData(QJsonValue());

      reply = d->taskManager->post(request);
    }

  } else {
    if (d->taskManager) {
      QJsonObject data;
      data.insert(QStringLiteral("conferenceUuid"), uuid);

      QSharedPointer<TaskRequest> request(new TaskRequest);
      request->setMode(d->mode);
      request->setAction(d->metaEnum.valueToKey(Actions::getConferenceInfo));
      request->setData(data);

      reply = d->taskManager->post(request);
    }
  }
  return reply;
}

TaskReply* ProtoConf::files(const QString& uuid) {
  Q_D(ProtoConf);

  TaskReply* reply(Q_NULLPTR);

  if (d->taskManager) {
    QJsonObject data;
    data.insert(QStringLiteral("conferenceUuid"), uuid);

    QSharedPointer<TaskRequest> request(new TaskRequest);
    request->setMode(d->mode);
    request->setAction(d->metaEnum.valueToKey(Actions::getConferenceFiles));
    request->setData(data);

    reply = d->taskManager->post(request);
  }
  return reply;
}
