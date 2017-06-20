#include "conference_manager.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include "conference/conference.h"
#include "conference_manager_p.h"
#include "device/device.h"
#include "model/conference_model.h"
#include "service/service_base.h"
#include "user/user.h"
#include "websocket/protocol/proto_conf.h"
#include "websocket/protocol/proto_person.h"

ConferenceManager::ConferenceManager(QObject *parent)
    : Client(new ConferenceManagerPrivate(this), parent) {
  Q_D(ConferenceManager);
  QObject::connect(
      this, &ConferenceManager::serviceChanged, [this, d](ServiceBase *servie) {
        d->conf_protocol =
            (ProtoConf *)servie->protocol(QStringLiteral("conference"));

        QObject::connect(d->conf_protocol, &ProtoConf::actionRecived, this,
                         [this, d](const int action, const QJsonValue &data) {
                           Conference *conference(Q_NULLPTR);
                           switch (action) {
                             case ProtoConf::createConference:
                               break;
                             default:
                               break;
                           }
                         });

        d->person_protocol =
            (ProtoPerson *)servie->protocol(QStringLiteral("personal"));

        QObject::connect(
            d->person_protocol, &ProtoPerson::actionRecived, this,
            [this, d](const int action, const QJsonValue &data) {
              Conference *conference(Q_NULLPTR);
              switch (action) {
                case ProtoPerson::getPersonalList:
                  d->model->clearAll();
                  foreach (QJsonValue value, data.toArray()) {
                    conference = new Conference(
                        Conference::Personal, value.toVariant().toMap(), this);
                    conference->setService(d->service);
                    d->confMap.insert(conference->uuid(), conference);
                    d->model->addConference(conference);
                  }
                  break;
                default:
                  break;
              }
            });
      });

  d->model = new ConferenceModel(this);
}

Conference *ConferenceManager::conference(const QString &uuid) const {
  return d_func()->confMap.value(uuid, Q_NULLPTR);
}

void ConferenceManager::refresh() {
  Q_D(ConferenceManager);
  QString userId = d->service->device()->owner()->userId();
  d->person_protocol->query(userId);

  d->conf_protocol->query();
}

ConferenceModel *ConferenceManager::model() const { return d_func()->model; }

ConferenceManager::ConferenceManager(ConferenceManagerPrivate *d,
                                     QObject *parent)
    : Client(d, parent) {}
