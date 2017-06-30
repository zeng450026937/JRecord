#ifndef TASK_BASE_H
#define TASK_BASE_H

#include <QJsonValue>
#include <functional>
#include "websocket/protocol/proto_base.h"

class TaskBasePrivate;

class TaskBase : public ProtoBase {
  Q_OBJECT
  Q_DISABLE_COPY(TaskBase)
  Q_DECLARE_PRIVATE(TaskBase)
  Q_PROPERTY(int action READ action WRITE setAction NOTIFY actionChanged)
  Q_PROPERTY(bool repeat READ repeat WRITE setRepeat NOTIFY repeatChanged)
  Q_PROPERTY(QJsonValue param READ param WRITE setParam NOTIFY paramChanged)
  Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)

 public:
  explicit TaskBase(QObject *parent = nullptr);

  typedef std::function<void(int, const QJsonValue &)> Notification;

  enum Status { Idle, Executing, Compeleted, Timeout, Error };
  Q_ENUM(Status)

  Q_INVOKABLE void start();
  Q_INVOKABLE void stop();

  int action() const;
  bool repeat() const;
  QJsonValue param() const;
  Status status() const;

 Q_SIGNALS:
  void actionChanged(int action);
  void repeatChanged(bool repeat);
  void paramChanged(const QJsonValue &param);
  void statusChanged(Status status);

  void triggered(const QJsonValue &result);

 public Q_SLOTS:
  void setAction(int action);
  void setRepeat(bool repeat);
  void setParam(const QJsonValue &param);
  void setStatus(Status status);

 protected:
  TaskBase(TaskBasePrivate *d, QObject *parent = nullptr);
};

#endif  // TASK_BASE_H
