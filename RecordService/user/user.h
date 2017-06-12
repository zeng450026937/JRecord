#ifndef USER_H
#define USER_H

#include <QObject>

class UserPrivate;

class User : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(User)
    Q_DECLARE_PRIVATE(User)

    Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)
    Q_PROPERTY(QString userGroup READ userGroup WRITE setUserGroup NOTIFY userGroupChanged)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit User(QObject *parent = 0);

    QString userId() const;
    QString userGroup() const;
    QString userName() const;

public Q_SLOTS:
    void setUserId(QString userId);
    void setUserGroup(QString userGroup);
    void setUserName(QString userName);

Q_SIGNALS:
    void userIdChanged(const QString &userId);
    void userGroupChanged(const QString &userGroup);
    void userNameChanged(const QString &userName);

protected:
    User(UserPrivate *d, QObject *parent = 0);
    QScopedPointer<UserPrivate> d_ptr;
};

#endif // USER_H
