#ifndef SERVICE_BASE_P_H
#define SERVICE_BASE_P_H

#include "service/service_base.h"

class TransportThread;
class ProcessThread;
class MessageQueue;
class MessageSocket;
class QThread;

class ServiceBasePrivate {
  Q_DISABLE_COPY(ServiceBasePrivate)
  Q_DECLARE_PUBLIC(ServiceBase)
 public:
  ServiceBasePrivate(ServiceBase *q);
  ~ServiceBasePrivate();

  ServiceBase *q_ptr;

  QThread *main_thread;
  QThread *socket_thread;
  MessageSocket *socket;
  TransportThread *transport_thread;
  ProcessThread *process_thread;
  MessageQueue *transport_queue;
  MessageQueue *process_queue;
  QHash<QString, ProtoBase *> protocols;

  bool active;
  ServiceBase::Status status;
  QString errorString;
  QUrl url;
  Device *device;
  QString uuid;

  DeviceManager *deviceManager;
};

#endif  // SERVICE_BASE_P_H
