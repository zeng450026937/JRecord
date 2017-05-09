#include "message_packet.h"
#include <QJsonDocument>
#include <QBuffer>
#include <QDebug>

TextMessage::TextMessage(QString msg):
    d_ptr(new TextMessageData)
{
    //this->parse(msg);
}
TextMessage::~TextMessage()
{
    delete d_ptr;
}

void TextMessage::process()
{
    qDebug()<<QObject::tr("process text message.");
}

void TextMessage::parse(QString msg)
{
    QJsonParseError error;
    QJsonDocument jsonDocument  = QJsonDocument::fromJson(msg.toUtf8(), &error);

    if(error.error == QJsonParseError::NoError){
        if(jsonDocument .isObject()){
            QVariantMap content = jsonDocument.toVariant().toMap();
            d_ptr->result = content.value("RESULT").toString();
            d_ptr->data = content.value("DATA").toMap();
            d_ptr->command = content.value("COMMAND").toString();
        }
    }
    else{
        qDebug()<<"parse json string failed"<<error.errorString();
    }
}
//static
QByteArray TextMessage::makeMessage(QString sender, QString receiver, QString command, QVariantMap data)
{
    QVariantMap json_command;

    json_command.insert("SENDER", sender);
    json_command.insert("RECEIVER", receiver);
    json_command.insert("COMMAND", command);
    json_command.insert("DATA", data);

    QJsonDocument jsonDocument  = QJsonDocument::fromVariant(json_command);

    return jsonDocument.toJson();
}

BinaryMessage::BinaryMessage(QByteArray msg):
    d_ptr(new BinaryMessageData)
{
    //this->parse(msg);
}
BinaryMessage::~BinaryMessage()
{
    delete d_ptr;
}

void BinaryMessage::process()
{
    qDebug()<<QObject::tr("process binary message.");
}
void BinaryMessage::parse(QByteArray msg)
{
    QBuffer buffer(&msg);
    buffer.open(QIODevice::ReadOnly);

    buffer.seek(0);

    bool ok(false);

    d_ptr->type = buffer.read(d_ptr->type_size).toHex().toUInt(&ok,16);
    //qDebug()<<"type"<<type<<ok;

    d_ptr->sender = QString::fromLatin1(buffer.read(d_ptr->sender_size));
    //qDebug()<<"sender"<<sender;

    d_ptr->file_uuid = QString::fromLatin1(buffer.read(d_ptr->file_uuid_size));
    //qDebug()<<"file_uuid"<<file_uuid;

    d_ptr->meeting_time = buffer.read(d_ptr->meeting_time_size).toHex().toUInt(&ok,16);
    //qDebug()<<"meeting_time"<<meeting_time<<ok;

    d_ptr->file_startpos = buffer.read(d_ptr->file_startpos_size).toHex().toULong(&ok,16);
    //qDebug()<<"file_startpos"<<file_startpos<<ok;

    d_ptr->file_status = buffer.read(d_ptr->file_status_size).toHex().toULong(&ok,16);
    //qDebug()<<"file_status"<<file_status<<ok;

    d_ptr->data_size = buffer.read(d_ptr->data_size_size).toHex().toULong(&ok,16);
    //qDebug()<<"data_size"<<data_size<<ok;

    if(d_ptr->data_size >= 0){
        d_ptr->data = buffer.read(d_ptr->data_size);
    }
}


