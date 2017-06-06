#ifndef ACCOUNT_P_H
#define ACCOUNT_P_H

#include "account/account.h"

class AccountPrivate
{
    Q_DISABLE_COPY(AccountPrivate)
    Q_DECLARE_PUBLIC(Account)
public:
    AccountPrivate(Account *q);

    Account *q_ptr;
    Account::Status status;
    QString userId;
    QString userName;
    QString userGroup;
    QString password;
    QString image;
    QString signature;
    QString errorString;
    bool active;
};

#endif // ACCOUNT_P_H
