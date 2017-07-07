#ifndef SERVICE_BASE_H
#define SERVICE_BASE_H

#include <QNetworkRequest>
#include <QObject>

class Device;
class DeviceManager;
class ConferenceManager;
class TaskManager;
class ProtoBase;
class ServiceBasePrivate;

class ServiceBase : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(ServiceBase)
  Q_DECLARE_PRIVATE(ServiceBase)
  Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
  Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)
  Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
  Q_PROPERTY(Device *device READ device WRITE setDevice NOTIFY deviceChanged)

 public:
  ServiceBase(QObject *parent = 0);
  ~ServiceBase();

  enum Status { Connecting, Open, Closing, Closed, Error };
  Q_ENUM(Status)

  Status status() const;
  bool active() const;
  QString errorString() const;
  QUrl url() const;

  Device *device() const;

  TaskManager *taskManager() const;

  // protocol which register by registerProtocol(), will be deleted when
  // removeProtocol() is called.
  // register protocol with same mode,the old one will be deleted.
  // user has responsibility for protocol's life span.
  void registerProtocol(ProtoBase *protocol);
  void removeProtocol(const QString &name);
  ProtoBase *protocol(const QString &name);

  Q_INVOKABLE DeviceManager *deviceManager() const;
  Q_INVOKABLE ConferenceManager *conferenceManager() const;

 public Q_SLOTS:
  void setActive(bool active);
  void setUrl(const QUrl &url);
  void setDevice(Device *device);

 Q_SIGNALS:
  void statusChanged(Status status);
  void activeChanged(bool active);
  void errorStringChanged(const QString &errorString);
  void urlChanged(const QUrl &url);
  void deviceChanged(const Device *device);
  void protocolChanged(const QString &protocolName);

 protected:
  ServiceBase(ServiceBasePrivate *d, QObject *parent = 0);
  QScopedPointer<ServiceBasePrivate> d_ptr;
};

#endif  // SERVICE_BASE_H
