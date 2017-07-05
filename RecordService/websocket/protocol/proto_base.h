#ifndef PROTO_BASE_H
#define PROTO_BASE_H

#include <QHash>
#include <QJsonValue>
#include <QMutex>
#include <QObject>
#include <QVector>
#include <functional>

class MessagePacket;
class ProtoBasePrivate;

class ProtoBase : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoBase)
  Q_DECLARE_PRIVATE(ProtoBase)
  Q_PROPERTY(QString mode READ mode CONSTANT)
 public:
  explicit ProtoBase(QObject *parent = nullptr);

  static const QString INFO_MODE;
  static const QString CONFERENCE_MODE;
  static const QString PERSONAL_MODE;
  static const QString MOBILE_MODE;
  static const QString BINARY_MODE;

  QString mode() const;

  typedef std::function<void(const QJsonValue &data)> callbackFunc;

 protected:
  /*
   * it is called in process thread
   * put heavy work in process function
   */
  virtual void process(QSharedPointer<MessagePacket> pkt);
  virtual void transport(QSharedPointer<MessagePacket> pkt);

  ProtoBase(ProtoBasePrivate *d, QObject *parent = nullptr);
  QScopedPointer<ProtoBasePrivate> d_ptr;
  friend class ProcessThread;
  friend class ServiceBase;
};

#endif  // PROTO_BASE_H
