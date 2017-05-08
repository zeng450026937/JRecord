#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QObject>

class WebSocketPrivate;

class WebSocket : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(WebSocket)
    Q_DECLARE_PRIVATE(WebSocket)

    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

public:
    explicit WebSocket(QObject *parent = Q_NULLPTR);

    enum Status{
        Connecting,
        Open,
        Closing,
        Closed,
        Error
    };
    Q_ENUM(Status)

    Q_INVOKABLE void socketConnect();
    Q_INVOKABLE void socketDisconnect();

    QString url() const;

Q_SIGNALS:
    void urlChanged(QString url);
    void statusChanged(Status status);

public Q_SLOTS:
    void setUrl(QString url);

private:
    void setStatus(Status status);

protected:
    QScopedPointer<WebSocketPrivate> d_ptr;

};

#endif // WEBSOCKET_H
