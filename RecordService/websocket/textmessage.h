#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H

#include "message_packet.h"
#include <QVariantMap>

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

public:
    explicit TextMessage(QObject *parent = 0);
    TextMessage(QString message, QObject *parent = 0);
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

    Q_INVOKABLE void parse(const QString &message);
    Q_INVOKABLE QString make();

Q_SIGNALS:
    void versionChanged(const QString &version);
    void fromChanged(const QString &from);
    void toChanged(const QString &to);
    void modeChanged(const QString &mode);
    void actionChanged(const QString &action);
    void dataChanged();

public Q_SLOTS:
    void setVersion(const QString &version);
    void setFrom(const QString &from);
    void setTo(const QString &to);
    void setMode(const QString &mode);
    void setAction(const QString &action);
    void setData(const QVariantMap &data);

protected:
    TextMessage(TextMessagePrivate *d, QObject *parent = 0);
    QScopedPointer<TextMessagePrivate> d_ptr;
};

#endif // TEXTMESSAGE_H
