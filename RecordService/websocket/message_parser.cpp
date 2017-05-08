#include "message_parser.h"
#include <QMetaEnum>
#include <QJsonDocument>
#include <QDebug>
#include "binary_message.h"

MessageParser::MessageParser(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<BinaryReader>();
}
void MessageParser::parseMessage(QString message)
{
    QJsonParseError error;
    QJsonDocument jsonDocument  = QJsonDocument::fromJson(message.toUtf8(), &error);

    if(error.error == QJsonParseError::NoError){
        if(jsonDocument .isObject()){
            QVariantMap content = jsonDocument.toVariant().toMap();
            QString result = content.value("RESULT").toString();
            QVariant data = content.value("DATA");
            QString command = content.value("COMMAND").toString();

            QMetaObject MetaObject = this->staticMetaObject;
            QMetaEnum MetaEnum = MetaObject.enumerator(MetaObject.indexOfEnumerator("Command"));

            Q_EMIT commandReceived(MetaEnum.keysToValue(command.toLatin1()), (result=="true")?true:false, data.toMap());
        }
    }
    else{
        qDebug()<<"parse json string failed"<<error.errorString();
    }
}
void MessageParser::parseBinary(QByteArray binary)
{
    BinaryReader* reader = new BinaryReader(binary);
    Q_EMIT binaryReceived(reader);
}
QByteArray MessageParser::makeMessgae(int command, QString sender, QString receiver, QVariantMap data)
{
    QMetaObject MetaObject = this->staticMetaObject;
    QMetaEnum MetaEnum = MetaObject.enumerator(MetaObject.indexOfEnumerator("Command"));

    QVariantMap json_command;

    json_command.insert("SENDER", sender);
    json_command.insert("RECEIVER", receiver);
    json_command.insert("COMMAND", MetaEnum.valueToKeys(command));
    json_command.insert("DATA", data);

    QJsonDocument jsonDocument  = QJsonDocument::fromVariant(json_command);

    return jsonDocument.toJson();
}

