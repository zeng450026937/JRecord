#ifndef SERVICE_BASE_H
#define SERVICE_BASE_H

#include <QThread>

class MessageSocket;
class ServiceBasePrivate;

class ServiceBase : public QThread
{
    Q_OBJECT
    Q_DISABLE_COPY(ServiceBase)
    Q_DECLARE_PRIVATE(ServiceBase)
public:
    static ServiceBase *GetInstance();
    static bool DeleteInstance(ServiceBase *instance);

    int AddRef();
    int Release();

    //avariable when service is started.
    MessageSocket *messageSocket();

public Q_SLOTS:

Q_SIGNALS:
    void serviceStarted();
    void serviceStopped();

private Q_SLOTS:
    void onStarted();
    void onFinished();

protected:
    void run() override;
    ServiceBase(QObject *parent = 0);
    ServiceBase(ServiceBasePrivate *d, QObject *parent = 0);
    ~ServiceBase();
    QScopedPointer<ServiceBasePrivate> d_ptr;
};

#endif // SERVICE_BASE_H
