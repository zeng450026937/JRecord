#ifndef RECORD_P_H
#define RECORD_P_H

#include <QFile>
#include "record/record.h"

class Record;

class RecordPrivate {
  Q_DISABLE_COPY(RecordPrivate)
  Q_DECLARE_PUBLIC(Record)
 public:
  RecordPrivate(Record* q);

  Record* q_ptr;
  QFile file;
  QString uuid;
  QString conference;
  QString device;
  QString directory;
  QString name;
  bool active;
  bool eof;
  qint32 total;
  qint32 size;
  qint32 progress;
  Record::Status status;
  QString error;
};

#endif  // RECORD_P_H
