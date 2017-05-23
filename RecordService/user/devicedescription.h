#ifndef DEVICEDESCRIPTION_H
#define DEVICEDESCRIPTION_H

#include <QObject>

class DeviceDescription : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY deviceChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY deviceChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY deviceChanged)
    Q_PROPERTY(QString vad READ vad WRITE setVad NOTIFY deviceChanged)
    Q_PROPERTY(int percent READ percent WRITE setPercent NOTIFY deviceChanged)
    Q_PROPERTY(int time READ time WRITE setTime NOTIFY deviceChanged)

public:
    explicit DeviceDescription(QObject *parent = 0);

    QString type() const;
    QString name() const;
    QString status() const;
    QString vad() const;
    int percent() const;
    int time() const;

Q_SIGNALS:
    void deviceChanged();

public Q_SLOTS:
    void setType(const QString &deviceType);
    void setName(const QString &deviceName);
    void setStatus(const QString &status);
    void setVad(const QString &vad);
    void setPercent(const int percent);
    void setTime(const int time);
};

#endif // DEVICEDESCRIPTION_H
