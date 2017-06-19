TEMPLATE = subdirs

SUBDIRS += \
    RecordService/recordservice.pro \
    JRecord \
    EchoServer

JRecord.depends = RecordService/recordservice.pro
