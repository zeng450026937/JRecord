#include "conference_manager.h"
#include <QDebug>
#include "conference/conference.h"
#include "conference_manager_p.h"
#include "device/device.h"
#include "model/conference_model.h"
#include "service/service_base.h"
#include "user/user.h"
#include "websocket/protocol/proto_conf.h"
#include "websocket/protocol/proto_mobile.h"
#include "websocket/protocol/proto_person.h"
#include "websocket/task/task_reply.h"

ConferenceManager::ConferenceManager(QObject *parent)
    : Client(new ConferenceManagerPrivate(this), parent) {
  Q_D(ConferenceManager);
  QObject::connect(this, &ConferenceManager::serviceChanged,
                   [this, d](ServiceBase *servie) {
                     d->conf_protocol = dynamic_cast<ProtoConf *>(
                         servie->protocol(ProtoBase::CONFERENCE_MODE));

                     d->person_protocol = dynamic_cast<ProtoPerson *>(
                         servie->protocol(ProtoBase::PERSONAL_MODE));

                     d->mobile_protocol = dynamic_cast<ProtoMobile *>(
                         servie->protocol(ProtoBase::MOBILE_MODE));
                   });

  d->model = new ConferenceModel(this);
}

Conference *ConferenceManager::conference(const QString &uuid) const {
  return d_func()->confMap.value(uuid, Q_NULLPTR);
}

void ConferenceManager::refresh() {
  Q_D(ConferenceManager);

  TaskReply *reply(Q_NULLPTR);
  reply = d->person_protocol->query();
  if (reply) {
    QObject::connect(reply, &TaskReply::finished, this, [=]() {
      d->updateConferenceList(Conference::Personal, reply->data());
      reply->deleteLater();
    });
  }
  reply = d->conf_protocol->query();
  if (reply) {
    QObject::connect(reply, &TaskReply::finished, this, [=]() {
      d->updateConferenceList(Conference::Normal, reply->data());
      reply->deleteLater();
    });
  }
}

ConferenceModel *ConferenceManager::model() const { return d_func()->model; }

ConferenceManager::ConferenceManager(ConferenceManagerPrivate *d,
                                     QObject *parent)
    : Client(d, parent) {}
