#include "recordservice_plugin.h"
#include <qqml.h>
#include "account/account.h"
#include "account/nd_account.h"
#include "client/client.h"
#include "client/client_p.h"
#include "conference/conference.h"
#include "conference/conference_p.h"
#include "device/device.h"
#include "device/device_p.h"
#include "manager/conference_manager.h"
#include "manager/conference_manager_p.h"
#include "manager/device_manager.h"
#include "manager/device_manager_p.h"
#include "model/conference_model.h"
#include "model/conference_model_p.h"
#include "model/device_model.h"
#include "model/device_model_p.h"
#include "model/sql_initializer.h"
#include "service/service_base.h"
#include "user/user.h"
#include "user/user_p.h"

// static
QObject *nd_account_singletontype_provider(QQmlEngine *engine,
                                           QJSEngine *scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  NdAccount *account = new NdAccount();
  return account;
}
// static
QObject *service_singletontype_provider(QQmlEngine *engine,
                                        QJSEngine *scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  ServiceBase *service = new ServiceBase();
  return service;
}

void RecordServicePlugin::registerTypes(const char *uri) {
  // @uri com.nd.recordservice
  connectToDatabase();

  qmlRegisterType<Client>(uri, 1, 0, "Client");

  qmlRegisterType<User>(uri, 1, 0, "User");
  qmlRegisterType<Device>(uri, 1, 0, "Device");
  qmlRegisterType<DeviceModel>(uri, 1, 0, "DeviceModel");
  qmlRegisterType<DeviceManager>(uri, 1, 0, "DeviceManager");
  qmlRegisterType<Conference>(uri, 1, 0, "Conference");
  qmlRegisterType<ConferenceModel>(uri, 1, 0, "ConferenceModel");
  qmlRegisterType<ConferenceManager>(uri, 1, 0, "ConferenceManager");

  qmlRegisterUncreatableType<Account>(uri, 1, 0, "Account",
                                      "Should not create Account.");
  qmlRegisterSingletonType<NdAccount>(uri, 1, 0, "NdAccount",
                                      nd_account_singletontype_provider);

  qmlRegisterSingletonType<ServiceBase>(uri, 1, 0, "ServiceBase",
                                        service_singletontype_provider);
}
