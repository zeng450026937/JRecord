#include "process_thread.h"
#include <QDebug>
#include "binarymessage.h"
#include "message_queue.h"
#include "message_socket.h"
#include "process_thread_p.h"
#include "protocol/proto_base.h"
#include "task/task_manager.h"
#include "textmessage.h"

ProcessThread::ProcessThread(QObject *parent)
    : MessageThread(new ProcessThreadPrivate(this), parent) {
  QObject::connect(
      this, &ProcessThread::socketChanged, [this](MessageSocket *socket) {
        Q_D(ProcessThread);
        QObject::disconnect(d->textConnection);
        QObject::disconnect(d->binaryConnection);

        d->textConnection = QObject::connect(
            socket, &MessageSocket::textReceived,
            [this](const QString &message) {
              pushMessage(
                  QSharedPointer<MessagePacket>(new TextMessage(message)));
            });
        d->binaryConnection = QObject::connect(
            socket, &MessageSocket::binaryReceived,
            [this](const QByteArray &message) {
              pushMessage(
                  QSharedPointer<MessagePacket>(new BinaryMessage(message)));
            });
      });
}

ProcessThread::~ProcessThread() {
  if (this->isRunning()) {
    Q_D(ProcessThread);
    d->queue->setActive(false);
    this->quit();
    this->wait(3000);
  }
}

void ProcessThread::run() {
  Q_D(ProcessThread);
  do {
    if (d->queue == Q_NULLPTR || !d->queue->active()) return;

    for (;;) {
      QSharedPointer<MessagePacket> pkt =
          d->queue->pop();  // block until new data arrived

      if (pkt.isNull()) return;

      Q_EMIT beforeProcess(pkt);

      if (pkt->type() == MessagePacket::Text) {
        QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
        if (msg) {
          //          if (msg->action() != "heartBeat" &&
          //              msg->action() != "notifyPersonRecordAdd" &&
          //              msg->action() != "getConferenceList" &&
          //              msg->action() != "getPersonalList")
          qDebug() << "received:" << msg->command();
          ProtoBase *protocol = d->protocols->value(msg->mode(), Q_NULLPTR);
          if (protocol) {
            protocol->process(pkt);
          }
        }
      }
      if (pkt->type() == MessagePacket::Binary) {
        QSharedPointer<BinaryMessage> msg = pkt.dynamicCast<BinaryMessage>();
        if (msg) {
          ProtoBase *protocol =
              d->protocols->value(QStringLiteral("binary"), Q_NULLPTR);
          if (protocol) {
            protocol->process(pkt);
          }
          qDebug() << "received binary.";
        }
      }

      Q_EMIT afterProcess(pkt);
    }

  } while (d->queue->active());
}
