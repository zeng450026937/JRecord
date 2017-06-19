#ifndef MESSAGE_SOCKET_H
#define MESSAGE_SOCKET_H

#include <QNetworkRequest>
#include <QObject>

class MessageSocketPrivate;

class MessageSocket : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MessageSocket)
  Q_DECLARE_PRIVATE(MessageSocket)
  Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
  Q_PROPERTY(QNetworkRequest request READ request WRITE setRequest NOTIFY
                 requestChanged)
  Q_PROPERTY(QString error READ error NOTIFY errorChanged)
 public:
  explicit MessageSocket(QObject *parent = nullptr);
  ~MessageSocket();

  bool active() const;
  QNetworkRequest request() const;
  QString error() const;

 Q_SIGNALS:
  void activeChanged(const bool active);
  void requestChanged(const QNetworkRequest &request);
  void errorChanged(const QString error);

  void connected();
  void disconnected();

  void textReceived(const QString &message);
  void binaryReceived(const QByteArray &message);

 public Q_SLOTS:
  void setActive(const bool active);
  void setRequest(const QNetworkRequest &request);

  void sendText(const QString &message);
  void sendBinary(const QByteArray &message);

 protected:
  MessageSocket(MessageSocketPrivate *d, QObject *parent = nullptr);
  QScopedPointer<MessageSocketPrivate> d_ptr;
};

#endif  // MESSAGE_SOCKET_H
