#include "message_socket_p.h"

MessageSocketPrivate::MessageSocketPrivate(MessageSocket *q)
    : q_ptr(q), socket(Q_NULLPTR), active(false) {}
