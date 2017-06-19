#include "record.h"
#include "record_p.h"

Record::Record(QObject *parent)
    : QObject(parent), d_ptr(new RecordPrivate(this)) {}

QString Record::uuid() const { return d_func()->uuid; }

QString Record::conference() const { return d_func()->conference; }

QString Record::device() const { return d_func()->device; }

QString Record::directory() const { return d_func()->directory; }

QString Record::name() const { return d_func()->name; }

bool Record::active() const { return d_func()->active; }

qint32 Record::total() const { return d_func()->total; }

qint32 Record::size() const { return d_func()->size; }

qint32 Record::progress() const { return d_func()->progress; }

Record::Status Record::status() const { return d_func()->status; }

QString Record::error() const { return d_func()->error; }

bool Record::eof() const
{
    return d_func()->eof;
}

void Record::setUuid(const QString &uuid) {
  Q_D(Record);
  if (d->uuid != uuid) {
    d->uuid = uuid;
    Q_EMIT uuidChanged(d->uuid);
  }
}

void Record::setConference(const QString &conference) {
  Q_D(Record);
  if (d->conference != conference) {
    d->conference = conference;
    Q_EMIT conferenceChanged(d->conference);
  }
}

void Record::setDevice(const QString &device) {
  Q_D(Record);
  if (d->device != device) {
    d->device = device;
    Q_EMIT deviceChanged(d->device);
  }
}

void Record::setDirectory(const QString &directory) {
  Q_D(Record);
  if (d->directory != directory) {
    d->directory = directory;
    Q_EMIT directoryChanged(d->directory);
  }
}

void Record::setName(const QString &name) {
  Q_D(Record);
  if (d->name != name) {
    d->name = name;
    Q_EMIT nameChanged(d->name);
  }
}

void Record::setActive(bool active) {
  Q_D(Record);
  if (d->active != active) {
    d->active = active;
    Q_EMIT activeChanged(d->active);
  }
}

void Record::setEof(bool eof)
{
    Q_D(Record);
    if (d->eof != eof) {
      d->eof = eof;
      Q_EMIT eofChanged(d->eof);
    }
}

void Record::binaryReceived(const QByteArray &binary) { Q_UNUSED(binary); }

Record::Record(RecordPrivate *d, QObject *parent) : QObject(parent), d_ptr(d) {}
