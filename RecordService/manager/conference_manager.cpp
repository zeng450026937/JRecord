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

ConferenceManager::ConferenceManager(QObject *parent)
    : Client(new ConferenceManagerPrivate(this), parent) {
  Q_D(ConferenceManager);
  QObject::connect(
      this, &ConferenceManager::serviceChanged, [this, d](ServiceBase *servie) {
        d->conf_protocol = dynamic_cast<ProtoConf *>(
            servie->protocol(ProtoBase::CONFERENCE_MODE));

        QObject::connect(d->conf_protocol, &ProtoConf::actionRecived, this,
                         [this, d](const int action, const QJsonValue &data) {
                           switch (action) {
                             case ProtoConf::createConference:
                               break;
                             case ProtoConf::getConferenceList:
                               foreach (QJsonValue value, data.toArray()) {
                                 d->updateConference(Conference::Normal,
                                                     value.toObject());
                               }
                               break;

                             default:
                               break;
                           }
                         });

        d->person_protocol = dynamic_cast<ProtoPerson *>(
            servie->protocol(ProtoBase::PERSONAL_MODE));

        QObject::connect(d->person_protocol, &ProtoPerson::actionRecived, this,
                         [this, d](const int action, const QJsonValue &data) {
                           switch (action) {
                             case ProtoPerson::getPersonalList:
                               foreach (QJsonValue value, data.toArray()) {
                                 d->updateConference(Conference::Personal,
                                                     value.toObject());
                               }
                               break;
                             default:
                               break;
                           }
                         });

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
  d->person_protocol->query();
  d->conf_protocol->query();
}

ConferenceModel *ConferenceManager::model() const { return d_func()->model; }

ConferenceManager::ConferenceManager(ConferenceManagerPrivate *d,
                                     QObject *parent)
    : Client(d, parent) {}
