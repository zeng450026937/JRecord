#ifndef TEXTMESSAGE_P_H
#define TEXTMESSAGE_P_H

#include <QObject>
#include <QJsonObject>

class TextMessage;

class TextMessagePrivate
{
    Q_DISABLE_COPY(TextMessagePrivate)
    Q_DECLARE_PUBLIC(TextMessage)
public:
    TextMessagePrivate(TextMessage *q);

    TextMessage* q_ptr;

    QString version;
    QString authorization;//reserved
    QString from;
    QString to;
    QJsonObject command;
    QJsonObject data;
};

#endif // TEXTMESSAGE_P_H
