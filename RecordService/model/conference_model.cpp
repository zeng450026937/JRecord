#include "conference_model.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include "conference/conference.h"
#include "conference_model_p.h"
#include "device/device.h"
#include "sql_initializer.h"
#include "user/user.h"

ConferenceModel::ConferenceModel(QObject *parent)
    : QSqlTableModel(parent, QSqlDatabase::database()),
      d_ptr(new ConferenceModelPrivate(this)) {
  createConferenceTable();

  setTable(conferenceTableName);
  // setSort(8, Qt::AscendingOrder);
  // Ensures that the model is sorted correctly after submitting a new row.
  setEditStrategy(QSqlTableModel::OnManualSubmit);

  select();

  Q_D(ConferenceModel);

  // Set names to the role name hash container (QHash<int, QByteArray>)
  d->roleNames[UuidRole] = "uuid";
  d->roleNames[TypeRole] = "type";
  d->roleNames[HostIdRole] = "hostId";
  d->roleNames[HostNameRole] = "hostName";
  d->roleNames[HostGroupRole] = "hostGroup";
  d->roleNames[HostDeviceRole] = "hostDevice";
  d->roleNames[TitleRole] = "title";
  d->roleNames[ContentRole] = "content";
  d->roleNames[MembersRole] = "member";
  d->roleNames[GpsRole] = "gps";
  d->roleNames[TagRole] = "tag";
  d->roleNames[CreateTimeRole] = "createTime";
  d->roleNames[UpdateTimeRole] = "updateTime";
  d->roleNames[StatusRole] = "status";
}

QVariant ConferenceModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) return QVariant();

  if (role < Qt::UserRole) return QSqlTableModel::data(index, role);

  const QSqlRecord sqlRecord = record(index.row());
  return sqlRecord.value(role - Qt::UserRole);
}

QHash<int, QByteArray> ConferenceModel::roleNames() const {
  return d_func()->roleNames;
}

void ConferenceModel::addConference(Conference *conference) {
  QSqlRecord newRecord = this->record();
  newRecord.setValue(UuidRole - Qt::UserRole, conference->uuid());
  newRecord.setValue(TypeRole - Qt::UserRole, conference->type());
  newRecord.setValue(HostIdRole - Qt::UserRole,
                     conference->host()->owner()->userId());
  newRecord.setValue(HostNameRole - Qt::UserRole,
                     conference->host()->owner()->userName());
  newRecord.setValue(HostGroupRole - Qt::UserRole,
                     conference->host()->owner()->userGroup());
  newRecord.setValue(HostDeviceRole - Qt::UserRole, conference->host()->uuid());
  newRecord.setValue(TitleRole - Qt::UserRole, conference->title());
  newRecord.setValue(ContentRole - Qt::UserRole, conference->content());
  newRecord.setValue(MembersRole - Qt::UserRole, conference->member());
  newRecord.setValue(GpsRole - Qt::UserRole, conference->gps());
  newRecord.setValue(CreateTimeRole - Qt::UserRole,
                     conference->createTime().toString(Qt::ISODate));
  newRecord.setValue(UpdateTimeRole - Qt::UserRole,
                     conference->updateTime().toString(Qt::ISODate));
  newRecord.setValue(StatusRole - Qt::UserRole,
                     static_cast<int>(conference->status()));

  if (!this->insertRecord(-1, newRecord)) qDebug() << "insert record failed.";
}

ConferenceModel::ConferenceModel(ConferenceModelPrivate *d,
                                 QSqlTableModel *parent)
    : QSqlTableModel(parent), d_ptr(d) {}
