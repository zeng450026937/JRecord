#ifndef MESSAGE_REPLY_H
#define MESSAGE_REPLY_H

#include <QJsonValue>
#include <QObject>

class MessageReplyPrivate;

class MessageReply : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MessageReply)
  Q_DECLARE_PRIVATE(MessageReply)
  Q_PROPERTY(QJsonValue data READ data WRITE setData NOTIFY dataChanged)
  Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
 public:
  explicit MessageReply(QObject *parent = nullptr);

  enum Status { Idle, Executing, Completed, Timeout, Error };
  Q_ENUM(Status)

  QJsonValue data() const;
  MessageReply::Status status() const;

 Q_SIGNALS:
  void dataChanged(const QJsonValue &data);
  void statusChanged(MessageReply::Status status);

  // use deleteLater() when reply is finished() or timeout().
  void finished();
  void timeout();

 public Q_SLOTS:
  void setData(const QJsonValue &data);
  void setStatus(MessageReply::Status status);

 protected:
  MessageReply(MessageReplyPrivate *d, QObject *parent = nullptr);
  QScopedPointer<MessageReplyPrivate> d_ptr;

  void timerEvent(QTimerEvent *event) override;
};

#endif  // MESSAGE_REPLY_H
