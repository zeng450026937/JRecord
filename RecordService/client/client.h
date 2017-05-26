#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class ServiceBase;
class ClientPrivate;

class Client : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Client)
    Q_DECLARE_PRIVATE(Client)

    Q_PROPERTY(ServiceBase* service READ service WRITE setService NOTIFY serviceChanged)

public:
    explicit Client(QObject *parent = 0);

    ServiceBase *service() const;

public Q_SLOTS:
    void setService(ServiceBase *servie);

Q_SIGNALS:
    void serviceChanged();

protected:
    Client(ClientPrivate *d, QObject *parent = 0);
    QScopedPointer<ClientPrivate> d_ptr;
};

#endif // CLIENT_H
