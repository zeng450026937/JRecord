#ifndef BINARYMESSAGE_H
#define BINARYMESSAGE_H

#include "message_packet.h"

class BinaryMessagePrivate;

class BinaryMessage : public MessagePacket {
  Q_OBJECT
  Q_DISABLE_COPY(BinaryMessage)
  Q_DECLARE_PRIVATE(BinaryMessage)

  Q_PROPERTY(qint32 mode READ mode WRITE setMode NOTIFY modeChanged)
  Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)
  Q_PROPERTY(QString deviceUuid READ deviceUuid WRITE setDeviceUuid NOTIFY
                 deviceUuidChanged)
  Q_PROPERTY(QString uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
  Q_PROPERTY(qint32 timestamp READ timestamp WRITE setTimestamp NOTIFY
                 timestampChanged)
  Q_PROPERTY(
      qint32 startpos READ startpos WRITE setStartpos NOTIFY startposChanged)
  Q_PROPERTY(qint32 status READ status WRITE setStatus NOTIFY statusChanged)
  Q_PROPERTY(QByteArray data READ data WRITE setData NOTIFY dataChanged)

 public:
  explicit BinaryMessage(QObject* parent = 0);
  BinaryMessage(const QByteArray& message, QObject* parent = 0);

  qint32 mode() const;
  QString userId() const;
  QString deviceUuid() const;
  QString uuid() const;
  qint32 timestamp() const;
  qint32 startpos() const;
  qint32 status() const;
  QByteArray data() const;

  Q_INVOKABLE void parse(QByteArray message);
  Q_INVOKABLE QByteArray make();

  bool match(MessagePacket* pkt) override;
  bool notify() override;

 Q_SIGNALS:
  void modeChanged(qint32 mode);
  void userIdChanged(const QString& userId);
  void deviceUuidChanged(const QString& deviceUuid);
  void uuidChanged(const QString& uuid);
  void timestampChanged(qint32 timestamp);
  void startposChanged(qint32 startpos);
  void statusChanged(qint32 status);
  void dataChanged(const QByteArray& data);

 public Q_SLOTS:
  void setMode(qint32 mode);
  void setUserId(const QString& userId);
  void setDeviceUuid(const QString& deviceUuid);
  void setUuid(const QString& uuid);
  void setTimestamp(qint32 timestamp);
  void setStartpos(qint32 startpos);
  void setStatus(qint32 status);
  void setData(const QByteArray& data);

 protected:
  BinaryMessage(BinaryMessagePrivate* d, QObject* parent = 0);
  QScopedPointer<BinaryMessagePrivate> d_ptr;
};

#endif  // BINARYMESSAGE_H
