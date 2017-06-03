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
    Q_PROPERTY(QString display READ display WRITE setDisplay NOTIFY displayChanged)
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
    QString display() const;
    QString errorString() const;

public Q_SLOTS:
    void setUsername(const QString &username);
    void setPassword(const QString &password);
    void setDisplay(const QString &display);

Q_SIGNALS:
    void usernameChanged(const QString &username);
    void passwordChanged(const QString &password);
    void displayChanged(const QString &display);
    void errorStringChanged(const QString &errorString);
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
    QString display_;
    QString errorString_;
    Status  status_;

    NdAccount* client_;
};

#endif // ACCOUNT_H
