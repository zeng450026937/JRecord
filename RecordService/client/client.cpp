#include "client.h"
#include "client_p.h"

Client::Client(QObject *parent)
    : QObject(parent), d_ptr(new ClientPrivate(this)) {}

ServiceBase *Client::service() const { return d_func()->service; }

void Client::setService(ServiceBase *servie) {
  Q_D(Client);
  if (servie != d->service) {
    d->service = servie;
    Q_EMIT serviceChanged(d->service);
  }
}

Client::Client(ClientPrivate *d, QObject *parent) : QObject(parent), d_ptr(d) {}
