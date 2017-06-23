#ifndef CONFERENCE_MODEL_H
#define CONFERENCE_MODEL_H

#include <QSqlTableModel>

class Conference;
class ConferenceModelPrivate;

class ConferenceModel : public QSqlTableModel {
  Q_OBJECT
  Q_DISABLE_COPY(ConferenceModel)
  Q_DECLARE_PRIVATE(ConferenceModel)
 public:
  explicit ConferenceModel(QObject *parent = 0);

  // Define the role names to be used
  enum RoleNames {
    UuidRole = Qt::UserRole,
    TypeRole,
    HostIdRole,
    HostNameRole,
    HostGroupRole,
    HostDeviceRole,
    TitleRole,
    ContentRole,
    MembersRole,
    GpsRole,
    TagRole,
    CreateTimeRole,
    UpdateTimeRole,
    StatusRole,
    RoleCount
  };

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  // return the roles mapping to be used by QML
  QHash<int, QByteArray> roleNames() const override;

  Q_INVOKABLE void addConference(Conference *conference);

 Q_SIGNALS:

 public Q_SLOTS:

 protected:
  ConferenceModel(ConferenceModelPrivate *d, QSqlTableModel *parent = 0);
  QScopedPointer<ConferenceModelPrivate> d_ptr;
};

#endif  // CONFERENCE_MODEL_H
