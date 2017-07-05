#include "binarymessage.h"
#include <QDataStream>
#include <QDebug>
#include "binarymessage_p.h"

BinaryMessage::BinaryMessage(QObject *parent)
    : MessagePacket(new BinaryMessagePrivate(this), parent) {}

BinaryMessage::BinaryMessage(const QByteArray &message, QObject *parent)
    : MessagePacket(new BinaryMessagePrivate(this), parent) {
  this->parse(message);
}

qint32 BinaryMessage::mode() const { return d_func()->mode; }

QString BinaryMessage::userId() const { return d_func()->userId; }

QString BinaryMessage::deviceUuid() const { return d_func()->deviceUuid; }

QString BinaryMessage::uuid() const { return d_func()->uuid; }

qint32 BinaryMessage::timestamp() const { return d_func()->timestamp; }

qint32 BinaryMessage::startpos() const { return d_func()->startpos; }

qint32 BinaryMessage::status() const { return d_func()->status; }

QByteArray BinaryMessage::data() const { return d_func()->data; }

void BinaryMessage::parse(QByteArray message) {
  Q_D(BinaryMessage);

  QDataStream stream(&message, QIODevice::ReadOnly);

  stream >> d->mode;
  stream >> d->userId;
  stream >> d->deviceUuid;
  stream >> d->uuid;
  stream >> d->timestamp;
  stream >> d->startpos;
  stream >> d->status;
  stream >> d->size;
  stream >> d->data;

  Q_EMIT modeChanged(d->mode);
  Q_EMIT userIdChanged(d->userId);
  Q_EMIT deviceUuidChanged(d->deviceUuid);
  Q_EMIT uuidChanged(d->uuid);
  Q_EMIT timestampChanged(d->timestamp);
  Q_EMIT startposChanged(d->startpos);
  Q_EMIT statusChanged(d->status);
  Q_EMIT dataChanged(d->data);

  //  bool ok(false);

  //  d->mode = buffer.read(d->mode_size).toHex().toUInt(&ok, 16);
  //  qDebug() << "mode" << d->mode << ok;

  //  d->userId = QString::fromLatin1(buffer.read(d->userId_size));
  //  qDebug() << "userId" << d->userId;

  //  d->deviceUuid = QString::fromLatin1(buffer.read(d->deviceUuid_size));
  //  qDebug() << "deviceUuid" << d->deviceUuid;

  //  d->uuid = QString::fromLatin1(buffer.read(d->uuid_size));
  //  qDebug() << "uuid" << d->uuid;

  //  d->timestamp = buffer.read(d->timestamp_size).toHex().toUInt(&ok, 16);
  //  qDebug() << "timestamp" << d->timestamp << ok;

  //  d->startpos = buffer.read(d->startpos_size).toHex().toULong(&ok, 16);
  //  qDebug() << "startpos" << d->startpos << ok;

  //  d->status = buffer.read(d->status_size).toHex().toULong(&ok, 16);
  //  qDebug() << "status" << d->status << ok;

  //  d->size = buffer.read(d->size_size).toHex().toULong(&ok, 16);
  //  qDebug() << "size" << d->size << ok;

  //  if (d->size >= 0) {
  //    d->data = buffer.read(d->size);
  //  }
}

QByteArray BinaryMessage::make() {
  qDebug() << QStringLiteral(
      "currently,we don't send any binary message to server side");

  Q_D(BinaryMessage);

  QByteArray binary;
  QDataStream stream(&binary, QIODevice::WriteOnly);

  stream << d->mode;
  stream << d->userId;
  stream << d->deviceUuid;
  stream << d->uuid;
  stream << d->timestamp;
  stream << d->startpos;
  stream << d->status;
  stream << d->size;
  stream << d->data;

  return binary;
}

bool BinaryMessage::match(MessagePacket *pkt) { return false; }

bool BinaryMessage::notify() { return false; }

void BinaryMessage::setMode(qint32 mode) {
  Q_D(BinaryMessage);
  if (mode != d->mode) {
    d->mode = mode;
    Q_EMIT modeChanged(d->mode);
  }
}

void BinaryMessage::setUserId(const QString &userId) {
  Q_D(BinaryMessage);
  if (userId != d->userId) {
    d->userId = userId;
    Q_EMIT userIdChanged(d->userId);
  }
}

void BinaryMessage::setDeviceUuid(const QString &deviceUuid) {
  Q_D(BinaryMessage);
  if (deviceUuid != d->deviceUuid) {
    d->deviceUuid = deviceUuid;
    Q_EMIT deviceUuidChanged(d->deviceUuid);
  }
}

void BinaryMessage::setUuid(const QString &uuid) {
  Q_D(BinaryMessage);
  if (uuid != d->uuid) {
    d->uuid = uuid;
    Q_EMIT uuidChanged(d->uuid);
  }
}

void BinaryMessage::setTimestamp(qint32 timestamp) {
  Q_D(BinaryMessage);
  if (timestamp != d->timestamp) {
    d->timestamp = timestamp;
    Q_EMIT timestampChanged(d->timestamp);
  }
}

void BinaryMessage::setStartpos(qint32 startpos) {
  Q_D(BinaryMessage);
  if (startpos != d->startpos) {
    d->startpos = startpos;
    Q_EMIT startposChanged(d->startpos);
  }
}

void BinaryMessage::setStatus(qint32 status) {
  Q_D(BinaryMessage);
  if (status != d->status) {
    d->status = status;
    Q_EMIT statusChanged(d->status);
  }
}

void BinaryMessage::setData(const QByteArray &data) {
  Q_D(BinaryMessage);
  if (data != d->data) {
    d->data = data;
    Q_EMIT dataChanged(d->data);
  }
}

BinaryMessage::BinaryMessage(BinaryMessagePrivate *d, QObject *parent)
    : MessagePacket(d, parent) {}
