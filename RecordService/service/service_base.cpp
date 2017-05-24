#include "service_base.h"
#include "service/service_base_p.h"

#include "websocket/message_socket.h"
#include "websocket/transport_thread.h"
#include "websocket/process_thread.h"
#include "websocket/message_queue.h"

#include <QDebug>

static ServiceBase *gServiceInstance = Q_NULLPTR;

//static
ServiceBase *ServiceBase::GetInstance()
{
    if(!gServiceInstance){
        gServiceInstance = new ServiceBase();
        if(!gServiceInstance)
            gServiceInstance->AddRef();
    }
    else{
        gServiceInstance->AddRef();
    }
    return gServiceInstance;
}

//static
bool ServiceBase::DeleteInstance(ServiceBase *instance)
{
    if(!instance)
        return false;

    int ref = instance->Release();
    instance = Q_NULLPTR;

    if(ref != 0) {
        qDebug()<<"Delete did not release the very last reference.";
    }
    return true;
}

int ServiceBase::AddRef()
{
    Q_D(ServiceBase);
    return ++d->ref;
}

int ServiceBase::Release()
{
    Q_D(ServiceBase);
    int new_ref = --d->ref;

    if(new_ref == 0)
        delete this;

    return new_ref;
}

MessageSocket *ServiceBase::messageSocket()
{
    Q_D(ServiceBase);
    return d->socket;
}

void ServiceBase::onStarted()
{
    Q_EMIT serviceStarted();
}

void ServiceBase::onFinished()
{
    Q_D(ServiceBase);
    if(d->transport_queue)
        delete d->transport_queue;
    if(d->process_queue)
        delete d->process_queue;
    if(d->transport_thread)
        delete d->transport_thread;
    if(d->process_thread)
        delete d->process_thread;
    if(d->socket)
        delete d->socket;

    Q_EMIT serviceStopped();
}

void ServiceBase::run()
{
    Q_D(ServiceBase);
    d->socket = new MessageSocket(true, Q_NULLPTR);
    d->transport_thread = new TransportThread;
    d->process_thread = new ProcessThread;
    d->transport_queue = new MessageQueue;
    d->process_queue = new MessageQueue;

    d->transport_thread->setQueue(d->transport_queue);
    d->process_thread->setQueue(d->process_queue);
    d->socket->setTransportThread(d->transport_thread);
    d->socket->setProcessThread(d->process_thread);

    this->exec();
}

ServiceBase::ServiceBase(QObject *parent) :
    QThread(parent),
    d_ptr(new ServiceBasePrivate(this))
{
    connect(this,SIGNAL(started()),this,SLOT(onStarted()));
    connect(this,SIGNAL(finished()),this,SLOT(onFinished()));

    this->start();
}
ServiceBase::ServiceBase(ServiceBasePrivate *d, QObject *parent) :
    QThread(parent),
    d_ptr(d)
{
    connect(this,SIGNAL(started()),this,SLOT(onStarted()));
    connect(this,SIGNAL(finished()),this,SLOT(onFinished()));

    this->start();
}

ServiceBase::~ServiceBase()
{
    if(this->isRunning()){
        this->quit();
        this->wait(3000);
    }
}
