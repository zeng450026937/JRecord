#include "nd_account.h"
#include "nd_account_p.h"

#include <QCryptographicHash>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QTimer>
#include <QtConcurrent>

NdAccount::NdAccount(QObject *parent)
    : Account(new NdAccountPrivate(this), parent) {
  Q_D(NdAccount);
  d->manager = new QNetworkAccessManager(this);

  QTimer::singleShot(1000, []() {
    QtConcurrent::run([]() {
      // QNetworkAccessManager will take long time to excute at first call
      // do the first call in threaded
      // see QTBUG-10106
      QScopedPointer<QNetworkAccessManager> m(new QNetworkAccessManager);
      m->post(QNetworkRequest(), QByteArray());
    });
  });

  QObject::connect(
      d->manager, &QNetworkAccessManager::finished, this,
      [this, d](QNetworkReply *reply) {
        QJsonParseError error;
        QJsonDocument document =
            QJsonDocument::fromJson(reply->readAll(), &error);

        if (error.error == QJsonParseError::NoError) {
          if (document.isObject()) {
            if (reply->error() == QNetworkReply::NoError) {
              switch (d->currentRequest.value(reply, -1)) {
                case NdAccountPrivate::SignIn:
                  d->userMap = document.object().toVariantMap();
                  d->userId =
                      d->userMap.value(QLatin1String("user_id")).toString();
                  Q_EMIT userIdChanged(d->userId);
                  d->status = NdAccount::Login;
                  Q_EMIT statusChanged(d->status);
                  d->active = true;
                  Q_EMIT activeChanged(d->active);
                  d->doRequest(NdAccountPrivate::QueryInfo);
                  break;
                case NdAccountPrivate::SignOut:
                  d->status = NdAccount::Logout;
                  Q_EMIT statusChanged(d->status);
                  d->active = false;
                  Q_EMIT activeChanged(d->active);
                  break;
                case NdAccountPrivate::QueryInfo:
                  d->userInfoMap = document.object().toVariantMap();
                  d->userId =
                      d->userInfoMap.value(QLatin1String("user_id")).toString();
                  Q_EMIT userIdChanged(d->userId);
                  d->userName =
                      d->userInfoMap.value(QLatin1String("org_exinfo"))
                          .toMap()
                          .value("username")
                          .toString();
                  Q_EMIT userNameChanged(d->userName);
                  d->image = QString(
                                 "http://cs.101.com/v0.1/static/cscommon/"
                                 "avatar/%1/%1.jpg")
                                 .arg(d->userId);
                  Q_EMIT imageChanged(d->image);
                  d->signature =
                      d->userInfoMap.value(QLatin1String("realm_exinfo"))
                          .toMap()
                          .value("uc.sdp.nd.signature")
                          .toString();
                  Q_EMIT signatureChanged(d->signature);
                  break;
                default:
                  break;
              }
            } else {
              d->errorString =
                  document.object().value(QLatin1String("message")).toString();
              Q_EMIT errorStringChanged(d->errorString);
              d->status = NdAccount::Error;
              Q_EMIT statusChanged(d->status);
            }
          } else {
            qDebug() << "content is not an object.";
          }
        } else {
          qDebug() << "parse raw header failed:" << error.errorString();
        }

        d->currentRequest.remove(reply);
        reply->deleteLater();
      });

  QObject::connect(this, &NdAccount::statusChanged, [d](const Status status) {
    if (status == Logining)
      d->doRequest(NdAccountPrivate::SignIn);
    else if (status == Logouting)
      d->doRequest(NdAccountPrivate::SignOut);
  });
}

NdAccount::~NdAccount() { this->setActive(false); }
