#ifndef BINARYMESSAGE_H
#define BINARYMESSAGE_H

#include <QObject>
#include "message_packet.h"

class BinaryMessagePrivate;

class BinaryMessage : public QObject, public MessagePacket
{
    Q_OBJECT
    Q_DISABLE_COPY(BinaryMessage)
    Q_DECLARE_PRIVATE(BinaryMessage)

    Q_PROPERTY(int mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(QString from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QString uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
    Q_PROPERTY(int timestamp READ timestamp WRITE setTimestamp NOTIFY timestampChanged)
    Q_PROPERTY(int startpos READ startpos WRITE setStartpos NOTIFY startposChanged)
    Q_PROPERTY(int status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(int size READ size WRITE setSize NOTIFY sizeChanged)

public:
    explicit BinaryMessage(QObject *parent = 0);
    BinaryMessage(QByteArray message, QObject *parent = 0);

    MessageType type() { return Binary; }

    int mode() const;
    QString from() const;
    QString uuid() const;
    int timestamp() const;
    int startpos() const;
    int status() const;
    int size() const;

    Q_INVOKABLE void parse(QByteArray message);
    Q_INVOKABLE QByteArray make();

Q_SIGNALS:
    void modeChanged(int mode);
    void fromChanged(QString from);
    void uuidChanged(QString uuid);
    void timestampChanged(int timestamp);
    void startposChanged(int startpos);
    void statusChanged(int status);
    void sizeChanged(int size);

public Q_SLOTS:
    void setMode(int mode);
    void setFrom(const QString &from);
    void setUuid(const QString &uuid);
    void setTimestamp(int timestamp);
    void setStartpos(int startpos);
    void setStatus(int status);
    void setSize(int size);

protected:
    BinaryMessage(BinaryMessagePrivate *d, QObject *parent = 0);
    QScopedPointer<BinaryMessagePrivate> d_ptr;

};


#endif // BINARYMESSAGE_H