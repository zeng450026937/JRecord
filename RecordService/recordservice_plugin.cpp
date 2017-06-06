#include "recordservice_plugin.h"
#include "account/account.h"
#include "account/nd_account.h"
#include "model/sql_initializer.h"
#include "model/user_model.h"
#include "model/user_model_p.h"
#include "service/service_base.h"
#include "service/service_base_p.h"
#include "device/device.h"
#include "device/device_p.h"
#include "user/user.h"
#include "user/user_p.h"
#include "client/client.h"
#include "client/client_p.h"
#include "conference/conference.h"
#include "conference/conference_p.h"
#include <qqml.h>

//static
QObject *nd_account_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    NdAccount *account = new NdAccount();
    return account;
}
//static
QObject *service_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    ServiceBase *service = new ServiceBase();
    return service;
}

void RecordServicePlugin::registerTypes(const char *uri)
{
    // @uri com.nd.recordservice
    connectToDatabase();

    qmlRegisterType<UserModel>(uri, 1, 0, "UserModel");
    qmlRegisterType<Conference>(uri, 1, 0, "Conference");
    qmlRegisterType<Client>(uri, 1, 0, "Client");
    qmlRegisterType<Device>(uri, 1, 0, "Device");
    qmlRegisterType<User>(uri, 1, 0, "User");
    qmlRegisterUncreatableType<Account>(uri, 1, 0, "Account", "Should not create Account.");
    qmlRegisterSingletonType<NdAccount>(uri, 1, 0, "NdAccount", nd_account_singletontype_provider);
    qmlRegisterSingletonType<ServiceBase>(uri, 1, 0, "ServiceBase", service_singletontype_provider);

}
