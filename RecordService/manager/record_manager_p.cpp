#include "record_manager_p.h"

RecordManagerPrivate::RecordManagerPrivate(RecordManager *q)
    : ClientPrivate(q), protocol(Q_NULLPTR) {}
