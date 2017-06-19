#ifndef BINARYMESSAGE_P_H
#define BINARYMESSAGE_P_H

#include <QObject>

class BinaryMessage;

class BinaryMessagePrivate {
  Q_DISABLE_COPY(BinaryMessagePrivate)
  Q_DECLARE_PUBLIC(BinaryMessage)
 public:
  BinaryMessagePrivate(BinaryMessage* q);

  BinaryMessage* q_ptr;

  qint32 mode;
  QString userId;
  QString deviceUuid;
  QString uuid;
  qint32 timestamp;
  qint32 startpos;
  qint32 status;
  qint32 size;
  QByteArray data;

 protected:
  const qint32 mode_size;
  const qint32 userId_size;
  const qint32 deviceUuid_size;
  const qint32 uuid_size;
  const qint32 timestamp_size;
  const qint32 startpos_size;
  const qint32 status_size;
  const qint32 size_size;
  qint32 total_size;
};

#endif  // BINARYMESSAGE_P_H
