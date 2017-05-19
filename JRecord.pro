TEMPLATE = subdirs

SUBDIRS += \
    JRecord \
    RecordService/recordservice.pro

JRecord.depends = recordservice

