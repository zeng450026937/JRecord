#ifndef RECORD_H
#define RECORD_H

#include <QObject>

class RecordPrivate;

class Record : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(Record)
  Q_DECLARE_PRIVATE(Record)

  Q_PROPERTY(QString uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
  Q_PROPERTY(QString conference READ conference WRITE setConference NOTIFY
                 conferenceChanged)
  Q_PROPERTY(QString device READ device WRITE setDevice NOTIFY deviceChanged)

  Q_PROPERTY(QString directory READ directory WRITE setDirectory NOTIFY
                 directoryChanged)
  Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

  Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

  Q_PROPERTY(qint32 total READ total NOTIFY totalChanged)
  Q_PROPERTY(qint32 size READ size NOTIFY sizeChanged)
  Q_PROPERTY(qint32 progress READ progress NOTIFY progressChanged)
  Q_PROPERTY(Status status READ status NOTIFY statusChanged)
  Q_PROPERTY(bool eof READ eof WRITE setEof NOTIFY eofChanged)
  Q_PROPERTY(QString error READ error NOTIFY errorChanged)

 public:
  explicit Record(QObject *parent = 0);

  enum Status { Downloading, Paused, Completed, Error };
  Q_ENUM(Status)

  QString uuid() const;
  QString conference() const;
  QString device() const;
  QString directory() const;
  QString name() const;
  bool active() const;
  qint32 total() const;
  qint32 size() const;
  qint32 progress() const;
  Status status() const;
  QString error() const;
  bool eof() const;

 public Q_SLOTS:
  void setUuid(const QString &uuid);
  void setConference(const QString &conference);
  void setDevice(const QString &device);
  void setDirectory(const QString &directory);
  void setName(const QString &name);
  void setActive(bool active);
  void setEof(bool eof);

 Q_SIGNALS:
  void uuidChanged(const QString &uuid);
  void conferenceChanged(const QString &conference);
  void deviceChanged(const QString &device);
  void directoryChanged(const QString &directory);
  void nameChanged(const QString &path);
  void activeChanged(bool active);
  void totalChanged(qint32 total);
  void sizeChanged(qint32 size);
  void progressChanged(qint32 progress);
  void statusChanged(Status status);
  void errorChanged(const QString &error);
  void eofChanged(bool eof);

 protected:
  void binaryReceived(const QByteArray &binary);

 protected:
  Record(RecordPrivate *d, QObject *parent = 0);
  QScopedPointer<RecordPrivate> d_ptr;
  friend class RecordManager;
};

#endif  // RECORD_H
