#ifndef BINARYMESSAGE_P_H
#define BINARYMESSAGE_P_H

#include <QObject>

class BinaryMessage;

class BinaryMessagePrivate
{
    Q_DECLARE_PUBLIC(BinaryMessage)
public:
    BinaryMessagePrivate(BinaryMessage* q);

    BinaryMessage* q_ptr;

    int mode;
    QString from;
    QString uuid;
    int timestamp;
    int startpos;
    int status;
    int size;

    QByteArray data;

private:
    const int mode_size;
    const int from_size;
    const int uuid_size;
    const int timestamp_size;
    const int startpos_size;
    const int status_size;
    const int size_size;
    int total_size;
};

#endif // BINARYMESSAGE_P_H
