#include "authorization_p.h"
#include "auth/authorization.h"

AuthorizationPrivate::AuthorizationPrivate(Authorization *q) :
    q_ptr(q),
    userGroup(QStringLiteral("ND")),
    deviceType(QStringLiteral("PC")),
    authorized(false),
    socket(Q_NULLPTR)
{

}

void AuthorizationPrivate::onConnected()
{
    Q_Q(Authorization);
    authorized = true;
    Q_EMIT q->authorizedChanged(authorized);
}

void AuthorizationPrivate::onDisConnected()
{
    Q_Q(Authorization);
    authorized = false;
    Q_EMIT q->authorizedChanged(authorized);
}
