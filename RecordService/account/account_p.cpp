#include "account_p.h"

AccountPrivate::AccountPrivate(Account *q)
    : q_ptr(q),
      status(Account::Logout),
      active(false),
      userGroup(QStringLiteral("ND")) {}
