#ifndef PROTO_BASE_H
#define PROTO_BASE_H

#include <QJsonValue>
#include <QObject>
#include <QSharedPointer>

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

 protected:
  // process pkt data
  virtual void process(QSharedPointer<MessagePacket> pkt);

  ProtoBase(ProtoBasePrivate *d, QObject *parent = nullptr);
  QScopedPointer<ProtoBasePrivate> d_ptr;
  friend class ProcessThread;
  friend class ServiceBase;
};

#endif  // PROTO_BASE_H
