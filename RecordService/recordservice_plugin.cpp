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
#include "manager/device_manager.h"
#include "manager/device_manager_p.h"
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

  qmlRegisterType<DeviceModel>(uri, 1, 0, "DeviceModel");
  qmlRegisterType<Client>(uri, 1, 0, "Client");

  qmlRegisterType<Conference>(uri, 1, 0, "Conference");
  qmlRegisterType<User>(uri, 1, 0, "User");
  qmlRegisterType<Device>(uri, 1, 0, "Device");
  qmlRegisterType<DeviceManager>(uri, 1, 0, "DeviceManager");

  qmlRegisterUncreatableType<Account>(uri, 1, 0, "Account",
                                      "Should not create Account.");
  qmlRegisterSingletonType<NdAccount>(uri, 1, 0, "NdAccount",
                                      nd_account_singletontype_provider);

  qmlRegisterSingletonType<ServiceBase>(uri, 1, 0, "ServiceBase",
                                        service_singletontype_provider);
}
