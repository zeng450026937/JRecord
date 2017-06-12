#ifndef DEVICE_H
#define DEVICE_H

#include "client/client.h"

class User;
class DevicePrivate;

class Device : public Client
{
    Q_OBJECT
    Q_DISABLE_COPY(Device)
    Q_DECLARE_PRIVATE(Device)

    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(QString vad READ vad WRITE setVad NOTIFY vadChanged)
    Q_PROPERTY(int percent READ percent WRITE setPercent NOTIFY percentChanged)
    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(bool lock READ lock WRITE setLock NOTIFY lockChanged)
    Q_PROPERTY(User* owner READ owner WRITE setOwner NOTIFY ownerChanged)
public:
    explicit Device(QObject *parent = 0);

    QString type() const;
    QString uuid() const;
    QString name() const;
    QString status() const;
    QString vad() const;
    int percent() const;
    int time() const;
    bool lock() const;
    User *owner() const;

Q_SIGNALS:
    void typeChanged(const QString &type);
    void uuidChanged(const QString &uuid);
    void nameChanged(const QString &name);
    void statusChanged(const QString &status);
    void vadChanged(const QString &vad);
    void percentChanged(const int percent);
    void timeChanged(const int time);
    void lockChanged(const bool lock);
    void ownerChanged(const User* user);

public Q_SLOTS:
    void setType(const QString &type);
    void setUuid(const QString &uuid);
    void setName(const QString &name);
    void setStatus(const QString &status);
    void setVad(const QString &vad);
    void setPercent(const int percent);
    void setTime(const int time);
    void setLock(const bool lock);
    void setOwner(User *owner);

protected:
    Device(DevicePrivate *d, QObject *parent = 0);
};

#endif // DEVICE_H
