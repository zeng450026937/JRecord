#ifndef TASK_REPLY_H
#define TASK_REPLY_H

#include <QJsonValue>
#include <QObject>

class TaskReplyPrivate;

class TaskReply : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(TaskReply)
  Q_DECLARE_PRIVATE(TaskReply)
  Q_PROPERTY(QJsonValue data READ data WRITE setData NOTIFY dataChanged)
  Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
 public:
  explicit TaskReply(QObject *parent = nullptr);

  enum Status { Idle, Executing, Completed, Timeout, Error };
  Q_ENUM(Status)

  QJsonValue data() const;
  TaskReply::Status status() const;

 Q_SIGNALS:
  void dataChanged(const QJsonValue &data);
  void statusChanged(TaskReply::Status status);

  // use deleteLater() when reply is finished() or timeout().
  void finished();
  void timeout();

 public Q_SLOTS:
  void setData(const QJsonValue &data);
  void setStatus(TaskReply::Status status);

 protected:
  TaskReply(TaskReplyPrivate *d, QObject *parent = nullptr);
  QScopedPointer<TaskReplyPrivate> d_ptr;

  void timerEvent(QTimerEvent *event) override;
};
#endif  // TASK_REPLY_H
