#include "record_manager.h"
#include "record_manager_p.h"
#include "service/service_base.h"

RecordManager::RecordManager(QObject *parent)
    : Client(parent), d_ptr(new RecordManagerPrivate(this)) {
  Q_D(RecordManager);
  d->protocol = (ProtoBinary *)d->service->protocol(QStringLiteral("info"));
}

Record *RecordManager::record(const QString &uuid) {
  Q_D(RecordManager);
  return d->recordMap.value(uuid, Q_NULLPTR);
}

RecordManager::RecordManager(RecordManagerPrivate *d, QObject *parent)
    : Client(parent), d_ptr(d) {}
