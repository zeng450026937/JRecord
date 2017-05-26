#include "recordservice_plugin.h"
#include "account/account.h"
#include "service/service_base.h"
#include <qqml.h>

//static
QObject *account_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Account *account = new Account();
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

    //init sqlite database(TBD)
    //init service(TBD)

    //qmlRegisterType<Account>(uri, 1, 0, "Account");
    qmlRegisterSingletonType<Account>(uri, 1, 0, "Account", account_singletontype_provider);
    qmlRegisterSingletonType<ServiceBase>(uri, 1, 0, "ServiceBase", service_singletontype_provider);

}
