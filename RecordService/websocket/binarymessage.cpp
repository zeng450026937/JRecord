#include "binarymessage.h"
#include "binarymessage_p.h"
#include <QBuffer>
#include <QDebug>

BinaryMessage::BinaryMessage(QObject *parent) :
    QObject(parent),
    d_ptr(new BinaryMessagePrivate(this))
{

}

BinaryMessage::BinaryMessage(QByteArray message, QObject *parent) :
    QObject(parent),
    d_ptr(new BinaryMessagePrivate(this))
{
    this->parse(message);
}

BinaryMessage::~BinaryMessage()
{

}

int BinaryMessage::mode() const
{
    return d_func()->mode;
}

QString BinaryMessage::userId() const
{
    return d_func()->userId;
}

QString BinaryMessage::deviceUuid() const
{
    return d_func()->deviceUuid;
}

QString BinaryMessage::uuid() const
{
    return d_func()->uuid;
}

int BinaryMessage::timestamp() const
{
    return d_func()->timestamp;
}

int BinaryMessage::startpos() const
{
    return d_func()->startpos;
}

int BinaryMessage::status() const
{
    return d_func()->status;
}

int BinaryMessage::size() const
{
    return d_func()->size;
}

void BinaryMessage::parse(QByteArray message)
{
    Q_D(BinaryMessage);

    QBuffer buffer(&message);
    buffer.open(QIODevice::ReadOnly);

    buffer.seek(0);

    bool ok(false);

    d->mode = buffer.read(d->mode_size).toHex().toUInt(&ok,16);
    qDebug()<<"mode"<<d->mode<<ok;

    d->userId = QString::fromLatin1(buffer.read(d->userId_size));
    qDebug()<<"userId"<<d->userId;

    d->deviceUuid = QString::fromLatin1(buffer.read(d->deviceUuid_size));
    qDebug()<<"deviceUuid"<<d->deviceUuid;

    d->uuid = QString::fromLatin1(buffer.read(d->uuid_size));
    qDebug()<<"uuid"<<d->uuid;

    d->timestamp = buffer.read(d->timestamp_size).toHex().toUInt(&ok,16);
    qDebug()<<"timestamp"<<d->timestamp<<ok;

    d->startpos = buffer.read(d->startpos_size).toHex().toULong(&ok,16);
    qDebug()<<"startpos"<<d->startpos<<ok;

    d->status = buffer.read(d->status_size).toHex().toULong(&ok,16);
    qDebug()<<"status"<<d->status<<ok;

    d->size = buffer.read(d->size_size).toHex().toULong(&ok,16);
    qDebug()<<"size"<<d->size<<ok;

    if(d->size >= 0){
        d->data = buffer.read(d->size);
    }
}

QByteArray BinaryMessage::make()
{
    qDebug() << QStringLiteral("currently,we don't send any binary message to server side");
    return QByteArray();
}

void BinaryMessage::setMode(int mode)
{
    Q_D(BinaryMessage);
    if(mode != d->mode){
        d->mode = mode;
        Q_EMIT modeChanged(d->mode);
    }
}

void BinaryMessage::setUserId(const QString &userId)
{
    Q_D(BinaryMessage);
    if(userId != d->userId){
        d->userId = userId;
        Q_EMIT userIdChanged(d->userId);
    }
}

void BinaryMessage::setDeviceUuid(const QString &deviceUuid)
{
    Q_D(BinaryMessage);
    if(deviceUuid != d->deviceUuid){
        d->deviceUuid = deviceUuid;
        Q_EMIT deviceUuidChanged(d->deviceUuid);
    }
}

void BinaryMessage::setUuid(const QString &uuid)
{
    Q_D(BinaryMessage);
    if(uuid != d->uuid){
        d->uuid = uuid;
        Q_EMIT uuidChanged(d->uuid);
    }
}

void BinaryMessage::setTimestamp(int timestamp)
{
    Q_D(BinaryMessage);
    if(timestamp != d->timestamp){
        d->timestamp = timestamp;
        Q_EMIT timestampChanged(d->timestamp);
    }
}

void BinaryMessage::setStartpos(int startpos)
{
    Q_D(BinaryMessage);
    if(startpos != d->startpos){
        d->startpos = startpos;
        Q_EMIT startposChanged(d->startpos);
    }
}

void BinaryMessage::setStatus(int status)
{
    Q_D(BinaryMessage);
    if(status != d->status){
        d->status = status;
        Q_EMIT sizeChanged(d->status);
    }
}

void BinaryMessage::setSize(int size)
{
    Q_D(BinaryMessage);
    if(size != d->size){
        d->size = size;
        Q_EMIT sizeChanged(d->size);
    }
}
