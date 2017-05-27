#include "textmessage.h"
#include "textmessage_p.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

TextMessage::TextMessage(QObject *parent) :
    QObject(parent),
    d_ptr(new TextMessagePrivate(this))
{

}

TextMessage::TextMessage(TextMessagePrivate *d, QObject *parent) :
    QObject(parent),
    d_ptr(d)
{

}

TextMessage::TextMessage(QString message, QObject *parent) :
    QObject(parent),
    d_ptr(new TextMessagePrivate(this))
{
    this->parse(message);
}

TextMessage::TextMessage(QString from, QString to,
                         QString mode, QString action,
                         QVariantMap data, QObject *parent) :
    QObject(parent),
    d_ptr(new TextMessagePrivate(this))
{
    Q_D(TextMessage);
    d->from = from;
    d->to = to;
    d->command.insert("mode", QJsonValue(mode));
    d->command.insert("action", QJsonValue(action));
    d->data = QJsonObject::fromVariantMap(data);
}

TextMessage::~TextMessage()
{

}

QString TextMessage::version() const
{
    return d_func()->version;
}

QString TextMessage::from() const
{
    return d_func()->from;
}

QString TextMessage::to() const
{
    return d_func()->to;
}

QString TextMessage::mode() const
{
    return d_func()->command.value("mode").toString();
}

QString TextMessage::action() const
{
    return d_func()->command.value("action").toString();
}

QVariantMap TextMessage::data() const
{
    return d_func()->data.toVariantMap();
}

void TextMessage::parse(const QString &message)
{
    QJsonParseError error;
    QJsonDocument jsonDocument  = QJsonDocument::fromJson(message.toUtf8(), &error);

    if(error.error == QJsonParseError::NoError){
        Q_D(TextMessage);
        if(jsonDocument.isObject()){
            QJsonObject object = jsonDocument.object();
            d->version = object.value(QStringLiteral("version")).toString();
            d->authorization = object.value(QStringLiteral("authorization")).toString();
            d->from = object.value(QStringLiteral("from")).toString();
            d->to = object.value(QStringLiteral("to")).toString();
            d->command = object.value(QStringLiteral("command")).toObject();
            d->data = object.value(QStringLiteral("data")).toObject();
        }
        else if(jsonDocument.isArray()){
            qDebug()<<"unsupported json string format, json object is prefered.";
        }
    }
    else{
        qDebug()<<"parse json string failed"<<error.errorString();
    }
}

QString TextMessage::make()
{
    Q_D(TextMessage);
    QJsonObject object;
    object.insert("version", QJsonValue(d->version));
    object.insert("authorization", QJsonValue(d->authorization));
    object.insert("from", QJsonValue(d->from));
    object.insert("to", QJsonValue(d->to));
    object.insert("command", QJsonValue(d->command));
    object.insert("data", QJsonValue(d->data));

    QJsonDocument document;
    document.setObject(object);

    return document.toJson();
}

void TextMessage::setVersion(const QString &version)
{
    Q_D(TextMessage);
    if(version != d->version){
        d->version = version;
        Q_EMIT versionChanged(d->version);
    }
}

void TextMessage::setFrom(const QString &from)
{
    Q_D(TextMessage);
    if(from != d->from){
        d->from = from;
        Q_EMIT fromChanged(d->from);
    }
}

void TextMessage::setTo(const QString &to)
{
    Q_D(TextMessage);
    if(to != d->to){
        d->to = to;
        Q_EMIT toChanged(d->to);
    }
}

void TextMessage::setMode(const QString &mode)
{
    Q_D(TextMessage);
    if(mode != d->command.value("mode").toString()){
        d->command.insert("mode", QJsonValue(mode));
        Q_EMIT modeChanged(d->command.value("mode").toString());
    }
}

void TextMessage::setAction(const QString &action)
{
    Q_D(TextMessage);
    if(action != d->command.value("action").toString()){
        d->command.insert("action", QJsonValue(action));
        Q_EMIT modeChanged(d->command.value("action").toString());
    }
}

void TextMessage::setData(const QVariantMap &data)
{
    Q_D(TextMessage);
    d->data = QJsonObject::fromVariantMap(data);
    Q_EMIT dataChanged();
}

