#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H

#include "message_packet.h"
#include <QVariantMap>
#include <QJsonValue>

class TextMessagePrivate;

class TextMessage : public QObject, public MessagePacket
{
    Q_OBJECT
    Q_DISABLE_COPY(TextMessage)
    Q_DECLARE_PRIVATE(TextMessage)

    Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged)
    Q_PROPERTY(QString from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QString to READ to WRITE setTo NOTIFY toChanged)
    Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(QString action READ action WRITE setAction NOTIFY actionChanged)
    Q_PROPERTY(QVariantMap data READ data WRITE setData NOTIFY dataChanged)
    Q_PROPERTY(bool result READ result WRITE setResult NOTIFY resultChanged)
    Q_PROPERTY(QJsonValue json READ json CONSTANT)

public:
    explicit TextMessage(QObject *parent = 0);
    TextMessage(QString string, QObject *parent = 0);
    TextMessage(QString from,
                QString to,
                QString mode,
                QString action,
                QVariantMap data,
                QObject *parent = 0);
    ~TextMessage() override;

    MessageType type() { return Text; }

    QString version() const;
    QString from() const;
    QString to() const;
    QString mode() const;
    QString action() const;
    QVariantMap data() const;
    bool result() const;
    QJsonValue json() const;

    Q_INVOKABLE void decode(const QString &message);
    Q_INVOKABLE QString encode();

Q_SIGNALS:
    void versionChanged(const QString &version);
    void fromChanged(const QString &from);
    void toChanged(const QString &to);
    void modeChanged(const QString &mode);
    void actionChanged(const QString &action);
    void dataChanged();
    void resultChanged(const bool result);

public Q_SLOTS:
    void setVersion(const QString &version);
    void setFrom(const QString &from);
    void setTo(const QString &to);
    void setMode(const QString &mode);
    void setAction(const QString &action);
    void setData(const QVariantMap &data);
    void setResult(const bool &result);

protected:
    TextMessage(TextMessagePrivate *d, QObject *parent = 0);
    QScopedPointer<TextMessagePrivate> d_ptr;
};

#endif // TEXTMESSAGE_H
