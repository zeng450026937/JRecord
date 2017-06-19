#include "account.h"
#include "account_p.h"

Account::Account(QObject *parent)
    : QObject(parent), d_ptr(new AccountPrivate(this)) {}

Account::~Account() {}

QString Account::userId() const { return d_func()->userId; }

QString Account::userName() const { return d_func()->userName; }

QString Account::userGroup() const { return d_func()->userGroup; }

QString Account::password() const { return d_func()->password; }

QString Account::image() const { return d_func()->image; }

QString Account::signature() const { return d_func()->signature; }

QString Account::errorString() const { return d_func()->errorString; }

Account::Status Account::status() const { return d_func()->status; }

bool Account::active() const { return d_func()->active; }

void Account::setUserId(const QString &userId) {
  Q_D(Account);
  if (userId != d->userId) {
    d->userId = userId;
    Q_EMIT userIdChanged(d->userId);
  }
}

void Account::setUserGroup(const QString &userGroup) {
  Q_D(Account);
  if (userGroup != d->userGroup) {
    d->userGroup = userGroup;
    Q_EMIT userIdChanged(d->userGroup);
  }
}

void Account::setPassword(const QString &password) {
  Q_D(Account);
  if (password != d->password) {
    d->password = password;
    Q_EMIT passwordChanged(d->password);
  }
}

void Account::setActive(const bool active) {
  Q_D(Account);
  if (active != d->active) {
    if (active) {
      Q_EMIT statusChanged(Logining);
    } else {
      Q_EMIT statusChanged(Logouting);
    }
  }
}

Account::Account(AccountPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
