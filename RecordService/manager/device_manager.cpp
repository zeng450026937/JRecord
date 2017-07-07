#include "device_manager.h"
#include <QDebug>
#include "device_manager_p.h"
#include "model/device_model.h"
#include "service/service_base.h"
#include "websocket/protocol/proto_info.h"
#include "websocket/task/task_manager.h"
#include "websocket/task/task_reply.h"

DeviceManager::DeviceManager(QObject *parent)
    : Client(new DeviceManagerPrivate(this), parent) {
  Q_D(DeviceManager);
  QObject::connect(
      this, &DeviceManager::serviceChanged, [this, d](ServiceBase *servie) {
        d->info_protocol =
            dynamic_cast<ProtoInfo *>(servie->protocol(ProtoBase::INFO_MODE));

        if (d->info_protocol) {
          QObject::connect(
              d->info_protocol, &ProtoInfo::actionReceived, this,
              [=](int action, const QJsonValue &data) {
                Q_UNUSED(data);
                QSharedPointer<TaskRequest> request;
                switch (action) {
                  case ProtoInfo::heartBeat:
                    request = d->info_protocol->makeRequest(
                        ProtoInfo::heartBeat, QJsonValue());

                    d->service->taskManager()->postMessage(request);
                    break;
                  case ProtoInfo::updateDeviceInfo:
                    d->updateDevice(data);
                    break;
                  default:
                    break;
                }
              });
        }
      });

  d->model = new DeviceModel(this);
}

Device *DeviceManager::device(const QString &uuid) const {
  return d_func()->deviceMap.value(uuid, Q_NULLPTR);
}

void DeviceManager::getDeviceList() {
  Q_D(DeviceManager);
  if (d->info_protocol) {
    QSharedPointer<TaskRequest> request =
        d->info_protocol->makeRequest(ProtoInfo::getDeviceList, QJsonValue());

    TaskReply *reply = d->service->taskManager()->postRequest(request);

    if (reply) {
      QObject::connect(reply, &TaskReply::finished, this, [=]() {
        d->updateDeviceList(reply->data());
        reply->deleteLater();
      });
      QObject::connect(reply, &TaskReply::timeout, this, [=]() {
        qDebug() << "get device list failed.";
        reply->deleteLater();
      });
    }
  }
}

DeviceModel *DeviceManager::model() const { return d_func()->model; }

DeviceManager::DeviceManager(DeviceManagerPrivate *d, QObject *parent)
    : Client(d, parent) {}
