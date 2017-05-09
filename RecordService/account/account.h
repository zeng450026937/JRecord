#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>

class NdAccount;

class Account : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Account)

    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString errorString READ errorString WRITE setErrorString NOTIFY errorStringChanged)

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

    Q_INVOKABLE void signIn();
    Q_INVOKABLE void signOut();

    QString username() const;
    QString password() const;
    QString errorString() const;

public Q_SLOTS:
    void setUsername(QString username);
    void setPassword(QString password);

Q_SIGNALS:
    void usernameChanged(QString username);
    void passwordChanged(QString password);
    void errorStringChanged(QString errorString);
    void statusChanged(Status status);

private Q_SLOTS:
    void onSignIned(QString account, bool ok, QString reason);
    void onSignOuted(QString account, bool ok, QString reason);

private:
    void setStatus(Status status);
    void setErrorString(QString errorString);

private:
    QString username_;
    QString password_;
    QString errorString_;
    Status  status_;

    NdAccount* client_;
};

#endif // ACCOUNT_H
