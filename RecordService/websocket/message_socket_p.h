#ifndef MESSAGE_SOCKET_P_H
#define MESSAGE_SOCKET_P_H

#include <QNetworkRequest>
#include <QObject>

class MessageSocket;
class QWebSocket;

class MessageSocketPrivate {
  Q_DISABLE_COPY(MessageSocketPrivate)
  Q_DECLARE_PUBLIC(MessageSocket)
 public:
  MessageSocketPrivate(MessageSocket *q);

  MessageSocket *q_ptr;

  QWebSocket *socket;
  bool active;
  QNetworkRequest request;
  QString error;
};

#endif  // MESSAGE_SOCKET_P_H
