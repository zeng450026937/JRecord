#include "binarymessage_p.h"

BinaryMessagePrivate::BinaryMessagePrivate(BinaryMessage *q) :
    q_ptr(q),
    mode(0),
    mode_size(4),
    from(""),
    from_size(17),
    uuid(""),
    uuid_size(32),
    timestamp(0),
    timestamp_size(4),
    startpos(0),
    startpos_size(4),
    status(0),
    status_size(4),
    size(0),
    size_size(4)
{
    total_size = mode_size + from_size + uuid_size +
                 timestamp_size + startpos_size +
                 status_size + size_size;
}
