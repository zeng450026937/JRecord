#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <QDateTime>
#include <QJsonObject>
#include "client/client.h"

class Device;
class ConferencePrivate;

class Conference : public Client {
  Q_OBJECT
  Q_DISABLE_COPY(Conference)
  Q_DECLARE_PRIVATE(Conference)

  Q_PROPERTY(QString uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
  Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)
  Q_PROPERTY(Device *host READ host WRITE setHost NOTIFY hostChanged)
  Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
  Q_PROPERTY(
      QString content READ content WRITE setContent NOTIFY contentChanged)
  Q_PROPERTY(QString member READ member WRITE setMember NOTIFY memberChanged)
  Q_PROPERTY(QString gps READ gps WRITE setGps NOTIFY gpsChanged)
  Q_PROPERTY(QString tag READ tag WRITE setTag NOTIFY tagChanged)
  Q_PROPERTY(QDateTime createTime READ createTime WRITE setCreateTime NOTIFY
                 createTimeChanged)
  Q_PROPERTY(QDateTime updateTime READ updateTime WRITE setUpdateTime NOTIFY
                 updateTimeChanged)
  Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
  Q_PROPERTY(QString errorString READ errorString WRITE setErrorString NOTIFY
                 errorStringChanged)

 public:
  explicit Conference(QObject *parent = 0);
  Conference(const QJsonObject &json, QObject *parent = 0);

  enum Status { Comfirming, Created, Recording, Pausing, Finished, Error };
  Q_ENUM(Status)

  enum Type { Normal, Personal, Mobile, Unknown };
  Q_ENUM(Type)

  void fromJson(const QJsonObject &json);
  QJsonObject toJson();

  Q_INVOKABLE void create();
  Q_INVOKABLE void start();
  Q_INVOKABLE void pause();
  Q_INVOKABLE void resume();
  Q_INVOKABLE void stop();
  Q_INVOKABLE void query();

  QString uuid() const;
  Type type() const;
  Device *host() const;
  QString title() const;
  QString content() const;
  QString member() const;
  QString gps() const;
  QString tag() const;
  QDateTime createTime() const;
  QDateTime updateTime() const;
  Status status() const;
  QString errorString() const;

 Q_SIGNALS:
  void uuidChanged(const QString &uuid);
  void typeChanged(Type type);
  void hostChanged(const Device *host);
  void titleChanged(const QString &title);
  void contentChanged(const QString &content);
  void memberChanged(const QString &member);
  void gpsChanged(const QString &gps);
  void tagChanged(const QString &tag);
  void createTimeChanged(const QDateTime &createTime);
  void updateTimeChanged(const QDateTime &updateTime);
  void statusChanged(const Status status);
  void errorStringChanged(const QString &errorString);

 public Q_SLOTS:
  void setUuid(const QString &uuid);
  void setType(Type type);
  void setHost(Device *host);
  void setTitle(const QString &title);
  void setContent(const QString &content);
  void setMember(const QString &member);
  void setGps(const QString &gps);
  void setTag(const QString &tag);
  void setCreateTime(const QDateTime &createTime);
  void setUpdateTime(const QDateTime &updateTime);
  void setStatus(const Status status);
  void setErrorString(const QString &errorString);

 protected:
  Conference(ConferencePrivate *d, QObject *parent = 0);
  friend class ConferenceManager;
};

#endif  // CONFERENCE_H
