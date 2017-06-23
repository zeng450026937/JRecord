TEMPLATE = subdirs

SUBDIRS += \
    RecordService \
    JRecord \
    EchoServer

JRecord.depends = RecordService
