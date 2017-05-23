#ifndef MESSAGE_SOCKET_H
#define MESSAGE_SOCKET_H

#include <QObject>
#include <QNetworkRequest>

class TransportThread;
class ProcessThread;
class MessageSocketPrivate;

//to avoid process SIGNAL/SLOT in main thread
//create/move MessageSocket in/to other event thread is recommended
class MessageSocket : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MessageSocket)
    Q_DECLARE_PRIVATE(MessageSocket)

public:
    static MessageSocket *CreateInstance(bool multithread);
    static bool DeleteInstance(MessageSocket* instance);

    int AddRef();
    int Release();

    enum Status{
        Connecting,
        Open,
        Closing,
        Closed,
        Error
    };
    Q_ENUM(Status)

    void setTransportThread(TransportThread *transport);
    TransportThread *transportThread() const;

    void setProcessThread(ProcessThread *process);
    ProcessThread *processThread() const;

Q_SIGNALS:
    void connected();
    void disconnected();
    void statusChanged(Status status);

public Q_SLOTS:
    void open(const QNetworkRequest &authorization);
    void close();

protected:
    explicit MessageSocket(bool multithread = true, QObject *parent = Q_NULLPTR);
    MessageSocket(MessageSocketPrivate *d, QObject *parent = Q_NULLPTR);
    QScopedPointer<MessageSocketPrivate> d_ptr;
};

#endif // MESSAGE_SOCKET_H
