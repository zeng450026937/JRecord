#ifndef CLIENT_P_H
#define CLIENT_P_H

#include <QObject>

class Client;
class ServiceBase;

class ClientPrivate
{
    Q_DISABLE_COPY(ClientPrivate)
    Q_DECLARE_PUBLIC(Client)
public:
    ClientPrivate(Client* q);

    Client* q_ptr;
    ServiceBase *service;
};

#endif // CLIENT_P_H
