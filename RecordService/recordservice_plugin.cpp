#include "recordservice_plugin.h"
#include "account/account.h"
#include "model/device_model.h"

#include "sql_initialize.h"

#include <qqml.h>

//static
QObject *account_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Account *account = new Account();
    return account;
}

void RecordServicePlugin::registerTypes(const char *uri)
{
    // @uri com.nd.recordservice
    connectToDatabase();
    //qmlRegisterType<Account>(uri, 1, 0, "Account");
    qmlRegisterSingletonType<Account>(uri, 1, 0, "Account", account_singletontype_provider);
    qmlRegisterType<UserEntryModel>(uri, 1, 0, "UserEntryModel");
}
