#include "account_p.h"

AccountPrivate::AccountPrivate(Account *q) :
    q_ptr(q),
    status(Account::Logout),
    active(false),
    userGroup(QStringLiteral("ND"))
{

}

bool AccountPrivate::getActive() const
{
    return active;
}

void AccountPrivate::setActive(bool value)
{
    active = value;
}

QString AccountPrivate::getErrorString() const
{
    return errorString;
}

void AccountPrivate::setErrorString(const QString &value)
{
    errorString = value;
}

QString AccountPrivate::getUserId() const
{
    return userId;
}

