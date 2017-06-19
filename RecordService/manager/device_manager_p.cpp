#include "device_manager_p.h"

DeviceManagerPrivate::DeviceManagerPrivate(DeviceManager *q)
    : ClientPrivate(q), protocol(Q_NULLPTR) {}
