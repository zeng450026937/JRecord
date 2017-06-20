#ifndef PROTO_MOBILE_H
#define PROTO_MOBILE_H

#include <QJsonValue>
#include "proto_base.h"

class ProtoMobilePrivate;

class ProtoMobile : public ProtoBase {
  Q_OBJECT
  Q_DISABLE_COPY(ProtoMobile)
  Q_DECLARE_PRIVATE(ProtoMobile)
 public:
  explicit ProtoMobile(QObject *parent = nullptr);

  enum Actions { getMobileList, unknown };
  Q_ENUM(Actions)

 Q_SIGNALS:
  void actionRecived(const int action, const QJsonValue &data);

 public Q_SLOTS:
  void query(const QString &userId);

 protected:
  void process(QSharedPointer<MessagePacket> pkt) override;
};

#endif  // PROTO_MOBILE_H
