#include "nd_account_p.h"

#include <QCryptographicHash>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkRequest>
#include <QTimer>

NdAccountPrivate::NdAccountPrivate(NdAccount* q)
    : AccountPrivate(q),
      manager(Q_NULLPTR),
      url(QStringLiteral("https://aqapi.101.com")),
      ORG_NAME(QStringLiteral("ND")) {}

void NdAccountPrivate::doRequest(NdAccountPrivate::COMMAND command) {
  METHOD method;
  QString path;
  QByteArray data;
  QJsonObject content;
  QJsonDocument docment;

  switch ((int)command) {
    case SignIn:
      method = POST;
      path = QStringLiteral("/v0.93/tokens");

      content.insert("login_name", QJsonValue(userId));
      content.insert("password", QJsonValue(this->encryptMD5Salt(password)));
      content.insert("org_name", QJsonValue(ORG_NAME));
      break;
    case SignOut:
      method = DELETE;
      path = QString("/v0.93/tokens/%1")
                 .arg(userMap.value(QStringLiteral("access_token")).toString());
      break;
    case QueryInfo:
      method = GET;
      path = QString("/v0.93/users/%1?realm=%2")
                 .arg(userMap.value(QStringLiteral("user_id")).toString(),
                      QStringLiteral("uc.sdp.nd"));

      authorization = this->encryptAuthorization(
          GET, url.host(), path,
          userMap.value(QStringLiteral("access_token")).toString(),
          userMap.value(QStringLiteral("mac_key")).toString());
      break;
    default:
      break;
  }

  url.setPath(path);
  docment.setObject(content);
  data = docment.toJson();

  // the url will be encodeed when use QUrl directly, but server is not
  // supported yet.
  QNetworkRequest request(QUrl(QStringLiteral("https://") +
                               QStringLiteral("aqapi.101.com") + path));
  request.setRawHeader("Accept", "application/json");

  QNetworkReply* reply(Q_NULLPTR);

  switch (method) {
    case POST:
      request.setHeader(QNetworkRequest::ContentTypeHeader,
                        QVariant("application/json"));
      request.setHeader(QNetworkRequest::ContentLengthHeader,
                        QVariant(data.size()));
      reply = manager->post(request, data);
      break;
    case GET:
      request.setRawHeader("Authorization", authorization);
      reply = manager->get(request);
      break;
    case DELETE:
      reply = manager->deleteResource(request);
      break;
  }

  currentRequest.insert(reply, (int)command);
}

QByteArray NdAccountPrivate::encryptAuthorization(
    NdAccountPrivate::METHOD method, QString host, QString path,
    QString access_token, QString mac_key) {
  QString httpMethod;
  switch ((int)method) {
    case POST:
      httpMethod = QStringLiteral("POST");
      break;
    case GET:
      httpMethod = QStringLiteral("GET");
      break;
    case DELETE:
      httpMethod = QStringLiteral("DELETE");
      break;
  }

  QString macId = access_token;
  QString nonce = this->makeNonce();
  QString mac;
  mac += nonce;
  mac += "\n";
  mac += httpMethod;
  mac += "\n";
  mac += path;
  mac += "\n";
  mac += host;
  mac += "\n";

  mac = this->hmacSha256(mac_key.toUtf8(), mac.toUtf8());

  QString auth;
  auth += "MAC id=";
  auth.append("\"");
  auth += macId;
  auth.append("\"");
  auth += ",";
  auth += "nonce=";
  auth.append("\"");
  auth += nonce;
  auth.append("\"");
  auth += ",";
  auth += "mac=";
  auth.append("\"");
  auth += mac;
  auth.append("\"");

  return auth.toUtf8();
}

QString NdAccountPrivate::makeNonce() {
  QString nonce;
  nonce += QString::number(QDateTime::currentMSecsSinceEpoch());
  nonce += ":";
  nonce += this->makeRandString();

  return nonce;
}

QString NdAccountPrivate::makeRandString() {
  QString randString;

  int max = 8;
  QString tmp = QString("0123456789ABCDEFGHIJKLMNOPQRSTUVWZYZ");
  QTime t;
  t = QTime::currentTime();
  qsrand(t.msec() + t.second() * 1000);
  for (int i = 0; i < max; i++) {
    int ir = qrand() % tmp.length();
    randString.append(tmp.at(ir));
  }

  return randString;
}

QString NdAccountPrivate::encryptMD5Salt(QString content) {
  QString appkey = "fdjf,jkgfkl";

  QByteArray a = appkey.toUtf8();
  QByteArray datSource = content.toUtf8();
  QByteArray b;
  b.resize(a.length() + 4 + datSource.length());

  int i;
  for (i = 0; i < datSource.length(); i++) {
    b.data()[i] = datSource.constData()[i];
  }

  b.data()[i++] = (char)163;
  b.data()[i++] = (char)172;
  b.data()[i++] = (char)161;
  b.data()[i++] = (char)163;

  for (int k = 0; k < a.length(); k++) {
    b.data()[i] = a.constData()[k];
    i++;
  }

  QByteArray md5;
  md5 = QCryptographicHash::hash(b, QCryptographicHash::Md5);

  md5 = md5.toHex();

  return QString(md5);
}

QString NdAccountPrivate::hmacSha256(QByteArray key, QByteArray baseString) {
  int blockSize = 64;  // HMAC-SHA-1 block size, defined in SHA256 standard
  if (key.length() > blockSize) {  // if key is longer than block size (64),
                                   // reduce key length with SHA256 compression
    key = QCryptographicHash::hash(key, QCryptographicHash::Sha256);
  }

  QByteArray innerPadding(
      blockSize, char(0x36));  // initialize inner padding with char "6"
  QByteArray outerPadding(
      blockSize, char(0x5c));  // initialize outer padding with char "quot;
  // ascii characters 0x36 ("6") and 0x5c ("quot;) are selected because they
  // have large
  // Hamming distance (http://en.wikipedia.org/wiki/Hamming_distance)

  for (int i = 0; i < key.length(); i++) {
    innerPadding[i] =
        innerPadding[i] ^ key.at(i);  // XOR operation between every byte in key
                                      // and innerpadding, of key length
    outerPadding[i] =
        outerPadding[i] ^ key.at(i);  // XOR operation between every byte in key
                                      // and outerpadding, of key length
  }

  // result = hash ( outerPadding CONCAT hash ( innerPadding CONCAT baseString )
  // ).toBase64
  QByteArray total = outerPadding;
  QByteArray part = innerPadding;
  part.append(baseString);
  total.append(QCryptographicHash::hash(part, QCryptographicHash::Sha256));
  QByteArray hashed =
      QCryptographicHash::hash(total, QCryptographicHash::Sha256);
  return hashed.toBase64();
}
