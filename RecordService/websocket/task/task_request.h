#ifndef TASK_REQUEST_H
#define TASK_REQUEST_H

#include <QJsonValue>
#include <QObject>

class TaskRequestPrivate;

class TaskRequest : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(TaskRequest)
  Q_DECLARE_PRIVATE(TaskRequest)
  Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)
  Q_PROPERTY(QJsonValue data READ data WRITE setData NOTIFY dataChanged)
 public:
  explicit TaskRequest(QObject *parent = nullptr);

  enum Type { Info, Conference, Person, Mobile, Unknown };
  Q_ENUM(Type)

  enum InfoAction { getDeviceInfo };
  enum ConferenceAction { getConferenceInfo, getConferenceList };
  enum PersonAction { getConferenceInfo, getConferenceList };
  enum MobileAction { getConferenceInfo, getConferenceList };

  Type type() const;
  QJsonValue data() const;

 Q_SIGNALS:
  void typeChanged(const Type &type);
  void dataChanged(const QJsonValue &data);

 public Q_SLOTS:
  void setType(const Type &type);
  void setData(const QJsonValue &data);

 protected:
  TaskRequest(TaskRequestPrivate *d, QObject *parent = nullptr);
  QScopedPointer<TaskRequestPrivate> d_ptr;
};

#endif  // TASK_REQUEST_H
