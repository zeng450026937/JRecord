#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>

class AccountPrivate;

class Account : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Account)
    Q_DECLARE_PRIVATE(Account)

    Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)
    Q_PROPERTY(QString userName READ userName NOTIFY userNameChanged)
    Q_PROPERTY(QString userGroup READ userGroup WRITE setUserGroup NOTIFY userGroupChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString image READ image NOTIFY imageChanged)
    Q_PROPERTY(QString signature READ signature NOTIFY signatureChanged)

    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)
    Q_PROPERTY(Status status READ status NOTIFY statusChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
    explicit Account(QObject *parent = Q_NULLPTR);
    ~Account();

    enum Status{
        Logining,
        Login,
        Logouting,
        Logout,
        Error
    };
    Q_ENUM(Status)

    QString userId() const;
    QString userName() const;
    QString userGroup() const;
    QString password() const;
    QString image() const;
    QString signature() const;

    QString errorString() const;
    Status status() const;
    bool active() const;

public Q_SLOTS:
    void setUserId(const QString &userId);
    void setUserGroup(const QString &userGroup);
    void setPassword(const QString &password);
    virtual void setActive(const bool active);

Q_SIGNALS:
    void userIdChanged(const QString &userId);
    void userNameChanged(const QString &username);
    void userGroupChanged(const QString &userGroup);
    void passwordChanged(const QString &password);
    void imageChanged(const QString &image);
    void signatureChanged(const QString &signature);

    void errorStringChanged(const QString &errorString);
    void statusChanged(const Status status);
    void activeChanged(const bool active);

protected:
    Account(AccountPrivate *d, QObject *parent = Q_NULLPTR);
    QScopedPointer<AccountPrivate> d_ptr;
};

#endif // ACCOUNT_H
