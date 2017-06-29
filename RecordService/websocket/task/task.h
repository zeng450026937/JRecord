#ifndef TASK_H
#define TASK_H

#include <QJsonObject>
#include <QObject>
#include "websocket/message_packet.h"

class TaskPrivate;

class Task : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(Task)
  Q_DECLARE_PRIVATE(Task)
  Q_PROPERTY(MessagePacket *message READ message WRITE setMessage NOTIFY
                 messageChanged)
  Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)

 public:
  explicit Task(QObject *parent = nullptr);

  enum Status { Idle, Executing, Compeleted, Timeout, Error };
  Q_ENUM(Status)

  QString mode() const;
  int action() const;
  QJsonObject data() const;

 Q_SIGNALS:
  void modeChanged(const QString &mode);
  void actionChanged(const int action);
  void dataChanged(const QJsonObject &data);

 public Q_SLOTS:
  void setMode(const QString &mode);
  void setAction(const int action);
  void setData(const QJsonObject &data);

  Task(TaskPrivate *d, QObject *parent = nullptr);
  QScopedPointer<TaskPrivate> d_ptr;
};

#endif  // TASK_H
