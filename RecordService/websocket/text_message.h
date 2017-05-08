#ifndef TEXT_MESSAGE_H
#define TEXT_MESSAGE_H

#include <QString>
#include <QVariant>
#include <QObject>

class TextMeassge
{
public:
    TextMeassge();

    int command;
    bool result;
    QVariant data;
};
Q_DECLARE_METATYPE(TextMeassge)

#endif // TEXT_MESSAGE_H
