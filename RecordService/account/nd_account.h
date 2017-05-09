#ifndef ND_ACCOUNT_H
#define ND_ACCOUNT_H

#include <QObject>
#include <QNetworkAccessManager>

class NdAccount : public QObject
{
    Q_OBJECT
public:
    explicit NdAccount(QObject *parent = 0);
    ~NdAccount();

signals:
    void signInResult(QString account, bool ok, QString reason);
    void signOutResult(QString account, bool ok, QString reason);

public slots:
    void userSignIn(QString account, QString password);
    void userSignOut();

private slots:
    void requestFinished(QNetworkReply* reply);

private:
    enum METHOD{
        POST = 0,
        GET,
        DELETE
    };
    enum COMMADN{
        Session = 0,
        IdentifyCode,
        ValidIdentifyCode,
        Smses,
        Login,
        Logout,
        Authorization,
        UserInfo
    };

    QUrl commandToUrl(int command);

    void doRequest(int method ,int command, const QByteArray &data);

    void parseResult(bool error, int command, const QJsonDocument& jsonDocument);

    void encryptAuthorization(int method, QString uri);
    QString makeNonce();
    QString randString();

    QString encryptMD5_Salt(QString content);
    QString hmacSha1(QByteArray key, QByteArray baseString);

private:
    QNetworkAccessManager manager;
    QMap<QNetworkReply *, int> currentRequest;

    const QString HOST = "https://aqapi.101.com";
    const QString ORG_NAME = "ND";

    struct SESSION{
        QString session_id;
        QString session_key;
        int     op_count;
    }_session;

    struct USER{
        QString user_id;
        QString access_token;
        QString expires_at;
        QString refresh_token;
        QString mac_key;
        QString mac_algorithm;
        QString server_time;
        QString warning_code;
    }_user;

    struct AUTHORIZATION{
        QString mac_id;
        QString nonce;
        QString mac;
        QByteArray getAuthorization(){
            QString final;
            final += "MAC id=";
            final.append("\"");
            final += mac_id;
            final.append("\"");
            final += ",";
            final += "nonce=";
            final.append("\"");
            final += nonce;
            final.append("\"");
            final += ",";
            final += "mac=";
            final.append("\"");
            final += mac;
            final.append("\"");

            return final.toUtf8();
        }
    }_authorization;

    struct USER_INFO{
        QString user_id;
        QString user_name;
        QString nick_name;
        QString nick_name_full;
        QString nick_name_short;
        QString realm_exinfo;
        int region;
    }_user_info;
};

#endif // ND_ACCOUNT_H
