#ifndef ND_ACCOUNT_P_H
#define ND_ACCOUNT_P_H

#include "account/account_p.h"
#include "nd_account.h"

#include <QHash>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QVariantMap>

class NdAccountPrivate : public AccountPrivate {
  Q_DISABLE_COPY(NdAccountPrivate)
  Q_DECLARE_PUBLIC(NdAccount)
 public:
  NdAccountPrivate(NdAccount *q);

  enum METHOD { POST, GET, DELETE };
  enum COMMAND { SignIn, SignOut, QueryInfo };

  QNetworkAccessManager *manager;
  QHash<QNetworkReply *, int> currentRequest;

  QUrl url;
  const QString ORG_NAME;
  QByteArray authorization;

  QVariantMap userMap;
  QVariantMap userInfoMap;

 public:
  void doRequest(COMMAND command);

  QByteArray encryptAuthorization(METHOD method, QString host, QString path,
                                  QString access_token, QString mac_key);

  QByteArray makeAuthorization(const QString &macId, const QString &nonce,
                               const QString &mac);

  QString makeNonce();
  QString makeRandString();

  QString encryptMD5Salt(QString content);
  QString hmacSha256(QByteArray key, QByteArray baseString);
};

#endif  // ND_ACCOUNT_P_H
