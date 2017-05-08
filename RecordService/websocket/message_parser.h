#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <QObject>

class BinaryReader;

class MessageParser : public QObject
{
    Q_OBJECT
public:
    explicit MessageParser(QObject *parent = 0);

Q_SIGNALS:
    void commandReceived(int command, bool result, QVariantMap data);
    /*
     user should take the ownership of BinaryReader
    */
    void binaryReceived(BinaryReader* reader);

public Q_SLOTS:
    void parseMessage(QString message);
    void parseBinary(QByteArray binary);

    QByteArray makeMessgae(int command, QString sender, QString receiver, QVariantMap data);

public:
    enum Command{
        CreateConference,
        StartConference,
        PauseConference,
        StopConference,
        SetConferenceInfo,
        DeleteConferenceInfo,
        GetConferenceInfo,
        GetConferenceList,

        NotifyPersonRecordAdd,
        NotifyPersonRecordUpdate,
        NotifyPersonRecordDelete,
        GetPersonalList,
        GetAllPersonalList,

        AddDevice,
        RemoveDevice,
        GetDeviceList,

        AddTemplateInfo,
        SetTemplateInfo,
        DeleteTemplateInfo,
        GetTemplateInfo,
        GetTemplateList,

        AddMarkInfo,
        SetMarkInfo,
        DelMarkInfo,
        GetMarkinfo,
        GetMarkList,

        DownloadFile,
        DownloadFileAck,
        NotifyNewDataRecv,
        LoginDevice,
        HeartBeat,
        NotifyDeviceInfoChange,
        DeviceEnvironmentException
    };
    Q_ENUM(Command)
};

#endif // COMMAND_PARSER_H
