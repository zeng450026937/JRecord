#ifndef PROTO_BASE_H
#define PROTO_BASE_H

#include <QObject>
#include <QSharedPointer>
#include <QVariantMap>

class MessagePacket;
class ProtoBasePrivate;

class ProtoBase : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoBase)
  Q_DECLARE_PRIVATE(ProtoBase)
  Q_PROPERTY(QString mode READ mode CONSTANT)
 public:
  explicit ProtoBase(QObject *parent = nullptr);

  enum MODE { InfoMode, ConfMode, BinaryMode };
  Q_ENUMS(MODE)

  QString mode() const;

 protected:
  /*
   * it is called in process thread
   * put heavy work in process function
   */
  virtual void process(QSharedPointer<MessagePacket> pkt);

  virtual void transport(QString from, QString to, QString action,
                         const QVariantMap &data);

  ProtoBase(ProtoBasePrivate *d, QObject *parent = nullptr);
  QScopedPointer<ProtoBasePrivate> d_ptr;
  friend class ProcessThread;
  friend class ServiceBase;
};

#endif  // PROTO_BASE_H
