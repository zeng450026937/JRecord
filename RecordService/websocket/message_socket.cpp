#include "message_socket.h"
#include "message_socket_p.h"
#include <QWebSocket>

MessageSocket::MessageSocket(QObject *parent)
    : QObject(parent), d_ptr(new MessageSocketPrivate(this)) {
  qRegisterMetaType<QByteArray>();
  qRegisterMetaType<QNetworkRequest>();
  qRegisterMetaType<QAbstractSocket::SocketState>();
}

MessageSocket::~MessageSocket() { this->setActive(false); }

bool MessageSocket::active() const { return d_func()->active; }

QNetworkRequest MessageSocket::request() const { return d_func()->request; }

QString MessageSocket::error() const { return d_func()->error; }

void MessageSocket::setActive(const bool active) {
  Q_D(MessageSocket);
  if (active != d->active) {
    if (active) {
      d->socket = new QWebSocket();
      QObject::connect(d->socket, &QWebSocket::connected, [this, d]() {
        d->active = true;
        Q_EMIT activeChanged(d->active);
      });
      QObject::connect(d->socket, &QWebSocket::disconnected, [this, d]() {
        if (d->socket && d->error != d->socket->errorString()) {
          d->error = d->socket->errorString();
          Q_EMIT errorChanged(d->error);
        }
        d->socket->deleteLater();
        d->socket = Q_NULLPTR;
        d->active = false;
        Q_EMIT activeChanged(d->active);
      });
      QObject::connect(
          d->socket,
          static_cast<void (QWebSocket::*)(QAbstractSocket::SocketError)>(
              &QWebSocket::error),
          [this, d](QAbstractSocket::SocketError error) {
            Q_UNUSED(error);
            if (d->socket && d->error != d->socket->errorString()) {
              d->error = d->socket->errorString();
              Q_EMIT errorChanged(d->error);
            }
          });
      QObject::connect(
          d->socket, &QWebSocket::textMessageReceived,
          [this](const QString &message) { Q_EMIT textReceived(message); });
      QObject::connect(d->socket, &QWebSocket::binaryMessageReceived,
                       [this](const QByteArray &message) {
                         Q_EMIT binaryReceived(message);
                       });
      d->socket->open(d->request);
    } else {
      if (d->socket && d->socket->isValid())
        d->socket->close();
    }
  }
}

void MessageSocket::setRequest(const QNetworkRequest &request) {
  Q_D(MessageSocket);
  if (request != d->request) {
    d->request = request;
    Q_EMIT requestChanged(d->request);
  }
}

void MessageSocket::sendText(const QString &message) {
  Q_D(MessageSocket);
  if (d->socket)
    d->socket->sendTextMessage(message);
}

void MessageSocket::sendBinary(const QByteArray &message) {
  Q_D(MessageSocket);
  if (d->socket)
    d->socket->sendBinaryMessage(message);
}

MessageSocket::MessageSocket(MessageSocketPrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}
