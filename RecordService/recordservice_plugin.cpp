#include "recordservice_plugin.h"
#include "account/account.h"

#include <qqml.h>

void RecordServicePlugin::registerTypes(const char *uri)
{
    // @uri com.nd.recordservice
    qmlRegisterType<Account>(uri, 1, 0, "Account");
}

