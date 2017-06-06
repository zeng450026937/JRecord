#ifndef ND_ACCOUNT_H
#define ND_ACCOUNT_H

#include "account/account.h"

class NdAccountPrivate;

class NdAccount : public Account
{
    Q_OBJECT
    Q_DISABLE_COPY(NdAccount)
    Q_DECLARE_PRIVATE(NdAccount)
public:
    explicit NdAccount(QObject *parent = 0);
    ~NdAccount();

public Q_SLOTS:
    void setActive(const bool active) override;

};

#endif // ND_ACCOUNT_H
