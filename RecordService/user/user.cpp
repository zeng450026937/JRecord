#include "user.h"
#include "user_p.h"

User::User(QObject *parent) : QObject(parent), d_ptr(new UserPrivate(this)) {}

QString User::userId() const { return d_func()->userId; }

QString User::userGroup() const { return d_func()->userGroup; }

QString User::userName() const { return d_func()->userName; }

void User::setUserId(QString userId) {
  Q_D(User);
  if (userId.isEmpty()) return;
  if (userId != d->userId) {
    d->userId = userId;
    Q_EMIT userIdChanged(d->userId);
  }
}

void User::setUserGroup(QString userGroup) {
  Q_D(User);
  if (userGroup.isEmpty()) return;
  if (userGroup != d->userGroup) {
    d->userGroup = userGroup;
    Q_EMIT userGroupChanged(d->userGroup);
  }
}

void User::setUserName(QString userName) {
  Q_D(User);
  if (userName.isEmpty()) return;
  if (userName != d->userName) {
    d->userName = userName;
    Q_EMIT userNameChanged(d->userName);
  }
}

User::User(UserPrivate *d, QObject *parent) : QObject(parent), d_ptr(d) {}
