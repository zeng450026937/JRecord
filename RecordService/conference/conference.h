#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <QDate>
#include <QQmlListProperty>
#include "client/client.h"
#include "user/user.h"

class ConferencePrivate;

class Conference : public Client {
  Q_OBJECT
  Q_DISABLE_COPY(Conference)
  Q_DECLARE_PRIVATE(Conference)

  Q_PROPERTY(User *host READ host WRITE setHost NOTIFY hostChanged)
  Q_PROPERTY(QString uuid READ uuid)
  Q_PROPERTY(QDate createTime READ createTime)
  Q_PROPERTY(QDate updateTime READ updateTime)
  Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
  Q_PROPERTY(
      QString content READ content WRITE setContent NOTIFY contentChanged)
  Q_PROPERTY(QString member READ member WRITE setMember NOTIFY memberChanged)
  Q_PROPERTY(QQmlListProperty<User> userlist READ userlist)
  Q_CLASSINFO("DefaultProperty", "userlist")

 public:
  explicit Conference(QObject *parent = 0);

  enum Status { Comfirming, Created, Recording, Pausing, Finished, Error };
  Q_ENUM(Status)

  enum Type { Normal, Personal, Mobile };
  Q_ENUM(Type)

  Q_INVOKABLE void lock();
  Q_INVOKABLE void unlock();
  Q_INVOKABLE void create();
  Q_INVOKABLE void start();
  Q_INVOKABLE void pause();
  Q_INVOKABLE void resume();
  Q_INVOKABLE void stop();
  Q_INVOKABLE void join(const QString &uuid);
  Q_INVOKABLE void leave();
  Q_INVOKABLE void query(Type type, const QString &uuid = "");

  User *host() const;
  QString uuid() const;
  QDate createTime();
  QDate updateTime();
  QString title() const;
  QString content() const;
  QString member() const;
  QQmlListProperty<User> userlist();

 Q_SIGNALS:
  void hostChanged();
  void titleChanged(const QString &title);
  void contentChanged(const QString &content);
  void memberChanged(const QString &member);

 public Q_SLOTS:
  void setHost(User *host);
  void setTitle(const QString &title);
  void setContent(const QString &content);
  void setMember(const QString &member);
};

#endif  // CONFERENCE_H
