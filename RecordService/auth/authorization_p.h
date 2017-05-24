#ifndef AUTHORIZATION_P_H
#define AUTHORIZATION_P_H

#include <QObject>
#include <QNetworkRequest>

class MessageSocket;
class Authorization;

class AuthorizationPrivate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(AuthorizationPrivate)
    Q_DECLARE_PUBLIC(Authorization)
public:
    AuthorizationPrivate(Authorization* q);

    Authorization* q_ptr;

    QString userId;
    QString userGroup;
    QString userName;
    QString deviceType;

    bool authorized;

    MessageSocket* socket;

Q_SIGNALS:
    void authorizing(const QNetworkRequest &auth);
    void authorizing(const QUrl &url);

private Q_SLOTS:
    void onConnected();
    void onDisConnected();
};

#endif // AUTHORIZATION_P_H
