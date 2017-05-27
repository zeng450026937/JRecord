TEMPLATE = subdirs

SUBDIRS += \
    JRecord \
    RecordService/recordservice.pro \
    EchoServer

JRecord.depends = recordservice

